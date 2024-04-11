#include <bits/stdc++.h>
using namespace std;

int p,q,r;
vector<int> adj[1000013], jda[1000013];
bool on[1000013];

int id(int a, int b, int c) {
	return a*q*r+b*r+c;
}
void conn(int a, int b) {
	adj[a].push_back(b);
	jda[b].push_back(a);
}

bool dfs(int x, int s, int g, int d=0) {
	if (x==g || !on[x]) return false;
	if (x==s) return true;
	if (d>1) return false;
	for (int i: adj[x]) {
		if (dfs(i,s,g,d+1)) return true;
	}
	return false;
}

bool check(int x) {
	for (int i: jda[x]) {
		for (int j: adj[x]) {
			if (!on[i] || !on[j] || !on[x]) continue;
			if (!dfs(i,j,x)) return true;
		}
	}
	return false;
}

int main() {
	scanf("%d%d%d",&p,&q,&r);
	for (int i=0;i<p;i++) {
		for (int j=0;j<q;j++) {
			for (int k=0;k<r;k++) {
				char c;
				scanf(" %c",&c);
				on[id(i,j,k)] = (c=='1');
				if (i<p-1) conn(id(i,j,k),id(i+1,j,k));
				if (j<q-1) conn(id(i,j,k),id(i,j+1,k));
				if (k<r-1) conn(id(i,j,k),id(i,j,k+1));
			}
		}
	}
	int ans = 0;
	for (int i=0;i<p*q*r;i++) ans+=check(i);
	printf("%d\n",ans);

	return 0;
}