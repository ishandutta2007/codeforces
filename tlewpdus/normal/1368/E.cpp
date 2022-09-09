#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,pii> piii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

int n, m;
vector<int> ans;
int dead[200100];
int pre[200100];
vector<int> lis[200100];

int main(){
	int t;

	scanf("%d",&t);
	while(t--) {
		ans.clear();
		scanf("%d%d",&n,&m);
		for (int i=0;i<n;i++) pre[i] = dead[i] = 0;
		for (int i=0;i<m;i++) {
			int a, b;
			scanf("%d%d",&a,&b); --a; --b;
			lis[a].push_back(b);
		}
		for (int i=0;i<n;i++) {
			if (dead[i]) {
				ans.push_back(i);
				continue;
			}
			if (pre[i]) {
				for (int &v : lis[i]) dead[v] = 1;
			}
			for (int &v : lis[i]) pre[v]++;
		}
		printf("%d\n",ans.size());
		for (int &v : ans) printf("%d ",v+1);
		puts("");
		for (int i=0;i<n;i++) lis[i].clear();
	}

	return 0;
}