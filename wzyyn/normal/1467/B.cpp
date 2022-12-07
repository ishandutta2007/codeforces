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

const int N=300005;
int a[N],fl[N],n;
bool chk(int x){
	return x>1&&x<n&&1ll*(a[x]-a[x-1])*(a[x]-a[x+1])>0;
}
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	ll S=0,ans=1ll<<60;
	For(i,1,n) if (fl[i]=chk(i)) S++;
	For(i,1,n) For(j,-1,1){
		int v=a[i+j];
		ll tmp=S;
		For(k,-2,2) if (chk(i-k)) tmp--;
		swap(v,a[i]);
		For(k,-2,2) if (chk(i-k)) tmp++;
		swap(v,a[i]);
		ans=min(ans,tmp);
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}