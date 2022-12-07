#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;

int n;
ll a[105];
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%lld",&a[i]);
	For(i,1,n){
		if (a[i]<i-1) return puts("NO"),void(0);
		a[i+1]+=a[i]-(i-1);
	}
	puts("YES");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}