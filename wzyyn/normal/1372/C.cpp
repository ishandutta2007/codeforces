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
const int N=200005;
int n,a[N];
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	int f0=1,f1=1,f2=0;
	For(i,1,n)
		if (a[i]!=i){
			if (a[i-1]==i-1&&f2) f1=0;
			f0=0; f2=1;
		}
	printf("%d\n",(f0?0:(f1?1:2)));
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}