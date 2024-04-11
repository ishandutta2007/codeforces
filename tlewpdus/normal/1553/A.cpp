#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int N;

int main() {
	int tt;
	scanf("%d",&tt);
	while(tt--) {
		scanf("%d",&N);
		printf("%d\n",(N+1)/10);
	}

	return 0;
}