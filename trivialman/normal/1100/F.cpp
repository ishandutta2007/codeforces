#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
#define PII pair<int,int>
typedef long long LL;
const LL P = 1e9+7;
const int N = 5e5+5;
const LL INF = 1e16;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int n,q,r,a[N],l[N],ans[N],b[30],bi[30];
vector<int> w[N];
 
int main(){
	//freopen("test.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",a+i);
	scanf("%d",&q);
	rep(i,1,q)scanf("%d%d",&l[i],&r),w[r].PB(i);
	memset(b,0,sizeof b);
	memset(bi,0,sizeof bi);
	memset(ans,0,sizeof ans);
	rep(i,1,n){
		int x = a[i], p = i;
		rrep(j,19,0)if(x>>j&1){
			if(!b[j]){
				b[j] = x, bi[j] = p;
				break;
			}
			if(bi[j]<p) swap(bi[j],p), swap(b[j],x);
			x ^= b[j];
		}
		for(auto x:w[i]) rrep(j,19,0){
			if(bi[j]>=l[x]) ans[x] = max(ans[x], b[j]^ans[x]);
		}
	}
	rep(i,1,q)printf("%d\n",ans[i]);
	return 0;
}