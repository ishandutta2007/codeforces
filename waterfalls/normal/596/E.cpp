#include <bits/stdc++.h>
using namespace std;

int n,m,q;
char buff[1000013];
int table[213*213];
int a[10], b[10];

int p[213*213];
int find(int x) { return p[x]==x ? x : p[x]=find(p[x]); }
void merge(int x, int y) { p[find(x)] = find(y); }

int to[213*213];
vector<int> adj[213*213];
vector<int> all[213*213];
int which[213*213];
bool on[213*213];
vector<vector<int> > has;
vector<vector<int> > conn;

void dfs(int x, int s) {
	has.back()[table[x]] = 1;
	on[x] = 1;
	if (x==s) return;
	dfs(to[x],s);
}
void dfsall(int x, int w) {
	which[x] = w;
	for (int i: all[x]) if (which[i]==-1) dfsall(i,w);
}

void another() {
	has.push_back(vector<int>(10));
	conn.push_back(vector<int>());
}
void make() {
	for (int i=0;i<n;i++) p[i] = i, which[i] = -1;
	for (int i=0;i<n;i++) {
		int nX = i/m+a[table[i]];
		int nY = i%m+b[table[i]];
		if (nX<0 || nX>=n/m || nY<0 || nY>=m) to[i] = i;
		else to[i] = nX*m+nY;
		all[i].push_back(to[i]);
		all[to[i]].push_back(i);
	}
	for (int i=0;i<n;i++) {
		if (i==to[i]) {
			another();
			has.back()[table[i]] = 1;
			on[i] = 1;
			dfsall(i,has.size()-1);
		} else if (find(i)==find(to[i])) {
			another();
			dfs(to[i],i);
			dfsall(i,has.size()-1);
		}
		merge(i,to[i]);
	}
	for (int i=0;i<n;i++) if (!on[i]) {
		if (on[to[i]]) conn[which[i]].push_back(i);
		else adj[to[i]].push_back(i);
	}
}

string s;
int last[10];

bool check(int x, int ind) {
	if (table[x]==s[ind]-'0') ind-=1;
	if (ind==-1) return 1;
	for (int i: adj[x]) if (check(i,ind)) return 1;
	return 0;
}

int main() {
	scanf("%d%d%d",&n,&m,&q);
	for (int i=0;i<n;i++) {
		scanf(" %s",&buff);
		for (int j=0;j<m;j++) table[i*m+j] = buff[j]-'0';
	}
	for (int i=0;i<10;i++) scanf("%d%d",&a[i],&b[i]);
	n*=m;
	make();
	for (int Q=0;Q<q;Q++) {
		scanf(" %s",&buff);
		s = string(buff);
		for (int i=0;i<10;i++) last[i] = -1;
		for (int i=0;i<s.size();i++) last[s[i]-'0'] = i;
		bool found = 0;
		for (int i=0;i<has.size();i++) {
			int ind = -1;
			for (int j=0;j<10;j++) if (last[j]!=-1 && !has[i][j]) ind = max(ind,last[j]);
			if (ind==-1) found = 1;
			else {
				for (int j: conn[i]) if (check(j,ind)) found = 1;
			}
		}
		printf("%s\n",found ? "YES" : "NO");
	}

	return 0;
}