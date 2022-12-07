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
const int N=200005;
int n,a[N],b[N],c[N];
int sum[35][2];
ll S;
void GG(){
	puts("-1");
	exit(0);
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]),S+=a[i];
	For(i,1,n) scanf("%d",&b[i]),S+=b[i];
	if (S%(2*n)) GG(); S/=2*n;
	For(i,1,n){
		int v=a[i]+b[i];
		//cout<<S<<' '<<v<<endl;
		if (v<S||(S-v)%n) GG();
		c[i]=(v-S)/n;
	}
	For(i,1,n) For(j,0,30){
		int key=((c[i]>>j)&1);
		++sum[j][key];
	}
	For(i,1,n){
		ll s1=0,s2=0;
		For(j,0,30){
			int key=((c[i]>>j)&1);
			For(k,0,1) s1+=(1ll<<j)*(key&k)*sum[j][k];
			For(k,0,1) s2+=(1ll<<j)*(key|k)*sum[j][k];
		}
		if (s1!=a[i]||s2!=b[i]) GG();
	}
	For(i,1,n)
		printf("%d ",c[i]);
}