#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int N, K;
struct node {
	vector<int> F, mini, maxi;
	void init(int N) {
		F.assign(N,INF);
		mini.assign(N,INF);
		maxi.assign(N,0);
	}
};
node tree[1050000];
int chk[1050000];
int sz[1050000];
void idfs(int idx, int d) {
	tree[idx].init(1<<d);
	if (d>0) {
		idfs(idx * 2, d - 1);
		idfs(idx * 2 + 1, d - 1);
	}
	if (d==0) {
		int val = idx-(1<<K);
		if (chk[val]) {
			sz[idx] = 1;
			tree[idx].F[0] = INF;
			tree[idx].mini[0] = tree[idx].maxi[0] = 0;
		}
		else {
			sz[idx] = 0;
			tree[idx].F[0] = INF;
			tree[idx].mini[0] = INF;
			tree[idx].maxi[0] = 0;
		}
	}
	else {
		sz[idx] = sz[idx*2]+sz[idx*2+1];
		for (int x=0;x<(1<<d);x++) {
			int msb = (x>>(d-1)&1);
			int xp = (x&((1<<(d-1))-1));
			if (msb) {
				if (sz[idx*2]) {
					tree[idx].F[x] = min(tree[idx].F[x], tree[idx*2].F[xp]);
					tree[idx].mini[x] = min(tree[idx].mini[x], (1<<(d-1))+tree[idx*2].mini[xp]);
					tree[idx].maxi[x] = max(tree[idx].maxi[x], (1<<(d-1))+tree[idx*2].maxi[xp]);
				}
				if (sz[idx*2+1]) {
					tree[idx].F[x] = min(tree[idx].F[x], tree[idx*2+1].F[xp]);
					tree[idx].mini[x] = min(tree[idx].mini[x], tree[idx*2+1].mini[xp]);
					tree[idx].maxi[x] = max(tree[idx].maxi[x], tree[idx*2+1].maxi[xp]);
				}
				if (sz[idx*2] && sz[idx*2+1]) {
					tree[idx].F[x] = min(tree[idx].F[x],tree[idx*2].mini[xp]-tree[idx*2+1].maxi[xp]+(1<<(d-1)));
				}
			}
			else {
				if (sz[idx*2]) {
					tree[idx].F[x] = min(tree[idx].F[x], tree[idx*2].F[xp]);
					tree[idx].mini[x] = min(tree[idx].mini[x], tree[idx*2].mini[xp]);
					tree[idx].maxi[x] = max(tree[idx].maxi[x], tree[idx*2].maxi[xp]);
				}
				if (sz[idx*2+1]) {
					tree[idx].F[x] = min(tree[idx].F[x], tree[idx*2+1].F[xp]);
					tree[idx].mini[x] = min(tree[idx].mini[x], (1<<(d-1))+tree[idx*2+1].mini[xp]);
					tree[idx].maxi[x] = max(tree[idx].maxi[x], (1<<(d-1))+tree[idx*2+1].maxi[xp]);
				}
				if (sz[idx*2] && sz[idx*2+1]) {
					tree[idx].F[x] = min(tree[idx].F[x],tree[idx*2+1].mini[xp]-tree[idx*2].maxi[xp]+(1<<(d-1)));
				}
			}
		}
	}
//	printf("%d : \n",idx);
//	for (int i=0;i<(1<<d);i++) printf("%d ",tree[idx].F[i]); puts("");
//	for (int i=0;i<(1<<d);i++) printf("%d ",tree[idx].mini[i]); puts("");
//	for (int i=0;i<(1<<d);i++) printf("%d ",tree[idx].maxi[i]); puts("");
}

//int rf[1050000];

int main() {
//	N = 10000, K = 19;
	scanf("%d%d",&N,&K);
//	vector<int> se;
	for (int i=0;i<N;i++) {
		int a;
		scanf("%d",&a);
//		a = rand()%(1<<K);
//		se.push_back(a);
		chk[a] = 1;
	}
//	sort(se.begin(),se.end());se.erase(unique(se.begin(),se.end()),se.end());
//	for (int i=0;i<(1<<K);i++) {
//		int mini = INF;
//		for (int j=0;j<se.size();j++) {
//			for (int k=j+1;k<se.size();k++) {
//				mini = min(mini, abs((se[j]^i)-(se[k]^i)));
//			}
//		}
//		rf[i] = mini;
//	}
	idfs(1,K);
	for (int i=0;i<(1<<K);i++) {
		printf("%d ",tree[1].F[i]);
//		assert(tree[1].F[i]==rf[i]);
	}
	puts("");

	return 0;
}