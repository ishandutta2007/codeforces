// TODO debug more carefully

#define NDEBUG 1
#include<bits/stdc++.h>

#define MODULAR_LESS_EFFICIENT_BUT_EASIER_TO_CODE 1
int const MOD=998244353;
struct modular {
	int val;
	explicit constexpr operator int() const { return val; }
	constexpr modular():val(){}
#if MODULAR_LESS_EFFICIENT_BUT_EASIER_TO_CODE
	template<class T>
	constexpr modular(T v):val(int(v%MOD)){ if(val<0)val+=MOD; }
#else
	constexpr modular(int v):val(v){
		assert(0<=v and v<MOD);
	}
#endif

#define COMPAREOP(OP) bool constexpr operator OP(modular b) const { return val OP b.val; }
	COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>) COMPAREOP(<=) COMPAREOP(>=)
#undef COMPAREOP

	friend modular constexpr operator-(modular x) { x.val=x.val?MOD-x.val:0; return x; }
	modular constexpr& operator+=(modular m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
	modular constexpr& operator-=(modular m) { if ((val -= m.val) < 0) val += MOD; return *this; }
	modular constexpr& operator*=(modular m) {
		/*
		if(__builtin_constant_p(m.val)){
			switch(m.val){
				case 1: return *this;
				case 2: return *this+=*this;
				case 3: return *this+=*this+*this;
				case 0: return *this=0;
				case -1: return *this=-*this;
			}
		}else if(__builtin_constant_p(val)){
			*this=m**this;
		}
		*/
		val = int((int64_t)val*m.val%MOD);
		return *this;
	}
	modular constexpr pow(int p) const {
		modular a=*this;
		modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	modular constexpr inv() const {
		int a=val,b=MOD, ax=1,bx=0;
		while(b){
			int q=a/b, t=a%b;
			a=b; b=t;
			t=ax-bx*q; ax=bx; bx=t;
		}
		assert(a==1);
		if(ax<0)ax+=MOD;
		return ax;
	}
	modular constexpr& operator/=(modular m) { return (*this) *= m.inv(); }

#define ARITHBINARYOP(OP) friend modular constexpr operator OP(modular a, modular b) { return a OP##= b; }
	ARITHBINARYOP(+) ARITHBINARYOP(-) ARITHBINARYOP(*) ARITHBINARYOP(/)
#undef ARITHBINARYOP
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number, limit; std::cin>>number>>limit;
	std::vector<int> data(number);
	for(auto & x: data) {
		std::cin>>x;
		--x;
	}

	if(limit>=12){
		std::vector<std::vector<modular>> f(number+1);
		// [index][number of blocks] (no partial block)
		for(int index=0;index<(int)f.size();++index)
			f[index].resize(index/limit+1);

		std::vector<modular> power(number+1), inverse(number+1), step(number);
		std::generate(1+begin(power),end(power),[x=modular(0)]() mutable{return x=x*2+1;});
		std::transform(1+begin(power),end(power),1+begin(inverse),
				[&](auto x){return 1/x;});
		for(int index=1;index<(int)step.size();++index) step[index]=inverse[index]*power[index+1];

		f[0][0]=1;
		for(int index=0;index<number;++index)
			for(int blockCount=0;blockCount<=index/limit;++blockCount){
				auto const cur=f[index][blockCount];
				if(cur!=0){
					std::vector<int> count(limit, 0);
					int countZero=limit;
					modular value_times_cur=0;
					for(int next=index+1;next<=number;++next){
						auto const old=count[data[next-1]]++;
						if(0==old){
							--countZero;
							if(0==countZero){
								value_times_cur=std::accumulate(begin(count),end(count), cur,
										[&](modular b, int a){return b*power[a];});
							}
						}else if(countZero==0){
							value_times_cur=value_times_cur*step[old];
						}

						assert(value_times_cur==std::accumulate(begin(count),end(count), cur,
								[&](modular b, int a){return b*power[a];}));

						if(value_times_cur!=0)
							f[next][blockCount+1]+=value_times_cur*inverse[old+1];
					}
				}
			}

		std::vector<modular> result(number+1);
		{
			int index=number;
			modular total=1; // total number of subsequences of [index...]
			modular complete=0; // number of subsequences of[index...] that has each value from 0...limit-1
			int countZero=limit;
			std::vector<modular> value(limit);
			while(true){
				assert(complete==std::accumulate(begin(value),end(value), modular(1),
						[&](modular b, modular a){return b*a;}));
				for(int blockCount=0;blockCount<(int)f[index].size();++blockCount)
					result[blockCount]+=f[index][blockCount]*(total-complete);

				if(index==0) break;
				total*=2;
				--index;

				auto const old=value[data[index]];
				value[data[index]]=value[data[index]]*2+1;
				if(old==0){
					if(0==--countZero)
						complete=std::accumulate(begin(value),end(value), modular(1),
							[&](modular b, modular a){return b*a;});
				}else if(countZero==0)
					complete*=value[data[index]]/old;
			}
		}

		result[0]-=1; // ignore the empty subsequence
		for(int blockCount=0;blockCount<=number;++blockCount) {
			std::cout<<(int)result[blockCount]<<' ';
		}
		std::cout<<'\n';
	}else{
		std::vector<std::vector<std::vector<modular>>> f(2,
				std::vector<std::vector<modular>>(number/limit+1,
					std::vector<modular>(1<<limit))); // [index%2][number of blocks][status of last block] = count
		f[0][0][0]=1;
		for(int index=0;index<number;++index) {
			for(int blockCount=0;blockCount<=index/limit;++blockCount) 
				f[(index+1)&1][blockCount].assign(
						f[(index+1)&1][blockCount].size(), 0);

			for(int blockCount=0;blockCount<=index/limit;++blockCount) 
				for(int mask=(1<<limit);mask--;){
					auto const cur=f[index&1][blockCount][mask];
					if(cur!=0){
						f[(index+1)&1][blockCount][mask]+=cur;
						auto const newMask=mask|(1<<data[index]);
						if(newMask==(1<<limit)-1)
							f[(index+1)&1][blockCount+1][0]+=cur;
						else
							f[(index+1)&1][blockCount][newMask]+=cur;
					}
				}
		}

		for(int blockCount=0;blockCount<=number;++blockCount) {
			std::cout<<(
					blockCount<(int)f[number&1].size() ?
					(int)std::accumulate(begin(f[number&1][blockCount]), end(f[number&1][blockCount]),
					blockCount!=0 ? modular(0) : modular(-1) // if blockCount==0 it's necessary to exclude the empty subsequence
					) :
					0)<<' ';
		}
		std::cout<<'\n';
	}
}