#include<bits/stdc++.h>
using namespace std;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
typedef long long ll;
const int N=4e5+5;
int n,m;
map<pair<ll,ll>,int> mp;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int getid(int a,int b,int c,int d){
	ll p=1ll*a*d,q=1ll*b*c,g=gcd(p,q);
	p/=g,q/=g;
	int &v=mp[make_pair(p,q)];
	if(!v)v=++m;
	return v;
}
int lst[N],to[N],nxt[N],ec=1;
inline void ae(int x,int y){
	to[++ec]=y,nxt[ec]=lst[x],lst[x]=ec;
}
int vis[N];
int mark[N];
int M;
vector<pair<int,int> > ans;
void dfs(int x,int pre){
	vis[x]=1;
	for(int i=lst[x];i;i=nxt[i]){
		M++;
		int y=to[i];
		if(!vis[y])dfs(y,i>>1);
	}
	int now=0;
	for(int i=lst[x];i;i=nxt[i]){
		if(i>>1==pre||mark[i>>1])continue;
		if(!now)now=i>>1;
		else{
			mark[i>>1]=1,mark[now]=1;
			ans.push_back(make_pair(i>>1,now));
			now=0;
		}
	}
	if(now&&pre){
		mark[pre]=mark[now]=1;
		ans.push_back(make_pair(pre,now));
	}
}
int main(){
	n=in();
	for(int i=1;i<=n;i++){
		int a=in(),b=in(),c=in(),d=in();
		int x=getid(a+b,b,c,d);
		int y=getid(a,b,c+d,d);
		ae(x,y),ae(y,x);
	}
	for(int i=1;i<=m;i++)if(!vis[i]){
		dfs(i,0);
	}
	printf("%d\n",(int)ans.size());
	for(pair<int,int> p:ans)printf("%d %d\n",p.first,p.second);
	return 0;
}