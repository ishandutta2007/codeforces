#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N, M;
vector<int> A[1600];
vector<int> B[1600];
int cmp[1600][1600];
int csum[1600];
int diff[1600];
int inq[1600];

void pung() {
	puts("-1");
	exit(0);
}

int main() {
	scanf("%d%d",&N,&M);
	for (int i=0;i<N;i++) {
		A[i].assign(M,0);
		for (int j=0;j<M;j++) scanf("%d",&A[i][j]);
	}
	for (int i=0;i<N;i++) {
		B[i].assign(M,0);
		for (int j=0;j<M;j++) scanf("%d",&B[i][j]);
	}
	vector<int> orda(N,0), ordb(N,0);
	iota(orda.begin(),orda.end(),0);
	iota(ordb.begin(),ordb.end(),0);
	sort(orda.begin(),orda.end(),[](int a, int b){
		return (A[a]<A[b])||(A[a]==A[b]&&a<b);
	});
	sort(ordb.begin(),ordb.end(),[](int a, int b){
		return (B[a]<B[b])||(B[a]==B[b]&&a<b);
	});
	for (int i=0;i<N;i++) {
		if (A[orda[i]]!=B[ordb[i]]) pung();
	}
	for (int i=0;i<N;i++) {
		B[ordb[i]].push_back(orda[i]);
	}
	for (int i=0;i+1<N;i++) {
		for (int j=0;j<=M;j++) {
			if (B[i][j]>B[i+1][j]) cmp[i][j] = 1;
		}
	}
	for (int j=0;j<=M;j++) {
		for (int i=0;i+1<N;i++) csum[j] += cmp[i][j];
	}
	queue<int> q;
	for (int j=0;j<=M;j++) {
		if (csum[j]==0) {
			q.push(j);
			inq[j] = 1;
		}
	}
	vector<int> ans;
	bool done = false;
	while(!q.empty()) {
		int here = q.front(); q.pop();
		if (here==M) {
			done = true;
			break;
		}
		ans.push_back(here);
		for (int i=0;i+1<N;i++) {
			if (B[i][here]<B[i+1][here]&&!diff[i]) {
				for (int j=0;j<=M;j++) {
					if (cmp[i][j]==1) {
						cmp[i][j] = 0;
						csum[j]--;
						if (csum[j]==0) {
							q.push(j);
							inq[j] = 1;
						}
					}
				}
				diff[i] = 1;
			}
		}
	}
	if (done) {
		reverse(ans.begin(),ans.end());
		printf("%d\n",ans.size());
		for (int &v : ans) printf("%d ",v+1);
	}
	else pung();

	return 0;
}