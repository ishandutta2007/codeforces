#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N, M;
int A[100100];

int main() {
	int TT;

	scanf("%d",&TT);
	while(TT--) {
		scanf("%d%d",&N,&M);
		for (int i=0;i<M;i++) {
			scanf("%d",&A[i]);
		}
		sort(A,A+M);
		vector<int> L;
		for (int i=0;i<M;i++) {
			if (i<M-1) {
				if (A[i+1]-A[i]-1>0) {
					L.push_back(A[i+1]-A[i]-1);
				}
			}
			else {
				if (A[0]-A[i]+N-1>0) {
					L.push_back(A[0]-A[i]+N-1);
				}
			}
		}
		sort(L.begin(),L.end());
		reverse(L.begin(),L.end());
		int num = 0;
		int ans = 0;
		for (int i=0;i<L.size();i++) {
			int l = L[i]-num*2;
			if (l>2) {
				num+=2;
				ans += l-1;
			}
			else if (l>0) {
				num++;
				ans++;
			}
		}
		printf("%d\n",N-ans);
	}

	return 0;
}