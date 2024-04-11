#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n;
vector<int> lis[100100];
int dep[100100];

void dfs(int here, int p) {
	dep[here] = (~p?dep[p]:-1)+1;
	for (int &there : lis[here]) {
		if (there!=p) dfs(there,here);
	}
}

int main() {
	scanf("%d",&n);
	for (int i=0;i<n-1;i++) {
		int a, b;
		scanf("%d%d",&a,&b);a-- ;b--;
		lis[a].push_back(b);
		lis[b].push_back(a);
	}
	int rt = 0;
	for (int i=0;i<n;i++) {
		if (lis[i].size()!=1) {
			rt = i;
			break;
		}
	}
	dfs(rt,-1);
	int c[2] = {0,0};
	for (int i=0;i<n;i++) {
		if (lis[i].size()==1) {
			c[dep[i]%2] = 1;
		}
	}
	if (c[0]&&c[1]) {
		printf("3 ");
	}
	else printf("1 ");
	int m = n-1;
	for (int i=0;i<n;i++) {
		if (lis[i].size()==1) continue;
		int c = 0;
		for (int &j : lis[i]) {
			if (lis[j].size()==1) c++;
		}
		m -= max(c-1,0);
	}
	printf("%d\n",m);

	return 0;
}