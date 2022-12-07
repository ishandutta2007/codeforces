#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;

int a[55],n;
ll f[55];
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	f[1]=a[1];
	For(i,2,n) f[i]=max(f[i-1],f[i-2]+a[i]);
	int p=(f[n-1]>=f[n]?n-1:n);
	if (p==n-1) a[n]=1;
	for (;p>=1;)
		if (f[p]==f[p-2]+a[p])
			a[p-1]=1,p-=2;
		else a[p]=1,p--;
	For(i,1,n) printf("%d ",a[i]);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}