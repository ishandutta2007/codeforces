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
int n,a[N],b[N],c[N];
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&c[i]);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) scanf("%d",&b[i]);
	ll len=c[n]-1,ans=0;
	Rep(i,n,2){
		ans=max(ans,len+2+abs(a[i]-b[i]));
		if (a[i]==b[i]) len=0;
		else len+=2+c[i-1]-max(a[i],b[i])+min(a[i],b[i])-1;
		len=max(len,1ll*c[i-1]-1);
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}