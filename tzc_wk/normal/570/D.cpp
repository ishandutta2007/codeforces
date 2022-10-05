#include <bits/stdc++.h>
using namespace std;
vector<int> g[500005];
int n,m,L[500005],R[500005],dep[500005],idx,id[500005];
vector<int> d[500005],_xor[500005];
inline void dfs(int x,int f){
	L[x]=++idx;
	id[idx]=x;
	d[dep[x]].push_back(L[x]);
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];
		if(y==f)	continue;
		dep[y]=dep[x]+1;
		dfs(y,x);
	}
	R[x]=idx;
}
char s[500005];
int main(){
	cin>>n>>m;
	for(int i=2;i<=n;i++){
		int x;scanf("%d",&x);
		g[x].push_back(i);
		g[i].push_back(x);
	}
	scanf("%s",s+1);
	dep[1]=1;
	dfs(1,0);
	for(int i=1;i<=n;i++)	_xor[i].resize(d[i].size());
	for(int i=1;i<=n;i++){
		for(int j=0;j<d[i].size();j++){
//			cout<<i<<" "<<j<<endl;
			int pre=(j==0)?(0):(_xor[i][j-1]);
			_xor[i][j]=pre^(1<<(s[id[d[i][j]]]-'a'));
		}
	}
	while(m--){
		int x,y;scanf("%d%d",&x,&y);
		int l=lower_bound(d[y].begin(),d[y].end(),L[x])-d[y].begin();
		int r=upper_bound(d[y].begin(),d[y].end(),R[x])-d[y].begin()-1;
//		cout<<l<<" "<<r<<endl;
		if(r<0)	puts("Yes");
		else if(l>r)	puts("Yes");
		else{
			int ans=(l==0)?(_xor[y][r]):(_xor[y][r]^_xor[y][l-1]);
//			cout<<ans<<endl;
			if(ans==0||(ans&(-ans))==ans)	puts("Yes");
			else							puts("No");
		}
	}
}