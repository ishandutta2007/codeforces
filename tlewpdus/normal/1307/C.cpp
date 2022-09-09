#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;

int n;
int arr[200100];
char str[200100];

ll cnt[30], cnt2[30][30];

int main() {

	scanf("%s",str);
	n = strlen(str);
	for (int i=0;i<n;i++) {
		for (int j=0;j<26;j++) cnt2[j][str[i]-'a'] += cnt[j];
		cnt[str[i]-'a']++;
	}
	ll maxi = 0, t = 0, maxi2 = 0, a2 = 0, b2 = 0;
	for (int i=0;i<26;i++) {
		if (maxi<cnt[i]) {
			maxi=cnt[i];
			t = i;
		}
	}
	for (int i=0;i<26;i++) {
		for (int j=0;j<26;j++) {
			if (maxi2<cnt2[i][j]) {
				maxi2=cnt2[i][j];
				a2=i;b2=j;
			}
		}
	}
	printf("%lld\n",max(maxi,maxi2));

	return 0;
}