#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define dep(i,a,b) for (int i=a;i>=b;--i)
#define re(i,a,b) for (int i=a;i<b;++i)
#define mp make_pair
#define pb push_back
#define fail {puts("No");return 0;}
#define X first
#define Y second
using namespace std;
template<class T> inline void read(T&x){char c;bool fu=0;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x*=-1;}
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z) {read(x,y);read(z);}
typedef long long ll;
typedef pair<int,int> pii;
const int N=1111111;
int f[N];
int vis[2][N],v[2][N];
int get(int x){return f[x]==x?x:f[x]=get(f[x]);}
vector<pii> ans;
vector<int> COM;
int n,m,x[N],y[N];
int s,t,ds,dt;
int main() {
	read(n,m);
	rep(i,1,m){
		read(x[i],y[i]);
		if(x[i]>y[i])swap(x[i],y[i]);
	}
	rep(i,1,n)f[i]=i;
	read(s,t);read(ds,dt);
	if(s>t)swap(s,t),swap(ds,dt);
	rep(i,1,m)if(x[i]!=s&&x[i]!=t&&y[i]!=s&&y[i]!=t){
		int p=get(x[i]),q=get(y[i]);
		if(p!=q)f[p]=q,ans.pb(mp(x[i],y[i]));
	}
	bool ok=0;int pp=0;
	rep(i,1,m)if(x[i]==s||x[i]==t||y[i]==s||y[i]==t){
		if(x[i]==s&&y[i]==t)ok=1;
		else {
			if(s==x[i]){int p=get(y[i]);vis[0][p]=y[i];}//if(!vis[0][p]&&!vis[1][p])++pp;}
			else if (s==y[i]){int p=get(x[i]);vis[0][p]=x[i];}//if(!vis[0][p]&&!vis[1][p])++pp;}
			else if (t==x[i]){int p=get(y[i]);vis[1][p]=y[i];}//if(!vis[0][p]&&!vis[1][p])++pp;}
			else if (t==y[i]){int p=get(x[i]);vis[1][p]=x[i];}//if(!vis[0][p]&&!vis[1][p])++pp;}
		}
	}
	int sz=0;
	rep(i,1,n)if(vis[0][i]&&vis[1][i])COM.pb(i),++sz,v[0][i]=vis[0][i],v[1][i]=vis[1][i],vis[0][i]=vis[1][i]=0;
	rep(i,1,n)if(vis[0][i])ds--,ans.pb(mp(vis[0][i],s));
	rep(i,1,n)if(vis[1][i])dt--,ans.pb(mp(vis[1][i],t));
	if(ds<0||dt<0)fail
	if(sz==0){
		if(!ok)fail
		else {
			--ds,--dt;
			ans.pb(mp(s,t));
			if(ds<0||dt<0)fail
		}
	}else {
		if(dt+ds<COM.size()+1)fail
		else {
			--ds,--dt;
			ans.pb(mp(s,v[0][COM[0]]));
			ans.pb(mp(t,v[1][COM[0]]));
			re(i,1,COM.size())if(ds){
				--ds;
				ans.pb(mp(s,v[0][COM[i]]));
			}else {
				--dt;
				ans.pb(mp(t,v[1][COM[i]]));
			}
		}
	}
	if(ds<0||dt<0)fail
	if(ans.size()!=n-1)fail
	puts("Yes");
	re(i,0,ans.size()){
		printf("%d %d\n",ans[i].X,ans[i].Y);
	}
	return 0;
}