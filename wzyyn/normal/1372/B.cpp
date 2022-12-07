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

void solve(){
	int n;
	scanf("%d",&n);
	int v1=n-1;
	for (int i=2;i*i<=n;i++)
		if (n%i==0) v1=min(v1,n-n/i);
	printf("%d %d\n",v1,n-v1);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve(); 
}