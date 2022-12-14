#include<iostream>
#include<string>
#include<vector>
#include<climits>
#include<algorithm>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int ntest;std::cin>>ntest;
	std::string s,a,b;
	while(ntest--){

		int nchar;
		std::cin>>nchar>>s>>a>>b;
		for(auto x:{&s,&a,&b}) for(char& c:*x) c-='a';
		std::vector<int> min_map(nchar,0),max_map(nchar,nchar-1);

		/// return empty if there is no match
		auto find_match=[&](){
			struct map_item{int x,min,max;};
			std::vector<map_item> items(nchar);
			for(int i=0;i<nchar;++i)
				items[i]={i,min_map[i],max_map[i]};
			std::sort(items.begin(),items.end(),[](map_item a,map_item b){
					return a.max<b.max;});
			std::vector<int> map(nchar);
			std::vector<char> mapped(nchar,false);
			for(auto item:items){
				for(int map_x=item.min;map_x<=item.max;++map_x)
					if(!mapped[map_x]){
						mapped[map_x]=true;
						map[item.x]=map_x;
						goto next_outer;
					}
				map.clear();
				return map;
next_outer:;
			}
			return map;
		};

		if(false){
not_possible:
			std::cout<<"NO\n";
			continue;

solvable:
			std::cout<<"YES\n";
			for(auto x:find_match())std::cout<<char(x+'a');
			std::cout<<'\n';
			continue;
		}

		// change min_map and max_map, and return whether there is a match after
		// the change
		auto restrict=[&](int x,int min1,int max1){
			if(min_map[x]>max1||max_map[x]<min1||min1>max1)
				return false;
			min_map[x]=std::max(min_map[x],min1);
			max_map[x]=std::min(max_map[x],max1);
			return !find_match().empty();
		};

		unsigned lcp=0; // of a and b
		while(lcp<a.size()&&a[lcp]==b[lcp]){
			int x=s[lcp];
			int x_map=a[lcp];
			if(!restrict(x,x_map,x_map))
				goto not_possible;
			++lcp;
		}

		// =========
		for(auto r:{&a,&b}){
			auto oldminmap=min_map,oldmaxmap=max_map;
			for(unsigned i=lcp;;){
				// assume min(lcp(mapped s,a),lcp(mapped s,b))==i
				// and the min is reached at *r (*r in {a,b})
				if(i==a.size())
					goto solvable;

				int x=s[i];
				int old_min=min_map[x],old_max=max_map[x];
				int new_min,new_max;
				if(i==lcp){
					new_min=a[i]+1;new_max=b[i]-1;
				}else{
					if(r==&a){
						new_min=a[i]+1;new_max=INT_MAX;
					}else{
						new_min=INT_MIN;new_max=b[i]-1;
					}
				}
				if(restrict(x,new_min,new_max))
					goto solvable;
				min_map[x]=old_min;max_map[x]=old_max;

				if(!restrict(x,(*r)[i],(*r)[i]))
					break;
				++i;
			}
			min_map=std::move(oldminmap);max_map=std::move(oldmaxmap);
		}

		goto not_possible;
	}
}