#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int D[1030];
int getv(int bit) {
	vector<int> dig;
	for (int i=0;i<10;i++) {
		dig.push_back(bit%2);
		bit/=2;
	}
	int as = 0, bs = 0;
	for (int i=0;i<dig.size();i++) {
		if (i%2==0) {
			as += dig[i];
		}
		else {
			bs += dig[i];
		}
		if (as+(4-i/2)<bs) return i+1;
		if (bs+(5-(i+1)/2)<as) return i+1;
	}
	return 10;
}

int main() {
	int tt;
	scanf("%d",&tt);
	for (int i=0;i<(1<<10);i++) D[i] = getv(i);
	while(tt--) {
		char s[20];
		scanf(" %s",s);
		int ans = INF;
		for (int i=0;i<(1<<10);i++) {
			bool good = true;
			for (int j=0;j<10;j++) {
				if (i>>j&1) {
					if (s[j]=='0') good = false;
				}
				else {
					if (s[j]=='1') good = false;
				}
			}
			if (good) {
				ans = min(ans,D[i]);
			}
		}
		printf("%d\n",ans);

	}

	return 0;
}