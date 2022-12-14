#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

using pt=std::tuple<int,int,int,int>; // x,y,z,index
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::vector<pt> ps(n);
	for(int i=0;i<n;++i){
		auto& [x,y,z,id]=ps[i];
		id=i+1;
		std::cin>>x>>y>>z;
	}

	std::sort(begin(ps),end(ps));
#define n _
	for(std::size_t i=1;i<ps.size();++i){
		auto& [x,y,z,id]=ps[i-1];
		auto& [x_,y_,z_,id_]=ps[i];
		if(x==x_&&y==y_&&id!=0){
			std::cout<<id<<' '<<id_<<'\n';
			id=id_=0;
		}
	}
	ps.erase(std::remove_if(begin(ps),end(ps),[](pt p){
		auto& [x,y,z,id]=p;
		return id==0;
		}),end(ps));

	// now there are no 2 points with same x and y coord
	for(std::size_t i=1;i<ps.size();++i){
		auto& [x,y,_,id]=ps[i-1];
		auto& [x_,y_,__,id_]=ps[i];
		if(x==x_&&id!=0){
			std::cout<<id<<' '<<id_<<'\n';
			id=id_=0;
		}
	}
	ps.erase(std::remove_if(begin(ps),end(ps),[](pt p){
		auto& [x,y,z,id]=p;
		return id==0;
		}),end(ps));

	// now there are no 2 points with same x and y coord
	for(std::size_t i=1;i<ps.size();i+=2){
		auto& [x,y,_,id]=ps[i-1];
		auto& [x_,y_,__,id_]=ps[i];
		std::cout<<id<<' '<<id_<<'\n';
	}
}