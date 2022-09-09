#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

int n, k;
char str[301000];

int main() {
	int tt;

	scanf("%d",&tt);
	while(tt--) {
		scanf("%d%d",&n,&k);
		scanf(" %s",str);
		int mang = 0, sum[2] = {0,0};
		for (int i=0;i<k;i++) {
			int cnt[2] = {0,0};
			for (int j=i;j<n;j+=k) {
				if (str[j]=='0') cnt[0]++;
				else if (str[j]=='1') cnt[1]++;
			}
			if (cnt[0]&&cnt[1]) {
				mang = 1;
				break;
			}
			if (cnt[0]) {
				sum[0]++;
			}
			else if (cnt[1]) {
				sum[1]++;
			}
			else {
				str[i] = '?';
			}
		}
		if (mang || sum[0]>k/2||sum[1]>k/2) {
			puts("NO");
		}
		else {
			puts("YES");
		}
	}

	return 0;
}