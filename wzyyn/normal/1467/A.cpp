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

void solve(){
	int n;
	scanf("%d",&n);
	For(i,1,n) printf("%d",i<=2?10-i:(i+6)%10);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}