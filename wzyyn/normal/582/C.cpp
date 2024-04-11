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
int n,a[N],b[N];
int S[N],fl[N*2];
vector<int> vec[N];
ll ans;
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
void solve(int l){
	For(i,0,l-1) b[i]=0;
	For(i,1,n) b[i%l]=max(b[i%l],a[i]);
	For(i,1,n) fl[i]=fl[i+n]=(a[i]>=b[i%l]);
	memset(S,0,sizeof(S));
	for (auto i:vec[l]) ++S[i];
	For(i,1,n) S[i]+=S[i-1];
	int v=0;
	Rep(i,2*n,1){
		v=min(n,(fl[i]?v+1:0));
		if (i<=n) ans+=S[v];
	}
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n-1) vec[gcd(i,n)].PB(i);
	For(i,1,n) if (vec[i].size()) solve(i);
	printf("%lld\n",ans);
}