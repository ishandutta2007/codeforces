#include<bits/stdc++.h>
#define N 200005

int T;

int n;

std::vector<int> E[N];

int deg[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			E[i].clear();
			deg[i]=0;
		}
		for(int i=1;i<=n;i++){
			int k;
			scanf("%d",&k);
			while(k--){
				int j;
				scanf("%d",&j);
				E[j].push_back(i);
				deg[i]++;
			}
		}
		std::vector<int> p;
		std::set<int> s;
		for(int i=1;i<=n;i++)
			if(!deg[i])
				s.insert(i);
		int u=0;
		while(s.size()){
			auto it=s.upper_bound(u);
			if(it==s.end())
				it=s.begin();
			u=*it;
			s.erase(it);
			p.push_back(u);
			for(auto v:E[u])
				if(!--deg[v])
					s.insert(v);
		}
		if(p.size()!=n)
			puts("-1");
		else{
			int ans=1;
			for(int i=1;i<n;i++)
				if(p[i]<p[i-1])
					ans++;
			printf("%d\n",ans);
		}
	}
}