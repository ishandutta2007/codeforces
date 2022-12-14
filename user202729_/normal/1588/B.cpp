// time-limit: 1000
// problem-url: https://codeforces.com/contest/1588/problem/B
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

void up();
int main(){
	std::ios::sync_with_stdio(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

int64_t C2(int x){
	assert(x>=1);
	return (x*int64_t(x-1))>>1;
}

int antiC2(int64_t x){
	assert(x>=0);
	return (int)std::round(std::sqrt(double(x)*2+1./4)+1./2);
}

int antiC2Check(int64_t x){
	auto result=antiC2(x);
	assert(C2(result)==x);
	return result;
}

void up(){
	int n; std::cin>>n;
	auto const ask=[&](int l, int r)->int64_t{
		assert(0<=l); assert(l<r); assert(r<=n);
		std::cout<<"? "<<l+1<<' '<<r<<std::endl;
		int64_t x; std::cin>>x;
		if(x==-1) std::exit(0); // hack
		return x;
	};

	int left=0, right=n;
	auto const fullValue=ask(0, n);

	int i, j, k; // answer, shifted a bit

	while(true){
		assert((right-left)>=4);
		int middle=(left+right+1)>>1;
		auto const value=ask(left, middle);
		if(value==fullValue){
			right=middle;
		}else if(value==0){
			left=middle-1;
		}else{
			auto const valueRight=ask(middle, right);
			auto const countLeft=antiC2(value), countRight=antiC2(valueRight);
			if(C2(countLeft)==value and ask(middle-countLeft, middle)==value){
				// j  middle
				if(C2(countRight)==valueRight and ask(middle, middle+countRight)==valueRight){
					j=middle;
					i=j-countLeft;
					k=j+countRight;
					break;
				}


				// j>middle
				i=middle-countLeft;

				j=middle+1;
				for(int step=1<<30; step; step>>=1)
					if(j+step<right and ask(middle, j+step)==C2(j+step-middle))
						j+=step;
				k=j+antiC2Check(valueRight-C2(j-middle));
				break;
			}else{
				assert(C2(countRight)==valueRight);
				// j<middle
				k=middle+countRight;

				j=middle-1;
				for(int step=1<<30; step; step>>=1)
					if(j-step>left and ask(j-step, middle)==C2(middle-(j-step)))
						j-=step;
				i=j-antiC2Check(value-C2(middle-j));
				break;
			}
		}
	}

	std::cout<<"! "
		<<i+1<<' '
		<<j+1<<' '
		<<k<<'\n';
}