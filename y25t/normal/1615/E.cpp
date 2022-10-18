#include<bits/stdc++.h>
#define ll long long
#define N 200005

int n,m;

std::vector<int> E[N];

std::priority_queue<int> s[N];
inline void dfs(int u,int fa){
	if(u!=1&&(int)E[u].size()==1)
		s[u].push(0);
	for(auto v:E[u]) if(v!=fa){
		dfs(v,u);
		if(s[v].size()>s[u].size())
			std::swap(s[u],s[v]);
		while(s[v].size())
			s[u].push(s[v].top()),s[v].pop();
	}
	int x=s[u].top();
	s[u].pop();
	s[u].push(x+1);
}

ll ans;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		E[u].push_back(v),E[v].push_back(u);
	}
	dfs(1,0);
	if(m>=(int)s[1].size()){
		for(int i=(int)s[1].size();i<=m;i++)
			ans=std::max(ans,1ll*(n-i)*i);
	}
	else{
		int W=0,R=0;
		for(int i=1;i<=m;i++){
			int x=s[1].top();
			s[1].pop();
			W+=x-1,R++;
		}
		ans=1ll*(n-R)*R;
		for(int i=0;i<=n-W-R;i++)
			ans=std::min(ans,1ll*(n-R-i)*(R-i));
	}
	printf("%lld\n",ans);
}