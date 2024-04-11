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

vector<pii> ans;
void calc(int M) {
	for (int i=0;i<M/3+1;i++) {
		ans.emplace_back(i,i*2);
	}
	for (int i=M/3+1;i<M/3*2+1;i++) {
		ans.emplace_back(i,(i-M/3)*2-1);
	}
}

int main() {
	scanf("%d",&N);
	if (N%3==2) {
		calc(N);
	}
	else if (N%3==1) {
		calc(N+1);
	}
	else {
		calc(N-1);
		ans.emplace_back(N-1,N-1);
	}
	printf("%d\n",ans.size());
	for (pii &v: ans) {
		printf("%d %d\n",v.first+1,v.second+1);
	}
//	for (int i=0;i<N;i++) {
//		for (int j=0;j<N;j++) {
//			int good = false;
//			for (pii &v: ans) {
//				if (v.first==i||v.second==j||v.first-v.second==i-j) {
//					good=true;
//					break;
//				}
//			}
//			if (!good) {
//				puts("MANG");
//				return 0;
//			}
//		}
//	}

	return 0;
}