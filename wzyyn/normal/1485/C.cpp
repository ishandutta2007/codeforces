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
	int a,b;
	scanf("%d%d",&a,&b); ++b;
	ll re=0;
	for (int l=2,r;l<=min(a,b);l=r+1){
		r=min(a/(a/l),b/(b/l));
		if (l<=50000) r=l;
		re+=(r-l+1)*min(l-2,a/l);
	}
	cout<<re<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}