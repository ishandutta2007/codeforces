#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1000000007;

int N;
int A[20];

bool bt(int idx, int sum, int cnt) {
	if (idx==N) {
		if (sum==0&&cnt>0) return true;
		return false;
	}
	if (bt(idx+1,sum+A[idx],cnt+1)) return true;
	if (bt(idx+1,sum-A[idx],cnt+1)) return true;
	if (bt(idx+1,sum,cnt)) return true;
	return false;
}

int main() {
	int tt;

	scanf("%d",&tt);
	while(tt--) {
		scanf("%d",&N);
		for (int i=0;i<N;i++) scanf("%d",&A[i]);
		if (bt(0,0,0)) puts("YES");
		else puts("NO");
	}

	return 0;
}