// Just a direct implementation of the editorial. Nothing to see here.

#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif
#include<cassert>
#include<iostream>

#include<vector>
#include<unordered_map>
#include<climits>
#include<array>
#include<algorithm>

template<class T,T base,auto f> // T f(T,T)
struct IT2D{
	std::vector<std::vector<std::pair<int,T> /* {y, value} */ >> d;
	std::vector<std::vector<T>> st;
	std::vector<std::vector<int>> ind;

	int ymax;

	IT2D(int xmax,int ymax):d(2*xmax),ymax(ymax){}

	void setmore(int x,int y,T val){
		// [x,y] = f([x,y], val)
		x+=int(d.size()/2);
		y+=ymax;

		d[x].push_back({y,val});
	}

	void build(){
		for(auto x=d.size();x-->d.size()/2;){
			auto& dx=d[x];
			if(!dx.empty()){
				std::sort(begin(dx),end(dx),[](auto a,auto b){return a.first<b.first;});
				auto out=begin(dx);
				for(auto iter=++begin(dx);iter!=end(dx);++iter){
					auto z=*iter;
					if(z.first==out->first)
						out->second=f(out->second,z.second);
					else
						*++out=z;
				}
				dx.erase(++out,end(dx));
			}
		}

		auto const merge=[](std::vector<std::pair<int,T>> a,std::vector<std::pair<int,T>> b){
			std::vector<std::pair<int,T>> ans;ans.reserve(a.size()+b.size());
			auto i1=begin(a),i2=begin(b);
			while(true){
				if(i1!=end(a)&&i2!=end(b)&&i1->first==i2->first){
					ans.push_back({i1->first,f(i1->second,i2->second)});
					++i1;++i2;
				}else if(i1!=end(a)&&(i2==end(b) || i1->first<i2->first))
					ans.push_back(*i1++);
				else if(i2!=end(b))
					ans.push_back(*i2++);
				else break;
			}
			return ans;
		};

		for(auto x=d.size()/2;--x;){
			d[x]=merge(d[x<<1],d[x<<1|1]);
		}

		st.resize(d.size());
		ind.resize(d.size());

		for(auto x=d.size();x--;){
			auto& dx=d[x];
			if(!dx.empty()){
				ind[x].resize(dx.size());
				auto& stx=st[x];
				stx.resize(dx.size()*2);
				std::transform(begin(dx),end(dx),begin(ind[x]),[](auto z){return z.first;});
				std::transform(begin(dx),end(dx),begin(stx)+dx.size(),[](auto z){return z.second;});
				for(auto y=stx.size()/2;--y;){
					stx[y]=f(stx[y<<1],stx[y<<1|1]);
				}
			}
		}
	}

	T get(int xl,int xr,int yl,int yr)const{
		assert(0<=xl&&xl<=xr&&xr<=int(d.size()/2));
		assert(0<=yl&&yl<=yr&&yr<=ymax);
		xl+=int(d.size()/2);
		xr+=int(d.size()/2);
		yl+=ymax;
		yr+=ymax;

		T ans=base;

		auto const process=[&](int x){
			for(auto
					yl_=std::lower_bound(begin(ind[x]),end(ind[x]),yl)-begin(ind[x])+ind[x].size(),
					yr_=std::lower_bound(begin(ind[x]),end(ind[x]),yr)-begin(ind[x])+ind[x].size();
					yl_<yr_;yl_>>=1,yr_>>=1){
				if(yl_&1) ans=f(ans,st[x][yl_++]);
				if(yr_&1) ans=f(ans,st[x][--yr_]);
			}
		};

		for(;xl<xr;xl>>=1,xr>>=1){
			if(xl&1) process(xl++);
			if(xr&1) process(--xr);
		}

		return ans;
	}
};

auto constexpr min=(int const&(*)(int const&,int const&)) std::min;
auto constexpr max=(int const&(*)(int const&,int const&)) std::max;

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int xm,ym,zm, nopen,nClose,nQuery;
	std::cin>>xm>>ym>>zm>> nopen>>nClose>>nQuery;

	std::array<int,3> minOpen;std::fill(begin(minOpen),end(minOpen),INT_MAX);
	std::array<int,3> maxOpen;std::fill(begin(maxOpen),end(maxOpen),INT_MIN);


	for(int _=nopen;_--;){
		std::array<int,3> t;
		for(int& x:t){std::cin>>x;--x; }
		std::transform(begin(minOpen),end(minOpen),begin(t),begin(minOpen),min);
		std::transform(begin(maxOpen),end(maxOpen),begin(t),begin(maxOpen),max);
	}

	IT2D<int,INT_MAX,min> min_ge_min_open(xm,ym);
	IT2D<int,INT_MIN,max> max_le_max_open(xm,ym);

	for(int _=nClose;_--;){
		std::array<int,3> t;
		int n_inrange=0;
		for(int i=0;i<3;++i){
			int& x=t[i];
			std::cin>>x;--x;
			n_inrange+=minOpen[i]<=x&&x<=maxOpen[i];
		}
		if(n_inrange==3){
			std::cout<<"INCORRECT\n";
			return 0;
		}

		if(t[2]>=minOpen[2])
			min_ge_min_open.setmore(t[0],t[1],t[2]);
		if(t[2]<=maxOpen[2])
			max_le_max_open.setmore(t[0],t[1],t[2]);
	}

	min_ge_min_open.build();
	max_le_max_open.build();

	std::cout<<"CORRECT\n";
	for(int _=nQuery;_--;){
		std::array<int,3> t;
		int n_inrange=0;
		for(int i=0;i<3;++i){
			int& x=t[i];
			std::cin>>x;--x;
			n_inrange+=minOpen[i]<=x&&x<=maxOpen[i];
		}
		if(n_inrange==3){
			std::cout<<"OPEN\n";continue;
		}

		int minZ=std::min(minOpen[2],t[2]);
		int maxZ=std::max(maxOpen[2],t[2]);

		auto test=[&](auto const& segtree){
			int z=segtree.get(
				std::min(minOpen[0],t[0]),std::max(maxOpen[0],t[0])+1,
				std::min(minOpen[1],t[1]),std::max(maxOpen[1],t[1])+1
				);
			return minZ<=z&&z<=maxZ;
		};
		if(test(min_ge_min_open)||test(max_le_max_open))
			std::cout<<"CLOSED\n";
		else
			std::cout<<"UNKNOWN\n";
	}
}