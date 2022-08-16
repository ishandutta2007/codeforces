#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=998244353;
int n,m;
int sg[100005],vis[100005],du[100005],q[100005];
ll c[520][520];
vector<int> adj[100005];

ll mod(ll x){return x>=cys?x-cys:x;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

void gauss(){
	for(int i=0;i<512;i++){
		int pl=i;
		for(int j=i;j<512;j++) if(c[j][i]) pl=j;
		for(int j=i;j<=512;j++) swap(c[i][j],c[pl][j]);
		for(int j=0;j<512;j++){
			if(i==j) continue;
			ll tmp=qpow(c[i][i],cys-2)*c[j][i]%cys;
			for(int k=i;k<=512;k++) c[j][k]=mod(c[j][k]+cys-tmp*c[i][k]%cys);
		}
	}
}

int main(){
	n=readint(); m=readint();
	int x,y;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint();
		adj[x].pb(y); du[y]++;
	}
	int front=1,rear=1;
	for(int i=1;i<=n;i++) if(!du[i]) q[rear++]=i;
	while(front<rear){
		int t=q[front++];
		for(auto v:adj[t]) if(!(--du[v])) q[rear++]=v;
	}
	for(int i=n;i>=1;i--){
		for(int j=0;j<=adj[q[i]].size();j++) vis[j]=0;
		for(auto v:adj[q[i]]) vis[sg[v]]=1;
		for(int j=0;j<=adj[q[i]].size();j++){
			if(!vis[j]){
				sg[q[i]]=j;
				break;
			}
		}
	}
	ll invn=qpow(n+1,cys-2);
	for(int i=0;i<512;i++){
		c[i][i]=cys-1;
		for(int j=1;j<=n;j++) c[i][i^sg[j]]=mod(c[i][i^sg[j]]+invn);
		if(i) c[i][512]=invn;
	}
	gauss();
	printf("%lld\n",mod(cys-c[0][512])*qpow(c[0][0],cys-2)%cys);
	return 0;
}