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
	DRI(n);
	vector<VI> cs(n+1);
	REP(i,n-1){
		DRII(u,v);
		cs[u].PB(v);
		cs[v].PB(u);
	}
	VI ved(n+1);
	VI a(n);
	REP(i,n) {RI(a[i]);}
	VI q(n);
	vector<set<int>> tohave(1);
	tohave[0].insert(1);
	int ith=0;
	bool isok=true;
	ved[1]=1;
	REP(ind,n){
		int tc=a[ind];
		assert(tohave[ith].size());
		//for (auto i:tohave[ith]) {cout<<i<<" ";}
		//cout<<tc<<endl;
		if (tohave[ith].find(tc)!=tohave[ith].end()){
			tohave[ith].erase(tc);
		}
		else{
			isok=false;
			break;
		}
		set<int> nth;
		for (auto c:cs[tc]){
			if (!ved[c]){
				nth.insert(c);
				ved[c]=1;
			}
		}
		if (nth.size()) {tohave.PB(nth);}
		if (!tohave[ith].size()) ith++;
	}
	if (isok) {printf("Yes\n");}
	else {printf("No\n");}
}