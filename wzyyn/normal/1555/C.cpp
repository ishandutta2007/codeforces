#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=100005;
int m,a[N],b[N];
void solve(){
	scanf("%d",&m);
	for (int i=1;i<=m;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++) scanf("%d",&b[i]);
	a[0]=a[m+1]=b[0]=b[m+1]=0;
	for (int i=m;i>=0;i--) a[i]+=a[i+1];
	for (int i=1;i<=m+1;i++) b[i]+=b[i-1];
	int ans=1<<30;
	for (int i=1;i<=m;i++)
		ans=min(ans,max(a[i+1],b[i-1]));
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}