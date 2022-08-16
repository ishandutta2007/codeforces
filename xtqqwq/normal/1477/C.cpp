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

int n;
ll dis[5005][5005];
pll a[5005];
bool vis[5005];

ll sqr(ll x){return x*x;}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i].fi=readint(),a[i].se=readint();
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) dis[i][j]=dis[j][i]=sqr(a[i].fi-a[j].fi)+sqr(a[i].se-a[j].se);
	printf("%d ",1); vis[1]=1;
	int now=1;
	for(int i=2;i<=n;i++){
		ll maxa=0,opt=0;
		for(int j=1;j<=n;j++) if(!vis[j]&&chkmax(maxa,dis[now][j])) opt=j;
		printf("%d ",opt);
		vis[opt]=1;
		now=opt;
	}
	printf("\n");
	return 0;
}