#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <list>
#include <map>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <iomanip>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
int _,n,m,brr[N<<1],sum[N<<3];
pii arr[N];
void build(int o=1,int l=1,int r=m) {
	sum[o]=0;
	if(l==r) {
		return;
	}
	build(lo,l,mid);
	build(ro,mid+1,r);
}
void add(int p,int v,int o=1,int l=1,int r=m) {
	if(l==r) {
		sum[o]+=v;
		return;
	}
	if(p<=mid)add(p,v,lo,l,mid);
	else add(p,v,ro,mid+1,r);
	sum[o]=sum[lo]+sum[ro];
}
int query(int ql,int qr,int o=1,int l=1,int r=m) {
	if(ql<=l&&r<=qr) {
		return sum[o];
	}
	int ret=0;
	if(ql<=mid)ret+=query(ql,qr,lo,l,mid);
	if(qr>mid)ret+=query(ql,qr,ro,mid+1,r);
	return ret;
}
bool cmp(pii a,pii b) {
	if(a.se!=b.se)return a.se<b.se;
	else return a.fi>b.fi;
}
int solve() {
	cin>>n;
	map<int,int>mp;
	for(int i=0; i<n; i++) {
		cin>>arr[i].fi>>arr[i].se;
		mp[arr[i].fi];
		mp[arr[i].se];
	}
	m=0;
	for(auto &i:mp) {
		i.se=++m;
	}
	build();
	for(int i=0; i<n; i++) {
		add(mp[arr[i].fi],1);
		add(mp[arr[i].se],1);
	}
	sort(arr,arr+n,cmp);
	int ret=0;
	for(int i=0; i<n; i++) {
		add(mp[arr[i].fi],-1);
		if(i==n-1||arr[i]!=arr[i+1])ret=max(ret,query(mp[arr[i].fi],mp[arr[i].se]));
	}

	ret=n-ret;
	return ret;
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("in.txt","r",stdin);
	cin>>_;
	while(_--)
		cout<<solve()<<endl;
	return 0;
}