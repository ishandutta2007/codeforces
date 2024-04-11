#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

int n;
vector<int> lis[200100];
int cnt[2] = {0,0};

void dfs(int here, int p, int c) {
	cnt[c]++;
	for (int &there : lis[here]) {
		if (there!=p) dfs(there,here,c^1);
	}
}

int main(){
	scanf("%d",&n);
	for (int i=0;i<n-1;i++) {
		int a, b;
		scanf("%d%d",&a,&b); --a; --b;
		lis[a].push_back(b);
		lis[b].push_back(a);
	}
	dfs(0,-1,0);
	printf("%d\n",min(cnt[0],cnt[1])-1);

	return 0;
}