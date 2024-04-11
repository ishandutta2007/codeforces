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
#define all(v) v.begin(),v.end()
using namespace std;
const int N=1000005;
int n,a[N],b[N];
void mian(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) scanf("%d",&b[i]);
	ll v=1ll<<60;
	For(i,1,n){
		v+=b[i]-a[i];
		if (v<0) return puts("NO"),void(0);
		v=min(v,1ll*b[i]);
	}
	For(i,1,n){
		v+=b[i]-a[i];
		if (v<0) return puts("NO"),void(0);
		v=min(v,1ll*b[i]);
	}
	v=0;
	For(i,1,n) v-=a[i];
	For(i,1,n) v+=b[i];
	puts(v<0?"NO":"YES");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) mian();
}