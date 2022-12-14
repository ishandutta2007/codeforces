//

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nblock,nstar;std::cin>>nblock>>nstar;

	std::vector<int> blockpos(nblock);
	for(int& x:blockpos)std::cin>>x;
	std::sort(begin(blockpos),end(blockpos));

	for(unsigned i=1;i<blockpos.size();++i) assert(blockpos[i-1]<blockpos[i]);

	std::vector<int> starpos(nstar);
	for(int& x:starpos)std::cin>>x;
	std::sort(begin(starpos),end(starpos));
	
#ifdef LOCAL
	{
		assert(std::cin);
		int z;
		assert(not (std::cin>>z));
	}
#endif

	//std::vector<int> nstarsfx(starpos.back()+1);
	//for(int x:starpos)++nstarsfx;
	//for(auto i=nstarsfx.size();--i;) nstarsfx[i-1]+=nstarsfx[i];

	std::vector<int> g(nblock);
	// [i] = max nstar covered by (0..i+1) (right exclusive) assumes monster [i] is fixed
	std::vector<int> f(nblock+1);
	// [i] = max nstar covered by (0..i) (right exclusive)

	std::vector<int> presplit(nblock);
	// presplit[i] = max j<=i s.t. j==0 or blockpos[j-1]+1!=blockpos[j] (i.e., pudding j is not stuck to pudding j-1)

	for(int i=1,lastsplit=presplit[0]=0;
			i<(int)presplit.size();++i){
		if(blockpos[i-1]+1!=blockpos[i]) lastsplit=i;
		presplit[i]=lastsplit;
	}
	
	for(int i=0;;++i){
		if(i==0){
			assert(f[i]==0);
		}else{
			f[i]=std::max(f[i],f[i-1]);

#ifdef LOCAL // assert that f[i] == max of val's
			bool ok=false;
			for(int prevfix=0;prevfix<i;++prevfix){
				auto val=g[prevfix]+int(
					std::upper_bound(begin(starpos),end(starpos),blockpos[prevfix]+i-prevfix-1)-
					std::upper_bound(begin(starpos),end(starpos),blockpos[prevfix])
					);
				assert(val<=f[i]);
				if(val==f[i]) ok=true;
			}
			assert(ok);
#endif
		}
		if(i==nblock) break;

		// compute g[i]
		auto iter=std::upper_bound(begin(starpos),end(starpos),blockpos[i]);
		if(iter==begin(starpos)){
			assert(starpos[0]>blockpos[i]);
			assert(g[i]==0);
		}else{
			assert(iter==end(starpos) or *iter>blockpos[i]); // by the definition of upper_bound
			--iter;

			assert(g[i]==0);
			g[i]=f[presplit[i]]; // no star covered by this block
			for(auto i2=iter;;){ // i2 = first star covered by the block contains pudding i
				assert(*i2<=blockpos[i]);

				auto tmp=i-(blockpos[i]-*i2); // first pudding index inthe current block
				if(tmp<0) break;

#ifdef LOCAL
				auto tmp2=tmp;
				while(tmp2>0 and blockpos[tmp2-1]+1==blockpos[tmp2]) --tmp2;
#endif

				tmp=presplit[tmp];
				assert(tmp==presplit[tmp]);
				// which means...
				assert(tmp==0 or blockpos[tmp-1]+1!=blockpos[tmp]);

#ifdef LOCAL
				assert(tmp2==tmp);
#endif

				assert(tmp<=i); // fully computed
				g[i]=std::max(g[i],f[tmp]+int(iter-i2+1));
				if(i2==begin(starpos)) break;
				--i2;
			}

#ifdef LOCAL // assert that g[i] == max of val's
			bool ok=false;
			for(int blockfirst=0;blockfirst<=i;++blockfirst)
			if(blockfirst==0 or blockpos[blockfirst-1]+1!=blockpos[blockfirst]){
				auto val=f[blockfirst]+int(
					std::upper_bound(begin(starpos),end(starpos),blockpos[i])-
					std::upper_bound(begin(starpos),end(starpos),blockpos[i]-(i-blockfirst+1))
					);
				assert(val<=g[i]);
				if(val==g[i]) ok=true;
			}
			assert(ok);
#endif

			// done computing g[i]
		}

		// use g[i] to update to later f[...]
		f[i+1]=std::max(f[i+1],g[i]);
		int n_new_star=0;
		for(auto i2=*iter<blockpos[i]?std::next(iter):iter;
				i2!=end(starpos);++i2
				){
			assert(*i2>=blockpos[i]);
			if(*i2>blockpos[i]) ++n_new_star;

			unsigned tmp=i+*i2-blockpos[i]; // last (inclusive) pudding index inthe current block
			if(tmp+1>=f.size()) break;

			assert((int)tmp+1>i); // not fully computed
			f[tmp+1]=std::max(f[tmp+1],g[i]+n_new_star);
			// which also updates f[tmp+2], f[tmp+3], ...
		}
	}

	std::cout<<f[nblock]<<'\n';
}