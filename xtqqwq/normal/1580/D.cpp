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

int n,m,rt;
ll a[4005],rmq[4005][20],ch[4005][2],lg2[4005],siz[4005];
ll d[4005][4005];

int getmin(int l,int r){
	int k=lg2[r-l+1];
	return a[rmq[l][k]]<a[rmq[r-(1<<k)+1][k]]?rmq[l][k]:rmq[r-(1<<k)+1][k];
}

int build(int l,int r){
	int mid=getmin(l,r);
	if(l!=mid) ch[mid][0]=build(l,mid-1);
	if(r!=mid) ch[mid][1]=build(mid+1,r);
	return mid;
}

void dfs(int u){
	if(!u) return;
	siz[u]=1;
	dfs(ch[u][0]),dfs(ch[u][1]);
	siz[u]+=siz[ch[u][0]]+siz[ch[u][1]];
	for(int i=0;i<=siz[ch[u][0]];i++){
		for(int j=0;j<=siz[ch[u][1]];j++){
			chkmax(d[u][i+j],d[ch[u][0]][i]+d[ch[u][1]][j]-2ll*i*j*a[u]);
			chkmax(d[u][i+j+1],d[ch[u][0]][i]+d[ch[u][1]][j]-2ll*i*j*a[u]
				+1ll*(m-1)*a[u]-2ll*(i+j)*a[u]);
		}
	}
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=2;i<=n;i++) lg2[i]=lg2[i>>1]+1;
	for(int i=1;i<=n;i++) rmq[i][0]=i;
	for(int i=1;(1<<i)<=n;i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
			rmq[j][i]=a[rmq[j][i-1]]<a[rmq[j+(1<<(i-1))][i-1]]?rmq[j][i-1]:rmq[j+(1<<(i-1))][i-1];
	rt=build(1,n);
	for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) d[i][j]=-(1ll<<60);
	d[0][0]=0;
	dfs(rt);
	printf("%lld\n",d[rt][m]);
	return 0;
}