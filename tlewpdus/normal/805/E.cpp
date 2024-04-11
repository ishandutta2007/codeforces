#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>

using namespace std;

vector<int> lis[300100];
vector<int> ice[300100];
int col[300100];
bool chk[300100];
int n, m;

void dfs(int here, int p) {
	int i, j = 1;
	for (i=0;i<ice[here].size();i++) {
		if (col[ice[here][i]]) chk[col[ice[here][i]]] = true;
	}
	for (i=0;i<ice[here].size();i++) {
		if (col[ice[here][i]]) continue;
		for (;chk[j];j++);
		col[ice[here][i]] = j;
		chk[j] = true;
	}
	for (i=0;i<ice[here].size();i++) chk[col[ice[here][i]]] = false;
	for (i=0;i<lis[here].size();i++) {
		int there = lis[here][i];
		if (there==p)continue;
		dfs(there,here);
	}
}

int main() {
	int i, j, maxi = 1;
	scanf("%d%d",&n,&m);
	for (i=0;i<n;i++) {
		int s;
		scanf("%d",&s);
		maxi = max(maxi,s);
		for (j=0;j<s;j++) {
			int a;
			scanf("%d",&a);
			ice[i].push_back(a);
		}
	}
	for (i=0;i<n-1;i++) {
		int a, b;
		scanf("%d%d",&a,&b);
		a--;b--;
		lis[a].push_back(b);
		lis[b].push_back(a);
	}
	dfs(0,-1);
	printf("%d\n",maxi);
	for (i=1;i<=m;i++) {
		printf("%d ",((col[i])?(col[i]):1));
	}
	printf("\n");

	return 0;
}