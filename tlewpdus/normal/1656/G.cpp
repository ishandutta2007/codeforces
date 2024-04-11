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
int A[200100];
int cnt[200100];
int P[200100];
int pr[200100];
int ans[200100];

int main() {
	int T;

	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		for (int i=0;i<N;i++) {
			scanf("%d",&A[i]);
			A[i]--;
		}
		{
			for (int i=0;i<N;i++) cnt[i] = 0;
			for (int i=0;i<N;i++) cnt[A[i]]++;
			int c = 0;
			for (int i=0;i<N;i++) if (cnt[i]%2) c++;
			if (c>1) {
				puts("NO");
				continue;
			}
		}
		iota(P,P+N,0);
		if (N%2==1) {
			int d = 0;
			for (int i=0;i<N;i++) {
				if (cnt[i]%2) d = i;
			}
			int e = -1;
			for (int i=0;i<N;i++) {
				if (A[i]==d && i!=N/2) {
					e = i;
					break;
				}
			}
			if (e==-1) {
				puts("NO");
				continue;
			}
			A[e] = N;
			ans[N/2] = e;
			P[e] = N/2;
			swap(A[e],A[N/2]);
		}
		for (int i=0;i<N;i++) cnt[i] = -1;
		for (int i=0;i<N;i++) {
			if (N%2==1 && i==N/2) continue;
			if (cnt[A[i]]==-1) cnt[A[i]] = i;
			else {
				pr[cnt[A[i]]] = i;
				pr[i] = cnt[A[i]];
				cnt[A[i]] = -1;
			}
		}
		for (int i=0;i<N;i++) {
//			printf("%d: %d\n",i,pr[i]);
		}
		for (int i=0;i<N/2;) {
			int l = i;
			int r = N-1-i;
			while(l<N/2 && pr[l]==r) {
				l++; r--;
			}
			if (l==N/2) {
				l--; r++;
			}
			for (int j=i+1;j<=l;j++) {
				ans[j] = P[j-1];
			}
			for (int j=r;j<N-1-i;j++) {
				ans[j] = P[j+1];
			}
			ans[i] = P[pr[l]];
			ans[N-1-i] = P[l];
//			swap(A[pr[l]],A[r]);
			P[pr[l]] = P[r];
			pr[pr[r]] = pr[l];
			pr[pr[l]] = pr[r];
			i = l+1;
		}
		puts("YES");
		for (int i=0;i<N;i++) printf("%d ",ans[i]+1);
		puts("");
	}

	return 0;
}