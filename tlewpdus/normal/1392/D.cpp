#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

int n;
char str[200100];
ll D[200100][4];

char pat[4][3] = {"LL","LR","RL","RR"};

int main() {
	int tt;

	scanf("%d",&tt);
	while(tt--) {
		scanf("%d",&n);
		scanf(" %s",str);
		ll mini = LINF;
		for (int t=0;t<4;t++) {
			int sco = 0;
			for (int i=0;i<2;i++) sco += (pat[t][i]!=str[i]);
			for (int j=0;j<4;j++) {
				if (t==j) D[1][j] = sco;
				else D[1][j] = LINF;
			}
			for (int i=2;i<n;i++) {
				D[i][0] = D[i-1][2] + (str[i]=='R');
				D[i][1] = min(D[i-1][0],D[i-1][2]) + (str[i]=='L');
				D[i][2] = min(D[i-1][1],D[i-1][3]) + (str[i]=='R');
				D[i][3] = D[i-1][1] + (str[i]=='L');
			}
			if (t==0) mini = min({mini,D[n-1][1],D[n-1][3]});
			else if (t==1) mini = min({mini,D[n-1][1],D[n-1][2],D[n-1][3]});
			else if (t==2) mini = min({mini,D[n-1][1],D[n-1][2],D[n-1][0]});
			else if (t==3) mini = min({mini,D[n-1][0],D[n-1][2]});
		}
		printf("%lld\n",mini);
	}

	return 0;
}