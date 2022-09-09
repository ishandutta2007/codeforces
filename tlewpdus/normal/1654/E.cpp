#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N;
int A[100100];

const int SQ = 400;

int cnt[61000100];

int main() {
	scanf("%d",&N);
	for (int i=0;i<N;i++) scanf("%d",&A[i]);
	if (N==1) {
		puts("0");
		return 0;
	}
	int ans = 0;
	for (int s=-SQ;s<=SQ;s++) {
		int BIAS = 0;
		if (s<=0) {
			BIAS = 0;
		}
		else {
			BIAS = s*N;
		}
		for (int i=0;i<N;i++) {
			cnt[A[i]-s*i+BIAS]++;
		}
		for (int i=0;i<N;i++) {
			ans = max(ans, cnt[A[i]-s*i+BIAS]);
			cnt[A[i]-s*i+BIAS]--;
		}
	}
	for (int i=0;i<N;i++) {
		int BIAS = 200000;
		for (int j=i-1;j>=0&&j>i-SQ;j--) {
			if ((A[j]-A[i])%(i-j)==0) {
				int slope = (A[j]-A[i])/(i-j);
				cnt[slope+BIAS]++;
			}
		}
		for (int j=i-1;j>=0&&j>i-SQ;j--) {
			if ((A[j]-A[i])%(i-j)==0) {
				int slope = (A[j]-A[i])/(i-j);
				ans = max(ans,cnt[slope+BIAS]+1);
				cnt[slope+BIAS]--;
			}
		}
	}
	printf("%d\n",N-ans);

	return 0;
}