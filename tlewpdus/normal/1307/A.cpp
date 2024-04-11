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

int main() {
	int ttt;

	scanf("%d",&ttt);
	while(ttt--) {
		int d;
		scanf("%d%d",&n,&d);
		for (int i=0;i<n;i++) scanf("%d",&arr[i]);
		int sum = arr[0];
		for (int i=1;i<n;i++) {
			if (d>=arr[i]*i) {
				d-=arr[i]*i;
				sum+=arr[i];
			}
			else {
				sum += d/i;
				break;
			}
		}
		printf("%d\n",sum);
	}

	return 0;
}