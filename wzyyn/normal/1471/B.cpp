#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;
int n,x,a[200005];
void solve(){
	scanf("%d%d",&n,&x);
	For(i,1,n) scanf("%d",&a[i]);
	int mn=1<<30;
	For(i,1,n){
		int y=a[i],t=0;
		for (;y%x==0;y/=x,++t);
		mn=min(mn,t);
	}
	mn++;
	ll ans=0;
	For(i,1,n){
		int y=a[i],t=0;
		for (;y%x==0;y/=x,++t);
		mn=min(mn,t); ans+=1ll*(mn+1)*a[i];
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}