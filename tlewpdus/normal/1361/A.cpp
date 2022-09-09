#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int n, m;
vector<int> lis[500100];
int t[500100];

void pung() {
	puts("-1");
	exit(0);
}

int chk[500100];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		int a, b;
		scanf("%d%d",&a,&b); --a; --b;
		lis[a].push_back(b);
		lis[b].push_back(a);
	}
	for (int i=0;i<n;i++) {
		scanf("%d",&t[i]); t[i]--;
	}
	for (int i=0;i<n;i++) {
		for (int &j : lis[i]) {
			if (t[i]==t[j]) pung();
		}
		for (int &j : lis[i]) {
			chk[t[j]] = 1;
		}
		for (int j=0;j<t[i];j++) {
			if (!chk[j]) pung();
		}
		for (int &j : lis[i]) {
			chk[t[j]] = 0;
		}
	}
	iota(chk,chk+n,0);
	sort(chk,chk+n,[](int a, int b){return t[a]<t[b];});
	for (int i=0;i<n;i++) {
		printf("%d ",chk[i]+1);
	}puts("");

	return 0;
}