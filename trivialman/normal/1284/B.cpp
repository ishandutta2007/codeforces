#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const int N = 1e5+5;
mt19937 rng(time(0));

struct dat{
	int l, r;
	bool operator<(dat y){return l<y.l;}
}a[N];
int n, m, k, x;
bool flag;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&k);
		int pre = 1e7, ma = 0, mi = 1e7;
		flag = false;
		rep(j,1,k){
			scanf("%d",&x);
			if(pre<x) flag = true;
			ma = max(ma, x);
			mi = min(mi, x);
			pre = x;
		}
		if(!flag){
			a[++m] = {mi, ma};
		}
	}
	sort(a+1,a+m+1);
	LL ans = 1ll*n*n;
	rep(i,1,m){
		int l = 1, r = m, mid, ii=m+1, x = a[i].r;
		while(l<=r){
			mid = l+r>>1;
			if(x>a[mid].l) l=mid+1;
			else r=mid-1, ii=mid;
		}
		ans -= (m-ii+1);
	}
	cout<<ans<<endl;
	return 0;
}