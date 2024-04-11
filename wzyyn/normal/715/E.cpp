#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int mo=998244353;
const int N=2005;
int n,p[N],q[N];
int d[N],fl[N],nx[N];
int f[N],ans,cnt,vis[N];
int no,na,nb,nab;
int main(){
	ans=1;
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&p[i]);
	For(i,1,n) scanf("%d",&q[i]);
	For(i,1,n){
		if (p[i]&&q[i]) ++d[q[i]],nx[p[i]]=q[i];
		if (!p[i]&&!q[i]) ans=1ll*ans*(++cnt)%mo;
		if (p[i]&&!q[i]) fl[p[i]]|=1;
		if (!p[i]&&q[i]) fl[q[i]]|=2;
	}
	cnt=0;
	For(i,1,n)
		if (!d[i]&&!vis[i]){
			int j=i; vis[i]=1;
			for (;nx[j];vis[j=nx[j]]=1);
			//cout<<i<<' '<<j<<endl;
			if (fl[i]&2) fl[j]&1?++nab:++nb;
			else fl[j]&1?++na:++no;
		}
	For(i,1,n) if (!vis[i]){
		++cnt;
		for (int j=i;!vis[j];j=nx[j]) vis[j]=1;
	}
	For(i,1,nab) ans=1ll*ans*(no+1-i)%mo;
	//cout<<cnt<<' '<<ans<<' '<<no<<' '<<na<<' '<<nb<<' '<<nab<<endl;
	f[cnt]=ans;
	For(i,1,no+na){
		Rep(j,n,1) f[j]=(1ll*f[j]*(i-1)+f[j-1])%mo;
		f[0]=0;
	}
	For(i,1,nb){
		Rep(j,n,1) f[j]=(1ll*f[j]*(i+no-1)+f[j-1])%mo;
		f[0]=0;
	}
	For(i,0,n-1)
		printf("%d ",f[n-i]);
}
/*
a->b
a->0
0->b
0->0
*/