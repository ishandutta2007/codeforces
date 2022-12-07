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
int n,k,a[55],b[55];
void solve(){
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) scanf("%d",&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	int p1=1,p2=n;
	for (;k&&p1<=n&&a[p1]<b[p2];)
		swap(a[p1],b[p2]),p1++,p2--,k--;
	int sum=0;
	For(i,1,n) sum+=a[i];
	printf("%d\n",sum); 
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}