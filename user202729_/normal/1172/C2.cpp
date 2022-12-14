// [I didn't read the editorial or see any failed test cases]
// The last submission got AC already. This is just some minor optimization.
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

	int sumlk_all=0,sumn_all=0;
	for(int j=0;j<npic;++j)
		(like_pic[j] ? sumlk_all : sumn_all)+=wt[j];

	int out_lk,out_not_lk=0;

	std::vector<int> invmod_prep_v(nvisit*2-1);
	auto invmod_prep=begin(invmod_prep_v)+nvisit-1;

	for(int i=-(nvisit-1);i<nvisit;++i)
		if(sumallw+i>0)
			invmod_prep[i]=invmod(sumallw+i);

	std::vector<int> g(nvisit+1);
	g[0]=1;

	for(int iter=0;iter<nvisit;++iter){
		for(int b=iter+1;b--;)if(g[b]){
			int64_t const invsum=invmod_prep[iter-2*b];
			assert(invsum>0);

			int64_t const tmp=g[b]*invsum%MOD;

			g[b+1]=int( (g[b+1]+(sumn_all  -b  )*tmp)%MOD );
			g[b] = int((sumlk_all +iter-b  + 1)*tmp  %MOD);
		}
	}

	out_lk=int(std::accumulate(begin(g),end(g),0LL)%MOD);


	if(sumn_all>0){
		g.assign(g.size(),0);
		g[0]=1;

		for(int iter=0;iter<nvisit;++iter){
			for(int a=iter+1;a--;)if(g[a]){
				int64_t const invsum=invmod_prep[2*a-iter];
				assert(invsum>0);

				int64_t const tmp=g[a]*invsum%MOD;

				g[a+1]=int( (g[a+1]+(sumlk_all +a  )*tmp)%MOD );
				g[a]=int( (-iter+a-1+sumn_all    )*tmp%MOD );
			}

		}
		out_not_lk=int(std::accumulate(begin(g),end(g),0LL)%MOD);
	}


	for(int i=0;i<npic;++i){
		std::cout<<(like_pic[i] ? out_lk : out_not_lk)*(int64_t)wt[i]%MOD<<'\n';
	}
}