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

int n,W;
int f[1<<19|5];
bool check(int T){
	int re=0;
	for (int i=0;i<=29;i++){
		if (i<=19) re+=f[1<<i];
		if (W&(1<<i)) re-=T;
		re=max(re,0);
		re=(re+1)/2;
	}
	return re==0;
}
void solve(){
	scanf("%d%d",&n,&W);
	for (int i=0;i<=19;i++) f[1<<i]=0;
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		++f[x];
	}
	int l=1,r=n,ans=-1;
	while (l<=r){
		int mid=(l+r)/2;
		if (check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}