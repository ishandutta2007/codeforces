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
const int mo=1000000007;
const int I2=500000004;
int n,ans;
char s[1<<20];
int a[1<<20];
int cnt[1<<20];
void FWT(int *a,int n){
	for (int d=1;d<n;d<<=1)
		for (int i=0;i<n;i+=(d<<1))
			for (int j=0;j<d;j++){
				int x=a[i+j],y=a[i+j+d];
				a[i+j]=(x+y)%mo;
				a[i+j+d]=(x+mo-y)%mo;
			}
}
void IFWT(int *a,int n){
	for (int d=1;d<n;d<<=1)
		for (int i=0;i<n;i+=(d<<1))
			for (int j=0;j<d;j++){
				int x=a[i+j],y=a[i+j+d];
				a[i+j]=1ll*(x+y)*I2%mo;
				a[i+j+d]=1ll*(x+mo-y)*I2%mo;
			}
}
int main(){
	scanf("%d",&n);
	scanf("%s",s);
	For(i,0,(1<<n)-1) a[i]=s[i]-'0';
	FWT(a,1<<n);
	For(i,0,(1<<n)-1) a[i]=1ll*a[i]*a[i]%mo;
	IFWT(a,1<<n);
	For(i,0,(1<<n)-1){
		cnt[i]=cnt[i/2]+(i&1);
		ans=(ans+1ll*a[i]*(1<<(n-cnt[i])))%mo;
	}
	printf("%lld\n",3ll*ans%mo);
}