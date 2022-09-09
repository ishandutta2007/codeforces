#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<string.h>
#include<string>
#include<stdlib.h>

using namespace std;

int n;
vector<int> lis[200100];
int ldep[200100][2];
int kind[200100];

bool chk[200100];
void dfs(int here, int p) {
	int i, t = -1;
	int x[3] = {-1,-1,-1};
	bool flag = false, ok = true;
	for (i=0;i<lis[here].size();i++) {
		int there = lis[here][i];
		if (there==p) {t=i;continue;}
		flag = true;
		dfs(there,here);
		if (kind[there]!=1) {
			ok = false;
			continue;
		}
		for (int j=0;j<3;j++) {
			if (x[j]==-1||x[j]==ldep[there][0]+1) {
				x[j] = ldep[there][0]+1;
				break;
			}
		}
	}
	if (!flag) {
		ldep[here][0] = 0;
		kind[here] = 1;
	}
	else if (!ok) {
		kind[here] = -1;
	}
	else if (x[2]==-1) {
		if (x[1]==-1) kind[here] = 1;
		else kind[here] = 2;
		ldep[here][0] = x[0];
		ldep[here][1] = x[1];
	}
	else {
		kind[here] = -1;
	}
	if (~t) lis[here].erase(lis[here].begin()+t);
}

int res = -1;
int ans = -1;
void dfs2(int here, int dis) {
	int i, cnt = 0, wh = -1, p = -1, bnt = 0, nnt = 0;
	if (kind[here]==1) {
		res = here;
		ans = dis+ldep[here][0];
		return;
	}
	for (i=0;i<lis[here].size();i++) {
		int there = lis[here][i];
		if (kind[there]!=1) {
			cnt++, wh = there;
		}
		else if (ldep[there][0]+1!=dis) {
			bnt++;
			if (p==-1) p = ldep[there][0]+1;
			else if (p!=ldep[there][0]+1) nnt++;
		}
	}
	if (cnt==0) {
		if (bnt==0) {
			res = here;
			ans = dis;
			return;
		}
		else {
			if (nnt==0) {
				res = here;
				ans = dis+p;
			}
			return;
		}
	}
	if (cnt>=2) return;
	dfs2(wh,dis+1);
}

int deg[200100];
int main() {
	int i;

	scanf("%d",&n);
	for (i=0;i<n-1;i++) {
		int a, b;
		scanf("%d%d",&a,&b);
		--a;--b;
		lis[a].push_back(b);
		lis[b].push_back(a);
		deg[a]++;deg[b]++;
	}
	for (i=0;i<n;i++) {
		if (deg[i]==1) {
			dfs(i,-1);
			dfs2(i,0);
			break;
		}
	}
	if (~res) {
		while(ans%2==0) ans/=2;
		printf("%d\n",ans);
	}
	else printf("-1\n");

	return 0;
}