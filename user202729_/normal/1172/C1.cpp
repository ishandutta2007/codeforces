// [I didn't read the editorial or see any failed test cases]
// [Asymptotically faster than the previous solution, but still not fast enough to pass C2]
#ifndef LOCAL
#define NDEBUG
#endif
#include<numeric>
#include<vector>
#include<cassert>
#include<iostream>

int const MOD=998244353;
int invmod(int a){
	int b=MOD;
	assert(0<=a);
	assert(a<MOD);
	int ax=1,bx=0;
	while(b){
		int q=a/b;
		a-=b*q;
		ax-=bx*q;
		std::swap(a,b);
		std::swap(ax,bx);
	}
	assert(a==1);
	if(ax<0)ax+=MOD;
	assert(ax>=0);
	return ax;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int npic,nvisit;std::cin>>npic>>nvisit;
	std::vector<char> like_pic(npic);
	for(char& l:like_pic){
		std::cin>>l;
		l=char(l-'0');
	}
	std::vector<int> wt(npic);for(int& w:wt)std::cin>>w;
	int const sumallw=std::accumulate(begin(wt),end(wt),0);

	for(int i=0;i<npic;++i){
		int sumlk=0,sumn=0;
		for(int j=0;j<npic;++j)if(j!=i)
			(like_pic[j] ? sumlk : sumn)+=wt[j];

		int out=0;

		if(like_pic[i]){
			std::vector<int> g(nvisit+1),gnext(nvisit+1); // [b] = sum of dp(next)[b][c] int previous solution
			g[0]=wt[i];

			for(int iter=0;iter<nvisit;++iter){
				for(int b=0;b<=nvisit;++b)if(g[b]){
					int64_t const invsum=invmod(sumallw+iter-2*b);
					assert(invsum>0);

					int64_t const tmp=g[b]*invsum%MOD;

					gnext[b]  =int( (gnext[b]  +(sumlk +iter-b  + wt[i] +1)*tmp  )%MOD );
					gnext[b+1]=int( (gnext[b+1]+(sumn  -b  )*tmp)%MOD );
				}

				std::swap(g,gnext);
				gnext.assign(gnext.size(),0);
			}

			out=int(std::accumulate(begin(g),end(g),0LL)%MOD);
		}else{
			std::vector<int> g(nvisit+1),gnext(nvisit+1); // [a] = sum of dp(next)[a][b] (if a is used int the state)
			g[0]=wt[i];

			for(int iter=0;iter<nvisit;++iter){
				for(int a=0;a<=nvisit;++a)if(g[a]){
					int64_t const invsum=invmod(sumallw+2*a-iter);
					assert(invsum>0);

					int64_t const tmp=g[a]*invsum%MOD;

					gnext[a+1]=int( (gnext[a+1]+(sumlk +a  )*tmp)%MOD );
					gnext[a]=int( (gnext[a]+(wt[i] -iter+a-1+sumn    )*tmp)%MOD );
				}

				std::swap(g,gnext);
				gnext.assign(gnext.size(),0);
			}
			out=int(std::accumulate(begin(g),end(g),0LL)%MOD);
		}


		std::cout<<out<<'\n';
	}
}