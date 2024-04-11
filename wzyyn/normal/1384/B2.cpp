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
using namespace std;
int a[300005];
void solve(){
	int n,k,l;
	scanf("%d%d%d",&n,&k,&l);
	For(i,1,n) scanf("%d",&a[i]);
	int t=-1;
	For(i,1,n)
		if (a[i]+k<=l) t=-1;
		else if (a[i]>l) return puts("No"),void(0);
		else{
			int low=2*k-(l-a[i]);
			t=max(low,t+1);
			int del=(t%(2*k)<=k?t%(2*k):2*k-t%(2*k));
			//cout<<i<<' '<<t<<' '<<del<<endl;
			if (a[i]+del>l) return puts("No"),void(0);
		}
	puts("Yes");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}