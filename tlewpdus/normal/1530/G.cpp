#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int N, K, pa, pb;
char A[2010], B[2010];
int ZA[2010], ZB[2010];
void rev(char S[], int ZS[], int s, int l, vector<pii> &his) {
	assert(ZS[s]+ZS[s+K]>=l);
	int ts = 0, te = 0;
	for (int i=0;i<=s;i++) ts += ZS[i]+1; ts--;
	for (int i=0;i<s+K;i++) te += ZS[i]+1; te--;
	if (ZS[s]>l) ts -= ZS[s]-l;
	else te += l-ZS[s];
	int c = 0;
	for (int i=ts;i<=te;i++) c += (S[i]-'0');
	assert(c==K);
	his.emplace_back(ts,te);
	reverse(S+ts,S+te+1);
	reverse(ZS+(s+1),ZS+(s+K));
	ZS[s+K] = ZS[s]+ZS[s+K]-l;
	ZS[s] = l;
}

void print(vector<pii> &hisa, vector<pii> &hisb) {
	printf("%u\n",hisa.size()+hisb.size());
	for (pii &e : hisa) printf("%d %d\n",e.first+1,e.second+1);
	reverse(hisb.begin(),hisb.end());
	for (pii &e : hisb) printf("%d %d\n",e.first+1,e.second+1);
}

int main() {
	int tt;

	scanf("%d",&tt);
	while(tt--) {
		scanf("%d%d",&N,&K);
		scanf(" %s",A);
		scanf(" %s",B);
		int a1 = 0, b1 = 0, same = true;
		for (int i=0;i<N;i++) {
			a1 += (A[i]=='1');
			b1 += (B[i]=='1');
			if (A[i]!=B[i]) same = false;
		}
		if (a1!=b1) {
			puts("-1");
			continue;
		}
		if (K==0||K>a1) {
			if (same) puts("0");
			else puts("-1");
			continue;
		}
		pa=pb=0;
		int pst = -1;
		for (int i=0;i<N;i++) {
			if (A[i]=='1') {
				ZA[pa] = i-pst-1;
				pst = i;
				pa++;
			}
		}
		ZA[pa] = N-pst-1; pa++;
		pst = -1;
		for (int i=0;i<N;i++) {
			if (B[i]=='1') {
				ZB[pb] = i-pst-1;
				pst = i;
				pb++;
			}
		}
		ZB[pb] = N-pst-1; pb++;

		vector<pii> hisa;
		vector<pii> hisb;
		if (K==a1) {
			bool good = true;
			for (int i=1;i<pa-1;i++) {
				if (ZA[i]!=ZB[i]) good = false;
			}
			if (good) {
				rev(A,ZA,0,ZB[0],hisa);
				rev(A,ZA,0,ZB[0],hisa);
			}
			else {
				good = true;
				for (int i=1;i<pa-1;i++) {
					if (ZA[i]!=ZB[pa-1-i]) good = false;
				}
				if (good) {
					rev(A,ZA,0,ZB[0],hisa);
				}
				else {
					puts("-1");
					continue;
				}
			}
		}
		else if (K%2==0) {
			for (int i=0;i<=pa-K-2;i++) rev(A,ZA,i,0,hisa);
			rev(A,ZA,pa-K-1,ZA[pa-K-1]+ZA[pa-1],hisa);
			for (int i=0;i<K;i++) {
				if (i%2==0) rev(A,ZA,pa-K-1,0,hisa);
				else rev(A,ZA,pa-K-2,ZA[pa-K-2]+ZA[pa-2],hisa);
			}
			rev(A,ZA,pa-K-2,0,hisa);

			for (int i=0;i<=pa-K-2;i++) rev(B,ZB,i,0,hisb);
			rev(B,ZB,pb-K-1,ZB[pb-K-1]+ZB[pb-1],hisb);
			for (int i=0;i<K;i++) {
				if (i%2==0) rev(B,ZB,pa-K-1,0,hisb);
				else rev(B,ZB,pb-K-2,ZB[pb-K-2]+ZB[pb-2],hisb);
			}
			rev(B,ZB,pb-K-2,0,hisb);

			bool mang = false;
			for (int i=0;i<pa;i++) {
				if (ZA[i]!=ZB[i]) mang = true;
			}
			if (mang) {
				puts("-1");
				continue;
			}
		}
		else {
			for (int i=0;i<=pa-K-2;i++) rev(A,ZA,i,0,hisa);
			rev(A,ZA,pa-K-1,ZA[pa-K-1]+ZA[pa-1],hisa);
			for (int i=0;i<2*K;i++) {
				if (i%2==0) rev(A,ZA,pa-K-1,0,hisa);
				else rev(A,ZA,pa-K-2,0,hisa);
			}

			for (int i=0;i<=pa-K-2;i++) rev(B,ZB,i,0,hisb);
			rev(B,ZB,pb-K-1,ZB[pb-K-1]+ZB[pb-1],hisb);
			for (int i=0;i<2*K;i++) {
				if (i%2==0) rev(B,ZB,pa-K-1,0,hisb);
				else rev(B,ZB,pb-K-2,0,hisb);
			}

			bool mang = false;
			for (int i=0;i<pa;i++) {
				if (ZA[i]!=ZB[i]) mang = true;
			}
			if (mang) {
				puts("-1");
				continue;
			}
		}
		print(hisa,hisb);
	}

	return 0;
}