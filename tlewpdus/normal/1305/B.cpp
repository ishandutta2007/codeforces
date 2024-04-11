#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int n;
char str[1010];
int psum[1010];

int main() {
	scanf("%s",str+1);
	n = strlen(str+1);
	int fl = 0, bad = 0;
	for (int i=1;i<=n;i++) {
		if (str[i]=='(') fl = 1;
		if (fl&&str[i]==')') bad = 1;
	}
	if (!bad) {
		puts("0");
		return 0;
	}
	for (int i=1;i<=n;i++) {
		psum[i] = psum[i-1]+(str[i]=='(');
	}
	int sum = 0;
	for (int i=n;i>1;i--) {
		sum += (str[i]==')');
		if (sum==psum[i-1]) {
			printf("1\n");
			vector<int> loc;
			for (int j=1;j<i;j++) if (str[j]=='(') loc.push_back(j);
			for (int j=i;j<=n;j++) if (str[j]==')') loc.push_back(j);
			printf("%d\n",loc.size());
			for (int &v: loc) printf("%d ",v);puts("");
			return 0;
		}
	}
	puts("0");

	return 0;
}