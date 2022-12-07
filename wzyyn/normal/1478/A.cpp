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

int n,ans,a[105],x;
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	x=1; ans=0;
	For(i,1,n){
		x=(a[i]==a[i-1]?x+1:1);
		ans=max(ans,x);
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}