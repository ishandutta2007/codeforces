#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
using namespace std;
const int N=100005;
int n,a[N],c[N];
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) c[i]=0;
	For(i,1,n) ++c[a[i]];
	For(i,1,n) if (c[i]*2>n+1) return puts("-1"),void(0);
	memset(c,0,sizeof(c));
	int k=0;
	++c[a[1]]; ++c[a[n]];
	For(i,1,n-1) if (a[i]==a[i+1]) c[a[i]]+=2,k++;
	int mx=0;
	For(i,1,n) mx=max(mx,c[i]-k-2);
	cout<<k+mx<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}