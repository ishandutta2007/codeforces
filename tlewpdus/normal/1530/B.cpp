#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

char str[22][22];

int main() {
	int tt;

	scanf("%d",&tt);
	while(tt--) {
		int a, b;
		scanf("%d%d",&a,&b);
		for (int i=0;i<a;i++) {
			for (int j=0;j<b;j++) str[i][j] = '0';
			str[i][b] = 0;
		}
		for (int i=0;i<=a-3;i+=2) {
			str[i][0] = str[i][b-1] = '1';
		}
		str[a-1][0] = str[a-1][b-1] = '1';
		for (int j=0;j<=b-3;j+=2) {
			str[0][j] = str[a-1][j] = '1';
		}
		for (int i=0;i<a;i++) {
			printf("%s\n",str[i]);
		}
	}

	return 0;
}