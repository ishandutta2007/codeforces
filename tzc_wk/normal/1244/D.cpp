#include <bits/stdc++.h>
using namespace std;
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define int long long
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
int n,a[100005][4];
vector<int> g[100005];
int root;
vector<int> v;
inline void dfs(int x,int fa){
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];
		if(y==fa)	continue;
		dfs(y,x);
	}
	v.push_back(x);
//	cout<<x<<" "<<dp[x][1]<<" "<<dp[x][2]<<" "<<dp[x][3]<<endl;
}
int as[100005];
signed main(){
	cin>>n;
	for(int i=1;i<=3;i++)
		for(int j=1;j<=n;j++)
			cin>>a[j][i];
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)	if(g[i].size()>=3){
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n;i++)	if(g[i].size()==1)	root=i;
	dfs(root,0);
	int ans=1ll<<48,ansind1=0,ansind2=0;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			if(i==j)	continue;
			int sum=0;
			for(int k=0;k<v.size();k++){
				int x=v[k];
				int t;
				if(k%3==0)		t=i;
				else if(k%3==1)	t=j;
				else			t=6-i-j;
				sum+=a[x][t];
			}
			if(sum<ans)	ans=sum,ansind1=i,ansind2=j;
		}
	}
	cout<<ans<<endl;
	for(int k=0;k<v.size();k++){
		int t;
		if(k%3==0)		t=ansind1;
		else if(k%3==1)	t=ansind2;
		else			t=6-ansind1-ansind2;
		as[v[k]]=t;
	}
	for(int i=1;i<=n;i++)		cout<<as[i]<<" ";
	return 0;
}
/*
5
3 4 2 1 2
4 2 1 5 4
5 3 2 1 1
1 2
2 3
3 5
4 5

4
1 1 1 1
1 1 1 1
1 1 1 1
1 4
2 4
2 3
*/