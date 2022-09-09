#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353; //1000000007

int N;
int A[300100], R[300100];
int loc[300100];
vector<int> lis[300100];
int par[300100];
int dep[300100];


void pung() {
	puts("NO");
	exit(0);
}

void idfs(int here) {
	for (int &there : lis[here]) {
		dep[there] = dep[here]+1;
		idfs(there);
	}
}

int cmin[300100];
void ddfs(int here) {
	cmin[here] = A[here];
	for (int &there : lis[here]) {
		ddfs(there);
		cmin[here] = min(cmin[here],cmin[there]);
	}
}

int tcnt;
void tdfs(int here, int cur) {
	vector<int> ris;
	for (int &there : lis[here]) {
		if (cmin[there]<=cur) ris.push_back(there);
	}
	sort(ris.begin(),ris.end(),[](int a, int b){return cmin[a]<cmin[b];});
	A[here] = tcnt; tcnt++;
	for (int &there : ris) {
		tdfs(there,cur);
	}
}

int lcnt, ocnt;
void ldfs(int here, int cur) {
	if (A[here]!=lcnt) pung();
	lcnt++;
	sort(lis[here].begin(),lis[here].end(),[](int a, int b){return A[a]<A[b];});
	for (int &there : lis[here]) {
		ldfs(there,cur);
	}
	if (ocnt<=cur&&R[here]!=ocnt) pung();
	ocnt++;
}

//void dmdfs(int here) {
//	for ()
//}
//void dm() {
//	N = 50;
//	for (int i=1;i<N;i++) {
//		par[i] = rand()%i;
//		lis[par[i]].push_back(i);
//	}
//}

int main() {
	scanf("%d",&N);
	for (int i=0;i<N;i++) {
		scanf("%d",&A[i]); A[i]--;
	}
	par[0] = -1;
	pii mini = {N,N};
	int tu = -1, tv = -1;
	for (int i=0;i<N-1;i++) {
		int a, b;
		scanf("%d%d",&a,&b); --a; --b;
		lis[a].push_back(b);
		if (A[a]<A[b]&&mini>pii(A[a],A[b])) {
			mini=pii(A[a],A[b]);
			tu=a,tv=b;
		}
		par[b] = a;
	}
	idfs(0);
	ll ans = 0;
	if (tu!=-1) {
		int p = tu;
		while(p) {
			if (A[par[p]]!=A[p]+dep[p]) pung();
			swap(A[p],A[par[p]]);
			p = par[p];
			ans++;
		}
	}
	for (int i=0;i<N;i++) loc[A[i]] = i;
	int cur = A[0]-1;
	for (int i=0;i<=cur;i++) {
		ans += dep[loc[i]];
	}
	ddfs(0);
	int cnt = 0, maxi = -1;
	for (int i=0;i<N;i++) {
		if (cmin[i]<=cur&&A[i]>cur) {
			if (i!=0&&A[i]!=A[par[i]]+1) pung();
		}
		if (cmin[i]<=cur) {
			cnt++;
			maxi = max(maxi,A[i]);
		}
	}
	if (maxi+1!=cnt) pung();
	for (int i=0;i<N;i++) R[i] = A[i];
	tdfs(0,cur);
	ldfs(0,cur);
	puts("YES");
	printf("%lld\n",ans);
	for (int i=0;i<N;i++) printf("%d ",A[i]+1);
	puts("");

	return 0;
}