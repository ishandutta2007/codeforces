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
const int N=1<<20;
int n,m,S[N],cnt[N];
ll a[N],b[N];
char s[N];
void FWT(ll *a,int n){
	for (int d=1;d<1<<n;d<<=1)
		for (int i=0;i<1<<n;i+=d<<1)
			for (int j=0;j<d;j++){
				ll x=a[i+j],y=a[i+j+d];
				a[i+j]=x+y; a[i+j+d]=x-y;
			}
}
void IFWT(ll *a,int n){
	for (int d=1;d<1<<n;d<<=1)
		for (int i=0;i<1<<n;i+=d<<1)
			for (int j=0;j<d;j++){
				ll x=a[i+j],y=a[i+j+d];
				a[i+j]=(x+y)/2; a[i+j+d]=(x-y)/2;
			}
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,0,n-1){
		scanf("%s",s+1);
		For(j,1,m) if (s[j]=='1') S[j]|=1<<i;
	}
	For(i,1,m) a[S[i]]++;
	For(i,0,(1<<n)-1) cnt[i]=cnt[i/2]+(i&1);
	For(i,0,(1<<n)-1) b[i]=min(cnt[i],n-cnt[i]);
	FWT(a,n); FWT(b,n);
	For(i,0,(1<<n)-1) a[i]*=b[i];
	IFWT(a,n);
	int ans=1<<30;
	//For(i,0,(1<<n)-1) cout<<i<<' '<<a[i]<<endl;
	For(i,0,(1<<n)-1) ans=min(1ll*ans,a[i]);
	cout<<ans<<endl;
}