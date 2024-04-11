#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=105;
int n,l[N],r[N],a[N];
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d%d",&l[i],&r[i]);
	For(i,1,n) scanf("%d",&a[i]);
	int T=0;
	for (int i=1;i<n;i++){
		T+=a[i]+l[i]-r[i-1];
		T+=(r[i]-l[i]+1)/2;
		T=max(T,r[i]);
	}
	T+=a[n]+l[n]-r[n-1];
	cout<<T<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}