#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,pii> piii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

int n, m;
vector<vector<int>> arr;
char DIR[] = "DRUL";
int px[] = {1,0,-1,0};
int py[] = {0,1,0,-1};

int nxt[200100], sz[200100], part[200100];
vector<int> lis[200100];

bool ok(int x, int y) {
	return x>=0&&x<n&&y>=0&&y<m;
}

struct segtree {
	int mini[530000];
	int minc[530000];
	int rem[530000];
	void pd(int idx) {
		mini[idx*2]+=rem[idx];
		mini[idx*2+1]+=rem[idx];
		rem[idx*2]+=rem[idx];
		rem[idx*2+1]+=rem[idx];
		rem[idx] = 0;
	}
	void pu(int idx) {
		if (mini[idx*2]<mini[idx*2+1]) {
			mini[idx]=mini[idx*2];
			minc[idx]=minc[idx*2];
		}
		else if (mini[idx*2]>mini[idx*2+1]) {
			mini[idx]=mini[idx*2+1];
			minc[idx]=minc[idx*2+1];
		}
		else {
			mini[idx]=mini[idx*2];
			minc[idx]=minc[idx*2]+minc[idx*2+1];
		}
	}
	void init(int s=0, int e=n*m, int idx=1) {
		if (s==e) {
			mini[idx]=rem[idx]=0;
			minc[idx]=1;
			return;
		}
		int m = (s+e)/2;
		init(s,m,idx*2);
		init(m+1,e,idx*2+1);
		pu(idx);
	}
	void upd(int S, int E, int val, int s=0, int e=n*m, int idx=1) {
		if (e<S||E<s) return;
		if (S<=s&&e<=E) {
			mini[idx]+=val;
			rem[idx]+=val;
			return;
		}
		pd(idx);
		int m = (s+e)/2;
		upd(S,E,val,s,m,idx*2);
		upd(S,E,val,m+1,e,idx*2+1);
		pu(idx);
	}
	int get0(int S, int E, int s=0, int e=n*m, int idx=1) {
		if (e<S||E<s) return 0;
		if (S<=s&&e<=E) {
			return ((mini[idx]==0)?minc[idx]:0);
		}
		pd(idx);
		int m = (s+e)/2;
		return get0(S,E,s,m,idx*2)+get0(S,E,m+1,e,idx*2+1);
	}
} it;

int st[200100], en[200100];
int tc;
void idfs(int here) {
	st[here] = (tc++);
	sz[here] = 1;
	for (int &there : lis[here]) {
		idfs(there);
		sz[here] += sz[there];
	}
	en[here] = tc-1;
}
ll ans;
void dfs(int here) {
	if (here!=n*m) {
		ans += 1LL * sz[here] * it.get0(st[part[here]],en[part[here]]);
		it.upd(st[part[here]],en[part[here]],1);
	}
	for (int &there : lis[here]) {
		dfs(there);
	}
	if (here!=n*m) {
		it.upd(st[part[here]],en[part[here]], -1);
	}
}

char buf[200100];
int main(){
	scanf("%d%d",&n,&m);
	arr.resize(n);
	for (int i=0;i<n;i++) {
		arr[i].resize(m);
		scanf("%s",buf);
		for (int j=0;j<m;j++) {
			int k=0;
			for (;DIR[k]!=buf[j];k++);
			arr[i][j] = k;
		}
	}
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			part[i*m+j] = (i-px[arr[i][j]])*m+(j-py[arr[i][j]]);
			int x = i, y = j;
			x += px[arr[i][j]];
			y += py[arr[i][j]];
			if (!ok(x,y)) {
				nxt[i*m+j] = -1;
				continue;
			}
			int nx = x-px[arr[x][y]];
			int ny = y-py[arr[x][y]];
			nxt[i*m+j] = nx*m+ny;
		}
	}
	for (int i=0;i<n*m;i++) {
		if (nxt[i] >= 0) {
			lis[nxt[i]].push_back(i);
		}
		else {
			lis[n*m].push_back(i);
		}
	}
	it.init();
	idfs(n*m);
	dfs(n*m);
	printf("%lld\n",ans/2);

	return 0;
}