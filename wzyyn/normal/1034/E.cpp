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
const int N=1<<21|5;
char s1[N],s2[N];
int n,cnt[N];
ull a[N],b[N];
void FWT(ull *a,int n){
	for (int d=1;d<n;d<<=1)
		for (int i=0;i<n;i+=d<<1)
			for (int j=0;j<d;j++)
				a[i+j+d]+=a[i+j];
}
void IFWT(ull *a,int n){
	for (int d=1;d<n;d<<=1)
		for (int i=0;i<n;i+=d<<1)
			for (int j=0;j<d;j++)
				a[i+j+d]-=a[i+j];
}
int main(){
	scanf("%d%s%s",&n,s1,s2);
	For(i,0,(1<<n)-1) cnt[i]=cnt[i/2]+((i&1)<<1); 
	For(i,0,(1<<n)-1) a[i]=(ull)(s1[i]-'0')<<cnt[i];
	For(i,0,(1<<n)-1) b[i]=(ull)(s2[i]-'0')<<cnt[i];
	FWT(a,1<<n); FWT(b,1<<n);
	For(i,0,(1<<n)-1) a[i]*=b[i];
	IFWT(a,1<<n);
	For(i,0,(1<<n)-1) putchar('0'+((a[i]>>cnt[i])&3));
}