#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
// #define DEBUG 0

pii st[1<<20];
pii a[1<<19];
int n;
pii merge(pii a, pii b) {
	int x = max(a.first,b.first);
	int y = min(a.second,b.second);
	return pair<int, int>{x,y};
}
void build(int v=1,int l=0,int r=n-1) {
	if(l==r) {
		st[v]=a[l];
	} else {
		int m=(l+r)/2;
		build(2*v,l,m);
		build(2*v+1,m+1,r);
		st[v]=merge(st[v*2],st[v*2+1]);
	}
}

pii qry(int l,int r,int v=1,int t1=0,int t2=n-1) {
	if(l<=t1&&r>=t2) {
		return st[v];
	}
	if(t1>r||l>t2) {
		return {0,2e9};
	}

	int m=(t1+t2)/2;
	return merge(qry(l,r,2*v,t1,m),qry(l,r,2*v+1,m+1,t2));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> a[i].first >> a[i].second;
	}

	int ans=0;
	build();
	for(int i=0;i<n;i++) {
		pii a=qry(0,i-1),b=qry(i+1,n-1);
		pii x=merge(a,b);
		ans=max(ans,x.second-x.first);
	}
	cout << ans << "\n";
}