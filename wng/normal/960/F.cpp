#include <bits/stdc++.h>
typedef long long LL;
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second

using namespace std;

int main(){
	int n,m;
	RII(n,m);
	int res=0;
	vector<map<int,int>> bp(n);
	REP(i,n) {bp[i][0]=0;}
	REP(i,m) {
		int a,b,w;
		RIII(a,b,w);
		a--;b--;
		auto it=bp[a].lower_bound(w);
		it--;
		int nn=it->S+1;
		it = --bp[b].lower_bound(w);
		if (it->S<nn){
			if (bp[b].count(w)==0) {bp[b][w]=nn;}
			else {
				if (nn>bp[b][w]) {bp[b][w]=nn;}
				}
			if (bp[b][w]==nn){
				auto ref=bp[b].find(w);
				ref++;
				auto iniref(ref);
				while (ref!=bp[b].end() and ref->S<=nn){
					ref++;
				}
			bp[b].erase(iniref,ref);
			res=max(nn,res);
		}
		}
	}
	printf("%d\n",res);
}