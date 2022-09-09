#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1000000007; //998244353

int N;
char str[300100];

int main() {
	int t;

	scanf("%d",&t);
	while(t--){
		scanf("%s",str);
		N = strlen(str);
		int rem = 0, rb = 0, ans = 0;
		for (int i=0;i<N;i++) {
			if (str[i]=='A') {
				rem++;
			}
			else {
				if (rem>0) {
					rem--;
					ans+=2;
				}
				else {
					rb++;
				}
			}
		}
		printf("%d\n",N-(rb/2*2+ans));
	}

	return 0;
}