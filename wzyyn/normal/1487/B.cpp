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
	int n,k;
	scanf("%d%d",&n,&k);
	if (n%2==0) printf("%d\n",(k-1)%n+1);
	else printf("%d\n",(k-1+((k-1)/(n/2)))%n+1);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}