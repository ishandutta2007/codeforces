#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAXN = 2000100;
const ll MOD = 998244353;

int n;
int mat[20][20];
int Lloc[1<<18], Rloc[1<<18];
int L[3450][19][256];
int R[3450][19][128];
ll ans[100100];

void DoL(int bit, int idx) {
	vector<int> vec;
	for (int i=0;i<n;i++) if (bit>>i&1) vec.push_back(i);
	do {
		int x = 0;
		for (int i=(int)vec.size()-2;i>=0;i--) {
			x = x*2+mat[vec[i]][vec[i+1]];
		}
		L[idx][vec.back()][x]++;
	} while(next_permutation(vec.begin(),vec.end()));
}

void DoR(int bit, int idx) {
	vector<int> vec;
	for (int i=0;i<n;i++) if (bit>>i&1) vec.push_back(i);
	do {
		int x = 0;
		for (int i=0;i+1<vec.size();i++) {
			x = x*2+mat[vec[i]][vec[i+1]];
		}
		R[idx][vec.back()][x]++;
	} while(next_permutation(vec.begin(),vec.end()));
}

ll fact(ll n) {
	if (!n) return 1;
	return n*fact(n-1);
}

int main(){
	scanf("%d",&n);
	//n = 14;

	for (int i=0;i<n;i++) {
		char str[20];
		scanf("%s",str);
		for (int j=0;j<n;j++) {
			mat[i][j] = str[j]-'0';
		}
	}
	int lp = 0, rp = 0;
	memset(Lloc,-1,sizeof(Lloc));
	for (int i=0;i<(1<<n);i++) {
		int c = 0;
		for (int j=0;j<n;j++) {
			if (i>>j&1) c++;
		}
		if (c==n/2+1) {DoL(i,lp); Lloc[i] = lp; lp++;}
		if (c==n-n/2) {DoR(i,rp); Rloc[i] = rp; rp++;}
	}
	for (int i=0;i<(1<<n);i++) {
		if (Lloc[i]<0) continue;
		for (int j=0;j<n;j++) {
			if (~i>>j&1) continue;
			int l = Lloc[i], r = Rloc[((1<<n)-1)^i^(1<<j)];
			int ln = n/2+1, rn = n-n/2;
			for (int a=0;a<(1<<(ln-1));a++) {
				for (int b=0;b<(1<<(rn-1));b++) {
					ans[a|(b<<(ln-1))] += L[l][j][a] * R[r][j][b];
				}
			}
		}
	}

	for (int i=0;i<(1<<(n-1));i++) {
		printf("%lld ",ans[i]);
	}puts("");
	return 0;
}