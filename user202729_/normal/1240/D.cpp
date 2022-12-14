// I think I have done this problem before...
#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif
#include<cassert>
#include<unordered_map>
#include<iostream>
#include<vector>
#include<algorithm>

std::vector<int> a;
int64_t ans;

void process(int l,int r){
	if(r-l<=1)return;
	if(r-l==2){ans+=a[l]==a[l+1];return;}
	if(r-l==3){ans+=a[l]==a[l+1];ans+=a[l+1]==a[l+2];return;}

	int m=(l+r)>>1;
	{
		struct node{
			std::unordered_map<int,int> c;
			int parnode,paredge,val;
		};
		std::vector<node> t(1); // trie
		t[0].paredge=-1;

		int node=0;
		for(int i=m;i<r;++i){
			if(t[node].paredge==a[i])
				node=t[node].parnode;
			else{
				auto [iter,success]=t[node].c.insert({a[i],(int)t.size()});
				if(success){
					t.emplace_back();
					t.back().parnode=node;
					t.back().paredge=a[i];
				}
				node=iter->second;
			}
			++t[node].val;
		}

		node=0;
		std::vector<int> pendedges;
		for(int i=m;i-->l;){
			if(pendedges.empty()){
				if(t[node].paredge==a[i]){
					node=t[node].parnode;
				}else{
					auto iter=t[node].c.find(a[i]);
					if(iter==t[node].c.end()){
						pendedges.push_back(a[i]);
					}else{
						node=iter->second;
					}
				}
			}else{
				if(pendedges.back()==a[i]){
					pendedges.pop_back();
				}else{
					pendedges.push_back(a[i]);
				}
			}

			if(pendedges.empty()){
				ans+=t[node].val;
			}
		}
	}

	process(l,m);
	process(m,r);
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int q;std::cin>>q;
	while(q--){
		int n;std::cin>>n;
		a.resize(n);for(int& x:a)std::cin>>x;
		ans=0;
		process(0,n);
		std::cout<<ans<<'\n';
	}
}