#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define fi first
#define se second
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
 
#define INF ((1<<30)-233)
#define sqr(x) ((x)*(x))
#define debug puts("wzpkking")
using namespace std;
 
map<ll,vector<pii > > mp;
map<pii,int> ans;
int n,cnt;
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int tp,x,y;
		scanf("%d%d%d",&tp,&x,&y);
		if (tp==1){
			cnt++;
			vector<pii>& v=mp[1ll*x*x+1ll*y*y];
			for (auto t:v){
				ll X=t.fi+x,Y=t.se+y;
				ll G=gcd(X,Y);
				ans[pii(X/G,Y/G)]+=2;
			}
			ll G=gcd(x,y);
			ans[pii(x/G,y/G)]++;
			v.push_back(pii(x,y));
		}
		else if (tp==2){
			cnt--;
			vector<pii>& v=mp[1ll*x*x+1ll*y*y];
			vector<pii> nv;
			for (auto t:v)if (t.fi!=x||t.se!=y){
				ll X=t.fi+x,Y=t.se+y;
				ll G=gcd(X,Y);
				ans[pii(X/G,Y/G)]-=2;
				nv.push_back(t);
			}
			ll G=gcd(x,y);
			ans[pii(x/G,y/G)]--;
			mp[1ll*x*x+1ll*y*y]=nv;
		}
		else{
			int G=gcd(x,y); x/=G; y/=G;
			printf("%d\n",cnt-ans[pii(x,y)]);
		}
	}
}