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

int n,m;
ll l[2005],s[2005],c[4005],lst[2005][4005],d[2005][2005],f[2005][2005],cnt[4005],now[2005];

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) l[i]=readint();
	for(int i=1;i<=n;i++) s[i]=readint();
	for(int i=1;i<=n+m;i++) c[i]=readint();
	for(int i=1;i<=n+1;i++){
		cnt[l[i]]++;
		for(int j=1;j<=m;j++) lst[i][j]=now[j];
		now[l[i]]=i;
	}
	memset(d,-0x3f,sizeof(d));
	d[n+1][0]=0;
	int nmax=0;
	for(int i=1;i<=n+m;i++){
		nmax+=cnt[i];
		for(int j=n+1;j>=1;j--){
			for(int k=0;k<=nmax;k++){
				if(lst[j][i]) chkmax(d[lst[j][i]][k+1],d[j][k]-s[lst[j][i]]+c[i]);
				if(j>1) chkmax(d[j-1][k],d[j][k]);
			}
		}
		for(int j=1;j<=n+1;j++){
			for(int k=0;k<=nmax/2+cnt[i+1];k++) f[j][k]=-0x3f3f3f3f3f3f3f3fll;
			for(int k=0;k<=nmax;k++) chkmax(f[j][k/2],d[j][k]+(k/2)*c[i+1]);
		}
		nmax>>=1;
		for(int j=1;j<=n+1;j++) for(int k=0;k<=nmax+cnt[i+1];k++) d[j][k]=f[j][k];
	}
	ll ans=0;
	for(int i=1;i<=n+1;i++) for(int j=0;j<=nmax;j++) chkmax(ans,d[i][j]);
	printf("%lld\n",ans);
	return 0;
}