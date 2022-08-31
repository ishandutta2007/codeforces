#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define FOR(i,a,b) for(int i = a; i < b; i++)

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

int n,m;
int SZ;

struct node{
	int l = 0,r = 131071,val = 0;
	int lft = -1,rgt = -1;
};

vector<node> seg;
int root[100005];

int quer(int ind,int val){
	if(seg[ind].l >= val) return 0;
	if(seg[ind].r < val) return seg[ind].val;
	int res = 0;
	if(seg[ind].lft != -1) res = max(res,quer(seg[ind].lft,val));
	if(seg[ind].rgt != -1) res = max(res,quer(seg[ind].rgt,val));

	return res;
}

void upd(int ind,int pos,int val){
	// trace(ind,pos,val);
	// trace(seg[ind].l,seg[ind].r);
	seg[ind].val = max(seg[ind].val,val);
	if(seg[ind].l == seg[ind].r) return;
	int mid = (seg[ind].l+seg[ind].r)/2;
	if(pos <= mid){
		if(seg[ind].lft == -1){
			node gg;
			seg.push_back(gg);
			seg[ind].lft = SZ;
			seg[SZ].l = seg[ind].l;
			seg[SZ].r = mid;
			SZ++;
		}
		upd(seg[ind].lft,pos,val);
	}
	else{
		if(seg[ind].rgt == -1){
			node gg;
			seg.push_back(gg);
			seg[ind].rgt = SZ;
			seg[SZ].r = seg[ind].r;
			seg[SZ].l = mid+1;
			SZ++;
		}
		upd(seg[ind].rgt,pos,val);
	}
}

signed main(){
	cin >> n >> m;
	FOR(i,1,n+1){
		root[i] = i-1;
		node gg;
		seg.push_back(gg);
	}
	SZ = n;
	REP(i,m){
		int u,v,w;
		cin >> u >> v >> w;
		// cout << "<gg>\n";
		int cur = quer(root[u],w);
		// cout << cur << "-\n";
		upd(root[v],w,cur+1);
		// cout << "</gg>\n";
	}
	int ans = 0;
	FOR(i,1,n+1){
		ans = max(ans,seg[i-1].val);
	}
	cout << ans << endl;
}