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
const int N=200005;
int n,m,k,Q,x,a[N],fl[N];
vector<int> v1[N];
vector<ll> v2[N];
ll wzp;
pll calc(int lim,int v){
	int p0=upper_bound(v1[0].begin(),v1[0].end(),v)-v1[0].begin();
	int p1=upper_bound(v1[1].begin(),v1[1].end(),v)-v1[1].begin();
	int p2=upper_bound(v1[2].begin(),v1[2].end(),v)-v1[2].begin();
	p0--;
	p1=max(p1-1,lim-1);
	p2=max(p2-1,lim-1);
	ll sum=0;
	if (p0>=0) sum+=v2[0][p0];
	if (p1>=0) sum+=v2[1][p1];
	if (p2>=0) sum+=v2[2][p2];
	//cout<<lim<<' '<<v<<' '<<p0<<' '<<p1<<' '<<p2<<endl; 
	return pll(p0+p1+p2+3,sum);
}
void solve(int v){
	if (v1[1].size()+v<k) return;
	if (v1[2].size()+v<k) return;
	if (v+2*max(k-v,0)>m) return;
	int l=-1,r=1e9+233;
	ll ans=1ll<<60;
	while (l<=r){
		int mid=(l+r+2)/2-1;
		pll res=calc(max(k-v,0),mid);
		if (res.fi+v>=m){
			ans=res.se-1ll*(res.fi+v-m)*mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	if (v) ans+=v2[3][v-1];
	//cout<<ans<<' '<<v<<endl;
	wzp=min(wzp,ans);
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	For(i,1,n) scanf("%d",&a[i]);
	scanf("%d",&Q);
	For(i,1,Q) scanf("%d",&x),fl[x]|=1;
	scanf("%d",&Q); 
	For(i,1,Q) scanf("%d",&x),fl[x]|=2;
	For(i,1,n) v1[fl[i]].PB(a[i]);
	For(i,0,3){
		ll sum=0;
		sort(v1[i].begin(),v1[i].end());
		for (auto j:v1[i]) v2[i].PB(sum+=j);
	}
	wzp=1ll<<60;
	For(i,0,min((int)v1[3].size(),m)) solve(i);
	if (wzp>1ll<<52) wzp=-1;
	cout<<wzp<<endl;
}