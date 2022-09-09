#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353; //1000000007

int N;
pii A[200100];
int C[200100];
int T[200100];
int P[200100];

void pung() {
	puts("-1");
	exit(0);
}

int main() {
	scanf("%d",&N);
	for (int i=0;i<N;i++) {
		scanf("%d%d",&A[i].first,&A[i].second); A[i].first--; A[i].second--;
		if (A[i].first>A[i].second) {
			swap(A[i].first,A[i].second);
			C[A[i].first] = 1;
		}
		if (A[i].first>=N||A[i].second<N) pung();
		P[A[i].first] = A[i].second-N;
	}
	int mini = N+10;
	for (int i=0;i<N;i++) {
		if (mini<P[i]) T[i] = 1;
		mini = min(mini,P[i]);
	}
	int maxi = -1;
	for (int i=N-1;i>=0;i--) {
		if (P[i]<maxi) {
			if (T[i]==1) pung();
			T[i] = -1;
		}
		maxi = max(maxi,P[i]);
	}
	vector<int> U, L;
	for (int i=0;i<N;i++) {
		if (T[i]==1) U.push_back(i);
		else if (T[i]==-1) L.push_back(i);
	}
	int s=0, e=0;
	if (L.empty()) {
		puts("0");
		exit(0);
	}
	while(e<U.size()&&P[L[0]]<P[U[e]]) e++;
	int ps = s, pe = e, pi = 0, ans = 0;
	auto calc = [&](int si, int ei, int sj, int ej) {
		int i0=0, j1=0;
		for (int i=si;i<ei;i++) {
			if (C[L[i]]==0) i0++;
		}
		for (int j=sj;j<ej;j++) {
			if (C[U[j]]==1) j1++;
		}
		return min(i0+j1,ei-si-i0+ej-sj-j1);
	};
	for (int i=1;i<L.size();i++) {
		while(s<U.size()&&L[i]>U[s]) s++;
		while(e<U.size()&&P[L[i]]<P[U[e]]) e++;
		if (pe<=s) {
			ans += calc(pi,i,ps,pe);
			ps = s, pe = e;
			pi = i;
		}
		else {
			pe = max(pe,e);
		}
	}
	ans += calc(pi,L.size(),ps,pe);
	printf("%d\n",ans);

	return 0;
}