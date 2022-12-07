#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=400005;
const int mo=998244353;

int n,a[105];
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	a[0]=-1;
	For(i,1,n) if (a[i]!=a[i-1]) cout<<a[i]<<' ';
	For(i,1,n) if (a[i]==a[i-1]) cout<<a[i]<<' ';
	cout<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}