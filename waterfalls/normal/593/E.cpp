#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

vector<vector<int> > mult(vector<vector<int> > A, vector<vector<int> > B) {
	vector<vector<int> > ans(A.size(),vector<int>(B[0].size()));
	for (int i=0;i<A.size();i++) for (int j=0;j<B[0].size();j++) {
		for (int k=0;k<A[0].size();k++) ans[i][j] = (ans[i][j]+(ll) A[i][k]*B[k][j])%MOD;
	}
	return ans;
}

vector<vector<int> > pow(vector<vector<int> > cur, int p) {
	vector<vector<int> > ans(cur.size(),vector<int>(cur.size()));
	for (int i=0;i<cur.size();i++) ans[i][i] = 1;
	while (p) {
		if (p%2) ans = mult(ans,cur);
		cur = mult(cur,cur);
		p/=2;
	}
	return ans;
}

int n,m,q;
bool bad[20][20];
vector<vector<int> > cur;
vector<vector<int> > adj;

void makeAdj() {
	adj = vector<vector<int> >(n*m,vector<int>(n*m));
	for (int i=0;i<n*m;i++) if (!bad[i/m][i%m]) {
		adj[i][i] = 1;
		if (i/m>0 && !bad[i/m-1][i%m]) adj[i][i-m] = 1;
		if (i/m<n-1 && !bad[i/m+1][i%m]) adj[i][i+m] = 1;
		if (i%m>0 && !bad[i/m][i%m-1]) adj[i][i-1] = 1;
		if (i%m<m-1 && !bad[i/m][i%m+1]) adj[i][i+1] = 1;
	}
}

int main() {
	scanf("%d%d%d",&n,&m,&q);
	cur = vector<vector<int> >(1,vector<int>(n*m));
	cur[0][0] = 1;
	int prevT = 1;
	for (int Q=0;Q<q;Q++) {
		int type,x,y,t;
		scanf("%d%d%d%d",&type,&x,&y,&t);
		x-=1; y-=1;
		makeAdj();
		cur = mult(cur,pow(adj,t-prevT));
		if (type==1) printf("%d\n",cur[0][x*m+y]);
		else bad[x][y]^=1;
		prevT = t;
	}

	return 0;
}