#include<bits/stdc++.h>

int T;

int n;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		std::set<std::pair<int,int>> s,t;
		std::map<std::pair<int,int>,int> mp;
		for(int i=1;i<=n;i++){
			int l,r,c;
			scanf("%d%d%d",&l,&r,&c);
			s.emplace(l,c),t.emplace(-r,c);
			if(mp.count({l,r}))
				mp[{l,r}]=std::min(mp[{l,r}],c);
			else
				mp[{l,r}]=c;
			auto [L,x]=*s.begin();
			auto [R,y]=*t.begin();
			R=-R;
			int ans=x+y;
			if(mp.count({L,R}))
				ans=std::min(ans,mp[{L,R}]);
			printf("%d\n",ans);
		}
	}
}