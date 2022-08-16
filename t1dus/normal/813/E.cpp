#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define all(v) v.begin(),v.end()

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif


const int MX = 100000;

int n,k,q;
int a[MX+5],b[MX+5],root[MX+5];
vi v[MX+5];

int SZ = 0;

struct node{
	int l,r,lt,rt;
	int val;
	node(){
		l = 1,r = MX;
		lt = -1,rt = -1;
		val = 0;
	}
}; node seg[100*MX];

int build(int l,int r){
	int ind = (++SZ);
	seg[ind].l = l;
	seg[ind].r = r;
	if(l == r){
		return ind;
	}
	int mid = (l+r)/2;
	seg[ind].lt = build(l,mid);
	seg[ind].rt = build(mid+1,r);
	return ind;
}

int upd(int preid,int l,int r,int pos){
	int ind = (++SZ);
	seg[ind].l = l;
	seg[ind].r = r;
	if(l == r){
		seg[ind].val = seg[preid].val+1;
		return ind;
	}
	seg[ind].lt = seg[preid].lt;
	seg[ind].rt = seg[preid].rt;
	int mid = (l+r)/2;
	if(pos <= mid){
		seg[ind].lt = upd(seg[preid].lt,l,mid,pos);
	}
	else{
		seg[ind].rt = upd(seg[preid].rt,mid+1,r,pos);
	}
	seg[ind].val = seg[seg[ind].lt].val+seg[seg[ind].rt].val;
	return ind;
}

int quer(int ind1,int ind2,int gg){
	// trace(seg[ind1].l,seg[ind1].r,seg[ind1].val,seg[ind2].val,gg);
	if(gg < seg[ind1].l){
		return 0;
	}
	if(seg[ind1].r <= gg){
		return seg[ind1].val-seg[ind2].val;
	}
	return quer(seg[ind1].lt,seg[ind2].lt,gg)+quer(seg[ind1].rt,seg[ind2].rt,gg);
}

int main(){
	cin >> n >> k;
	FOR(i,1,n+1){
		cin >> a[i];
		v[a[i]].pb(i);
	}
	FOR(i,1,n+1){
		if(v[a[i]].size() <= k) b[i] = 0;
		else{
			int ind = lower_bound(all(v[a[i]]),i)-v[a[i]].begin();
			if(ind < k) b[i] = 0;
			else b[i] = v[a[i]][ind-k];
		}
		// cout << i << " - " << b[i] << endl;
	}
	root[0] = build(0,n);
	FOR(i,1,n+1){
		root[i] = upd(root[i-1],0,n,b[i]);
	}
	cin >> q;
	int last = 0;
	while(q --){
		int l,r; cin >> l >> r;
		l = ((l+last)%n)+1;
		r = ((r+last)%n)+1;
		if(l > r) swap(l,r);
		// cout << l << " - " << r << endl;
		last = quer(root[r],root[l-1],l-1);
		cout << last << endl;
	}
}