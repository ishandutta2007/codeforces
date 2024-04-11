#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7; //998244353;

int N;
int P[100100];

int main() {
	scanf("%d",&N);
	for (int i=0;i<N;i++) {
		scanf("%d",&P[i]);
	}
	vector<int> loc;
	loc.push_back(0);
	for (int i=1;i+1<N;i++) {
		if ((P[i]<P[i-1]&&P[i]<P[i+1])||(P[i]>P[i-1]&&P[i]>P[i+1])) loc.push_back(i);
	}
	loc.push_back(N-1);
	int maxi = 0, maxc = 0;
	for (int i=1;i<loc.size();i++) {
		int l = loc[i]-loc[i-1];
		if (maxi<l) {
			maxi=l;
			maxc=1;
		}
		else if (maxi==l) {
			maxc++;
		}
	}
	int ans = 0;
	for (int i=1;i+1<loc.size();i++) {
		int j = loc[i];
		if (P[j]<P[j-1]) continue;
		int l1 = loc[i]-loc[i-1];
		int l2 = loc[i+1]-loc[i];
		if (l1!=l2 || l1%2) continue;
		if (l1!=maxi || maxc>=3) continue;
		ans++;
	}
	printf("%d\n",ans);

	return 0;
}