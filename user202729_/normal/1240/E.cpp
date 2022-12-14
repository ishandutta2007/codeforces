// I didn't read the editorial and didn't see the test details
// NOTE: Wrap debug code int NDEBUG (... how can I make such a basic mistake ...)
#define NDEBUG
#include<cassert>
#include<array>
#include<vector>
#include<algorithm>
#include<iostream>

struct node{
	int a,b; // a: max, b: second max
	node():a(-1),b(-1){}
	node(node l,node r){
		if(l.a<r.a)std::swap(l,r);
		a=l.a;
		b=std::max(r.a,l.b);
	}

	void add(int x){
		if(x>b){
			auto [b_,a_]=std::minmax(a,x);
			b=b_;a=a_;
		}
	}
};


int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);

	int n;std::cin>>n;
	std::vector<int> a(n);for(int& ai:a)std::cin>>ai;
	std::sort(begin(a),end(a));
	int const maxa=a.back();

	int const SMALL_THRES=700; // TODO
	std::array<std::vector<node>,SMALL_THRES> t;

	for(int y=2;y<SMALL_THRES;++y){
		auto& ty=t[y];ty.resize(y);
	}

#if 1
	int64_t cnt=0;
	for(int y=2;y<SMALL_THRES;++y){
		auto& ty=t[y];
		for(int ai:a){
			++cnt;
			ty[ai%y].add(ai);
		}
	}
	assert(std::cerr<<"cnt="<<cnt<<'\n');
#else
	for(unsigned last=0,i=1;i<=a.size();++i){
		if(i==a.size()||a[i]!=a[i-1]){
			int ai=a[last];
			int mult=i-last;
			int y=SMALL_THRES-1,q=ai/y;

			while(true){ // complexity: sqrt(ai)
				int miny=ai/(q+1)+1;
				assert(ai/y==q && ai/miny==q);
				if(miny==y&&y!=SMALL_THRES-1 /* not first iteration */){
					//  the same situation will happen for all y <= current y
					for(int y1=2;y1<=y;++y1) {
						for(int times=std::min(mult,2);times--;)
							t[y1][ai%y1].add(ai);
					}
					break;
				}

				for(int y1=miny;y1<=y;++y1) {
					for(int times=std::min(mult,2);times--;)
						t[y1][ai-q*y1].add(ai);
				}

				y=miny-1;
				assert(ai/y>q);
				if(y<=1)
					break;

				// q=ai/y;
				while((q+1)*y<=ai) ++q; //  maximum value of q is ~= sqrt(n) before the check above happens
			}

			last=i;
		}
	}
#endif

	for(int y=2;y<SMALL_THRES;++y){
		auto& ty=t[y];
		for(int mod=y-1;mod--;) // suffix sum
			ty[mod]=node(ty[mod],ty[mod+1]);
	}





	std::vector<int64_t> nseg(maxa+1); // nseg[y] = sum(ai/y for ai in a) for y>=2
	// right now adding x to [i] will affect all y <= i

	std::vector<int> countge(maxa+1);
	for(int ai:a)++countge[ai];
	for(int min=maxa;min--;)
		countge[min]+=countge[min+1];

#if 0
	for(unsigned last=0,i=1;i<=a.size();++i){
		if(i==a.size()||a[i]!=a[i-1]){
			int ai=a[last];
			int mult=i-last;
			int q=1,y=ai;
			int64_t cnt=0;
			while(true){ // complexity: sqrt(ai)
				++cnt;
				int miny=ai/(q+1)+1;
				assert(ai/y==q && ai/miny==q);
				if(miny==y){
					//  the same situation will happen for all y <= current y
					cnt+=y;
					for(int y1=2;y1<=y;++y1) { nseg[y1]+=ai/y1*(int64_t)mult; nseg[y1-1]-=ai/y1*(int64_t)mult; }
					break;
				}
				nseg[y]+=q*mult;
				nseg[miny-1]-=q*mult;
				y=miny-1;
				if(y<=1)
					break;

				// q=ai/y;
				while((q+1)*y<=ai) ++q; //  maximum value of q is ~= sqrt(n) before the check above happens
			}
			//assert(std::cerr<<ai<<' '<<cnt<<'\n');
			assert(cnt<=20 || cnt*cnt<=8*ai);

			last=i;
		}
	}

	for(auto i=nseg.size();--i;)
		nseg[i-1]+=nseg[i];
#else

	for(auto y=nseg.size();y-->2;){
		auto& ans=nseg[y];
		for(int z=y;z<countge.size();z+=y)
			ans+=countge[z];
	}
#endif

	for(int min=maxa+1;min--;)
		assert( countge[min] == end(a)-std::lower_bound(begin(a),end(a),min) );

	auto const countf=[&](int min,int y,int minmod){
		// return min(2, number of ai values >= min, % y >= minmod)
		assert(minmod<y);
		if(minmod==0)
			return std::min(2,(int)countge[min]);

		if(y<SMALL_THRES){
			assert(y>=2);
			return (t[y][minmod].a>=min) + (t[y][minmod].b>=min);
		}else{
			int cnt=0;
			for(int q=(maxa-1)/y+1;q>=0;--q){
				int minv=std::max(min,minmod+q*y);
				int endv=(q+1)*y;
				if(minv>=endv)
					break;
				if(minv<(int)countge.size())
					cnt+=countge[minv];
				if(endv<(int)countge.size())
					cnt-=countge[endv];
				if(cnt>=2)
					break;
			}
			return std::min(2,cnt);
		}
	};


	auto const check=[&](int x,int y){
		assert(x<=maxa&&y<=maxa);
		assert(x>=2&&y>=2);

		int nsy=nseg[y];

		// case 1: take 2*x from one segment
		if(2*x<(int)countge.size()&&countge[2*x]>=1){
			int nswhole=2*x/y,rem=2*x%y;
			if(nsy-nswhole>=x+1)
				return true;
			if(nsy-nswhole>=x && nsy-nswhole>=x + std::max(0,1-countf(2*x,y,2*x%y)))
				return true;
		}

		// case 2: take x from 2 segments
		if(countge[x]>=2){
			int nswhole=x/y*2,rem=x%y;
			if(nsy-nswhole>=x+2)
				return true;
			if(nsy-nswhole>=x && nsy-nswhole>=x + std::max(0,2-countf(x,y,x%y)))
				return true;
		}

		return false;
	};

	int64_t ans=4;
	int x=2,y=maxa;
	while(true){
		if(check(x,y)){
			ans=std::max(ans,(int64_t)x*y);
			++x;
			if(x>maxa)break;
		}else{
			--y;
			if(y<=1 || y*(int64_t)maxa<=ans)break;
		}
	}
	std::cout<<ans<<'\n';
}