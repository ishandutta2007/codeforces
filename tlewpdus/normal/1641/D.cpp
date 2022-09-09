#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1000000007;

int N, M;
int tA[100100][5], A[100100][5];
int tW[100100], W[100100];
int C[500100];

const int SQ = 800;

int bigi[500100];
vector<int> biglist;
bitset<100100> bigs[1000];
int ord[100100];

bool test(int i, int j) {
	int k=0, l=0;
//	printf("%d %d\n",i,j);
	while(k<M&&l<M) {
		if (A[i][k]==A[j][l]) return false;
		if (A[i][k]<A[j][l]) k++;
		else l++;
	}
//	printf("!!\n");
	return true;
}

bitset<100100> tmp;
int main() {
	scanf("%d%d",&N,&M);
	vector<int> comp;
	for (int i=0;i<N;i++) {
		for (int j=0;j<M;j++) {
			scanf("%d",&tA[i][j]);
			comp.push_back(tA[i][j]);
		}
		scanf("%d",&tW[i]);
	}
	iota(ord,ord+N,0);
	sort(ord, ord+N,[](int a, int b){
		return tW[a]<tW[b];
	});
	for (int i=0;i<N;i++) {
		for (int j=0;j<M;j++) {
			A[i][j] = tA[ord[i]][j];
		}
		sort(A[i],A[i]+M);
		W[i] = tW[ord[i]];
	}
	sort(comp.begin(),comp.end());
	comp.erase(unique(comp.begin(),comp.end()), comp.end());
	for (int i=0;i<N;i++) {
		for (int j=0;j<M;j++) {
			A[i][j] = lower_bound(comp.begin(),comp.end(), A[i][j])-comp.begin();
			C[A[i][j]]++;
		}
	}
	memset(bigi,-1,sizeof(bigi));
	for (int i=0;i<comp.size();i++) {
		if (C[i]>=SQ) {
			bigi[i] = biglist.size();
			biglist.push_back(i);
		}
		if (C[i]==N) {
			puts("-1");
			return 0;
		}
	}
	for (int i=0;i<N;i++) {
		for (int j=0;j<M;j++) {
			if (C[A[i][j]]>=SQ) {
				bigs[bigi[A[i][j]]].set(i);
			}
		}
	}
	for (int i=0;i<biglist.size();i++) {
		bigs[i].flip();
	}
	int ans = 2*INF;
	for (int i=0;i<N;i++) {
		int c = 0;
		for (int j=0;j<M;j++) {
			if (C[A[i][j]]>=SQ) {
				c++;
			}
		}
		if (c==0) {
			for (int j=i+1;j<N;j++) {
				if (W[i]+W[j]>=ans) break;
				if (test(i,j)) {
					ans = min(ans,W[i]+W[j]);
					break;
				}
			}
		}
		else {
			tmp.set();
			for (int j=0;j<M;j++) {
				if (C[A[i][j]]>=SQ) {
					tmp = (tmp&bigs[bigi[A[i][j]]]);
				}
			}
			int idx = tmp._Find_next(i);
			while(idx<N && W[i]+W[idx]<ans) {
				if (test(i,idx)) {
					ans = min(ans,W[i]+W[idx]);
					break;
				}
				idx = tmp._Find_next(idx);
			}
		}
	}
	if (ans == 2*INF) puts("-1");
	else printf("%d\n",ans);

	return 0;
}