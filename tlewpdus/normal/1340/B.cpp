#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

char dig[10][8] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int onc[10];
int n, k;
int D[2010][2010];
vector<pii> cost[2010];

int main() {
	scanf("%d%d",&n,&k);
	for (int j=0;j<10;j++) for (int k=0;k<7;k++) onc[j] += (dig[j][k]=='1');
	for (int i=0;i<n;i++) {
		char buf[10];
		scanf(" %s",buf);
		int cnt = 0;
		for (int k=0;k<7;k++) cnt += (buf[k]=='1');
		for (int j=0;j<10;j++) {
			int bad = 0;
			for (int k=0;k<7;k++) {
				if (dig[j][k]=='0'&&buf[k]=='1') bad = 1;
			}
			if (bad) continue;
			cost[i].push_back({onc[j]-cnt,j});
		}
		reverse(cost[i].begin(),cost[i].end());
	}
	D[n][0] = 1;
	for (int i=n-1;i>=0;i--) {
		for (int j=0;j<=k;j++) {
			for (pii &v : cost[i]) {
				if (j>=v.first&&D[i+1][j-v.first]) D[i][j] = 1;
			}
		}
	}
	if (!D[0][k]) {
		puts("-1");
		return 0;
	}
	int i = 0, j = k;
	while(i<n) {
		for (pii &v : cost[i]) {
			if (j>=v.first&&D[i+1][j-v.first]) {
				printf("%d",v.second);
				i++;
				j-=v.first;
				break;
			}
		}
	}
	puts("");

	return 0;
}