#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>

using namespace std;

int n;
vector<int> lis[100100];
int col[100100];
int cols[100100];

void dfs(int here, int p) {
	int i, mycol = col[here], t = -1;
	for (i=0;i<lis[here].size();i++) {
		int there = lis[here][i];
		if (there==p) {t = i;continue;}
		dfs(there,here);
		if (mycol!=cols[there]) mycol = -1;
	}
	if (~t) lis[here].erase(lis[here].begin()+t);
	cols[here] = mycol;
}

int res = -1;
void dfs2(int here, int p, int cur) {
	if (cur==-1) return;
	int i, mycol = col[here], cnt = 0, bnt = 0;
	for (i=0;i<lis[here].size();i++) { 
		int there = lis[here][i];
		if (cols[there]==-1) bnt++;
		else if (mycol!=cols[there]) {
			cnt++;
		}
	}
	if (!bnt) {
		res = here;
		return;
	}
	if (bnt>=2) return;
	if (cnt) return;
	if (cur!=mycol) return;
	for (i=0;i<lis[here].size();i++) {
		int there = lis[here][i];
		if (cols[there]==-1) {
			dfs2(there,here,mycol);
			if (~res) return;
		}
	}
}

int main() {
	int i;
	scanf("%d",&n);
	for (i=0;i<n-1;i++) {
		int a, b;
		scanf("%d%d",&a,&b);
		--a;--b;
		lis[a].push_back(b);
		lis[b].push_back(a);
	}
	for (i=0;i<n;i++) scanf("%d",&col[i]);
	dfs(0,-1);
	dfs2(0,-1,col[0]);
	if (~res) printf("YES\n%d\n",res+1);
	else printf("NO\n");

	return 0;
}