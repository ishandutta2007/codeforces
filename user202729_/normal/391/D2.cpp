// Supercollider

#ifdef Sublime
#include <iostream>
#include <sstream>
#define cin cin__
namespace std{std::stringstream cin(R"(
1 2
4 0 9
1 1 8
1 2 7

)");}
#endif // Sublime


#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

struct tract{int x,y,len;};
std::istream& operator>>(std::istream& str,tract& a){
	return str>>a.x>>a.y>>a.len;
}

struct event{
	enum{
		OPEN,VERT,CLOSE
	}type;
	int x,y;
	bool operator<(event e){
		return x!=e.x?x<e.x:type<e.type;
	}
};

int main(){
	int nVert,nHorz;std::cin>>nVert>>nHorz;
	std::vector<tract> vertTracts(nVert),horzTracts(nHorz);
	for(tract& t:vertTracts)std::cin>>t;
	for(tract& t:horzTracts)std::cin>>t;
	// std::sort(vertTracts.begin(),vertTracts.end(),[](tract a,tract b){
	// 	return a.x<b.x;
	// }); // not 100% necessary

	int ans=0;
	std::vector<event>events;events.reserve(2*nHorz+nVert);
	for(int r=1<<27;r;r>>=1){
		ans+=r;

		// check possibility
		// build event list
		events.clear();
		for(int i=nVert;i-->0;)if(vertTracts[i].len>=2*ans)
			events.push_back({event::VERT,vertTracts[i].x,i});
		for(tract t:horzTracts)if(t.len>=2*ans){
			events.push_back({event::OPEN ,t.x+      ans,t.y});
			events.push_back({event::CLOSE,t.x+t.len-ans,t.y});
		}
		std::sort(events.begin(),events.end());

		std::set<int> yCoords;
		for(event e:events){
			switch(e.type){
			case event::VERT:{
				auto it=yCoords.lower_bound(vertTracts[e.y].y+ans);
				if(it!=yCoords.end()&&
					*it<=vertTracts[e.y].y+vertTracts[e.y].len-ans)
					goto possible;
				break;
			}
			case event::OPEN:
				yCoords.insert(e.y);
				break;
			case event::CLOSE:
				yCoords.erase(e.y);
				break;
			}
		}

		// if not possible
		ans-=r; 
		possible:;
	}
	std::cout<<ans<<'\n';
}