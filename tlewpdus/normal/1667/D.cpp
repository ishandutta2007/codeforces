#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N;
vector<int> lis[200100];
int D[2][200100];
int col[200100];

void dfs(int here, int p, int d) {
	int c = (d+(int)lis[here].size())%2;
	col[here] = c;
	int cnt[4] = {0,0,0,0};
	int cn = 0;
	for (int &there : lis[here]) {
		if (there==p) continue;
		dfs(there, here, d+1);
		cnt[D[0][there]+D[1][there]*2]++;
		cn++;
	}
	if (cnt[0]) {
		D[0][here] = D[1][here] = 0;
		return;
	}
	int del[2] = {-1,1};
	if (p==-1) {
		del[0] = del[1] = 0;
	}
	for (int t=0;t<2;t++) {
		int cur = c + del[t];
		int a=0, b=0;
		if ((cn-cur)%2==0) a = (cn-cur)/2, b = cn-a;
		else a = (cn-cur+1)/2, b=cn-a;
		if (a<0||b<0) {
			D[t][here] = 0;
			continue;
		}
		if (cnt[1]+cnt[3]>=a && cnt[2]+cnt[3]>=b) {
			D[t][here] = 1;
		}
		else D[t][here] = 0;
	}
}

int dir[200100];
vector<int> tis[200100];
int idx[200100];
void adfs(int here, int p, int d, int t) {
	int c = (d+(int)lis[here].size())%2;
	int cnt[4] = {0,0,0,0};
	int cn = 0;
	for (int &there : lis[here]) {
		if (there==p) continue;
		cnt[D[0][there]+D[1][there]*2]++;
		cn++;
	}
	int del[2] = {-1,1};
	if (p==-1) del[0] = del[1] = 0;

	int cur = c + del[t];
	int a=0, b=0;
	if ((cn-cur)%2==0) a = (cn-cur)/2, b = cn-a;
	else a = (cn-cur+1)/2, b=cn-a;


		if (cnt[1]+cnt[3]>=a && cnt[2]+cnt[3]>=b) {
			D[t][here] = 1;
		}

	for (int &there : lis[here]) {
		if (there==p) continue;
		int val = D[0][there]+D[1][there]*2;
		if (val==1) {
			dir[there] = 0;
			a--;
		}
		else if (val==2) {
			dir[there] = 1;
			b--;
		}
	}
	for (int &there : lis[here]) {
		if (there==p) continue;
		int val = D[0][there]+D[1][there]*2;
		if (val==3) {
			if (a>0) {
				dir[there] = 0;
				a--;
			} else {
				dir[there] = 1;
				b--;
			}
		}
	}
	for (int &there : lis[here]) {
		if (there==p) continue;
		if (dir[there]==0) {
			tis[there].push_back(here);
		}
		else {
			tis[here].push_back(there);
		}
		adfs(there, here, d+1, dir[there]);
	}
}

int main() {
	int T;

	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		for (int i=0;i<N;i++) {
			D[0][i] = D[1][i] = dir[i] = 0;
		}
		for (int i=0;i<N-1;i++) {
			int u, v;
			scanf("%d%d",&u,&v); u--; v--;
			lis[u].push_back(v);
			lis[v].push_back(u);
		}
		dfs(0,-1,0);
		if (D[0][0]) {
			puts("YES");
			adfs(0,-1,0,0);
//			for (int i=0;i<N;i++) {
//				printf("%d: ",i+1);
//				for (int &j: tis[i]) printf("%d ",j+1);
//				puts("");
//			}
			for (int i=0;i<N;i++) idx[i] = 0;
			for (int i=0;i<N;i++) {
				if (idx[i]==tis[i].size()) continue;
				if (col[i]==0) continue;
				vector<int> path;
				path.push_back(i);
				int p = i;
				while(idx[p]!=tis[p].size()) {
					p = tis[p][idx[p]++];
					path.push_back(p);
				}
				int last = (int)path.size()-1;
				for (int j=(int)path.size()-1;j>=0;j--) {
					if (col[path[j]]==1) {
						for (int k=j;k<last;k++) {
							printf("%d %d\n",path[k]+1,path[k+1]+1);
						}
						last = j;
					}
				}
				col[path[0]]^=1;
				col[path.back()]^=1;
			}
		}
		else {
			puts("NO");
		}
		for (int i=0;i<N;i++) lis[i].clear(), tis[i].clear();
	}

	return 0;
}