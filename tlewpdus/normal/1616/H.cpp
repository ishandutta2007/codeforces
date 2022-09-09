#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N, X;
int A[160000];
ll po[160000];

ll dnc(int s1, int e1, int s2, int e2, int b) {
	if (b==-1) return (po[e1-s1]-1)*(po[e2-s2]-1)%MOD;
	if (s1==e1 || s2==e2) return 0;
	int t1=e1, t2=e2;
	for (int i=s1;i<e1;i++) {
		if (A[i]>>b&1) {t1 = i; break;}
	}
	for (int i=s2;i<e2;i++) {
		if (A[i]>>b&1) {t2=i; break;}
	}
	if (X>>b&1) {
		ll ans = 0;
		ll v1 = dnc(s1,t1,t2,e2,b-1);
		ll v2 = dnc(t1,e1,s2,t2,b-1);
		ans += ((po[t1-s1]-1)*(po[t2-s2]-1)+(po[e1-t1]-1)*(po[e2-t2]-1))%MOD;
		ans += v1*(po[t2-s2]+po[e1-t1]-1)%MOD;
		ans += v2*(po[t1-s1]+po[e2-t2]-1)%MOD;
		ans += v1*v2%MOD;
		return ans%MOD;
	}
	return (dnc(s1,t1,s2,t2,b-1)+dnc(t1,e1,t2,e2,b-1))%MOD;
}

int main() {
	scanf("%d%d",&N,&X);
	for (int i=0;i<N;i++) scanf("%d",&A[i]);
	po[0] = 1;
	for (int i=1;i<=N;i++) po[i] = po[i-1]*2%MOD;
	sort(A,A+N);
	if (X==0) {
		int p =0;
		ll ans = 0;
		for (int i=0;i<N;i++) {
			if (i==N-1||A[i]!=A[i+1]) {
				ans += po[i-p+1]-1;
				p = i+1;
			}
		}
		printf("%lld\n",ans%MOD);
		return 0;
	}
	for (int i=29;i>=0;i--) {
		if (X>>i&1) {
			vector<int> cuts;
			cuts.push_back(0);
			for (int j=0;j<N;j++) {
				if (j==N-1 || (A[j]>>(i+1))!=(A[j+1]>>(i+1))) {
					cuts.push_back(j+1);
				}
			}
			ll ans = 0;
			for (int j=1;j<cuts.size();j++) {
				int s=cuts[j-1], e=cuts[j];
				int cut = e;
				for (int k=s;k<e;k++) {
					if (A[k]>>i&1) {
						cut=k;
						break;
					}
				}
				ans += dnc(s,cut,cut,e,i-1)+(po[cut-s]-1)+(po[e-cut]-1);
			}
			printf("%lld\n",ans%MOD);
			break;
		}
	}

	return 0;
}