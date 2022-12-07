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
int n,pr[N],mx;
ll a[N],ans;
map<ll,int> mp;
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%lld",&a[i]);
	For(i,1,n) a[i]+=a[i-1];
	For(i,0,n){
		if (mp.count(a[i]))
			pr[i]=mp[a[i]];
		else pr[i]=-1;
		mp[a[i]]=i;
	}
	mx=-1;
	For(i,1,n){
		mx=max(mx,pr[i]);
		ans+=i-mx-1;
	}
	printf("%lld\n",ans);
}