#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int n;
int arr[100100];
int loc[100100];
int chk[100100];

int main() {
	int t;

	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&arr[i]), loc[arr[i]] = i;
		for (int i=1;i<=n;i++) chk[i] = 0;
		int i = 1, mini = n+1;
		int mang = 0;
		while(i<=n) {
			int cnt = mini-loc[i];
			for (int j=0;j<cnt;j++) {
				if (i+j>n||loc[i+j]!=loc[i]+j) mang = 1;
			}
			if (mang) break;
			mini = loc[i];
			i += cnt;
		}
		puts(mang?"NO":"YES");
	}

	return 0;
}