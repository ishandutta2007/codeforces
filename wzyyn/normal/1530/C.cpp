#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=200005;
int n,a[N],b[N];
int F(int *a,int r,int l){
	return a[r]-a[max(l,0)];
}
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	for (int i=1;i<=n;i++)
		a[i]+=a[i-1],b[i]+=b[i-1];
	int p=0;
	for (;F(a,n+p,(n+p)/4)<F(b,n,n-(n+p-(n+p)/4));){
		++p;
		a[n+p]=a[n+p-1]+100;
	}
	cout<<p<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}