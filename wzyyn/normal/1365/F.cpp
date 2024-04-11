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
int n,a[505],b[505];
pii aa[505],bb[505];
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) scanf("%d",&b[i]);
	if (n&1)
		if (a[(n+1)/2]!=b[(n+1)/2])
			return puts("No"),void(0);
	For(i,1,n/2){
		if (a[i]>a[n-i+1])
			swap(a[i],a[n-i+1]);
		aa[i]=pii(a[i],a[n-i+1]);
	}
	For(i,1,n/2){
		if (b[i]>b[n-i+1])
			swap(b[i],b[n-i+1]);
		bb[i]=pii(b[i],b[n-i+1]);
	}
	sort(aa+1,aa+n/2+1);
	sort(bb+1,bb+n/2+1);
	For(i,1,n/2) if (aa[i]!=bb[i])
		return puts("No"),void(0);
	puts("Yes");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}