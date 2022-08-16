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

const int cys=1000000007;
int n,m,q;
int c[105],b[105],s[105],s1[105],s2[105],d[10005],f[10005],g[10005],ans[1005];

ll mod(ll x){return x>=cys?x-cys:x;}

int main(){
	n=readint();
	int sum=0;
	for(int i=1;i<=n;i++) c[i]=readint(),sum+=c[i];
	for(int i=1;i<n;i++) b[i]=readint();
	for(int i=1;i<=n;i++) s[i]=s[i-1]+c[i];
	for(int i=2;i<=n;i++){
		s1[i]=s1[i-1]+b[i-1];
		s2[i]=s2[i-1]+s1[i];
	}
	int mina=1<<30,maxa=1<<30;
	for(int i=1;i<=n;i++){
		chkmin(mina,-s2[i]/i-2);
		chkmin(maxa,(s[i]-s2[i])/i+2);
	}
	for(int x=mina;x<=maxa;x++){
		memset(d,0,sizeof(d));
		memset(f,0,sizeof(f));
		s1[1]=s2[1]=x;
		for(int i=2;i<=n;i++){
			s1[i]=s1[i-1]+b[i-1];
			s2[i]=s2[i-1]+s1[i];
		}
		d[0]=1;
		for(int i=1;i<=n;i++){
			g[0]=d[0];
			for(int j=1;j<=sum;j++) g[j]=mod(g[j-1]+d[j]);
			for(int j=max(0,s2[i]);j<=sum;j++) f[j]=mod(cys+g[j]-(j-c[i]-1>=0?g[j-c[i]-1]:0));
			for(int j=0;j<=sum;j++) d[j]=f[j],f[j]=0;
		}
		for(int i=0;i<=sum;i++) ans[x-mina]=mod(ans[x-mina]+d[i]);
	}
	q=readint();
	int x;
	while(q--){
		x=readint();
		chkmax(x,mina);
		chkmin(x,maxa);
		printf("%d\n",ans[x-mina]);
	}
	return 0;
}