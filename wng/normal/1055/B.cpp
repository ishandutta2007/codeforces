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
	DRIII(n,m,l);
	vector<LL> a(n);
	set<PII> mm;
	mm.insert({-1,-1});
	mm.insert({n+3,n+3});
	int curr=-1;
	REP(i,n){
		DRI(x);
		a[i]=(LL)x;
		if (a[i]>l){
			if (curr==-1){
				curr=i;
			}
		}
		else{
			if (curr>=0){
				mm.insert({curr,i});
				curr=-1;
			}
		}
	}
	if (curr>=0){
		mm.insert({curr,n});
		curr=-1;
	}
	REP(i,m){
		DRI(q);
		if (!q){
			printf("%d\n",mm.size()-2);
		}
		else{
			DRII(p,d);
			p--;
			LL na=a[p]+d;
			if (a[p]<=l and na>l){
				PII tp={p,p+1};
				auto it=mm.upper_bound({p,p+1});
				PII above=*it;
				it--;
				PII below=*it;
				if (above.F==tp.S){
					mm.erase(above);
					tp={tp.F,above.S};
				}
				if (tp.F==below.S){
					mm.erase(below);
					tp={below.F,tp.S};
				}
				mm.insert(tp);
			}
			a[p]=na;
		}
	}
}