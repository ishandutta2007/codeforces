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
	DRII(n,m);
	VI p(n);
	VI c(n);
	vector<multiset<int>> ps(m+1);
	vector<LL> ss(m+1);
	vector<int> ns(m+1);
	multiset<pair<int,PII>> cheapest;
	int got=0;
	REP(i,n) {
		RII(p[i],c[i]);
		if (p[i]==1) {got++;}
		else {ps[p[i]].insert(c[i]);
			ns[p[i]]++;
			ss[p[i]]+=c[i];
		}
	}
	//Sum that is costs to remove all guys that have x
	vector<LL> sumx(n+1);
	VI nx(n+1);
	LL minscore=0;
	int maxscore=0;
	REPP(i,2,m+1){
		int k=0;
		for (auto j:ps[i]){
			cheapest.insert({j,{ns[i]-k,i}});
			sumx[ns[i]-k]+=j;
			nx[ns[i]-k]++;
			k++;
		}
		minscore+=ss[i];
		maxscore=max(maxscore,ns[i]);
	}
	LL tc=0;
	//for (auto i:sumx) {cout<<i<<" ";} cout<<endl;
	for (auto i:cheapest){
		//Cheapest
	   // cout<<minscore<<" "<<maxscore<<" "<<got<<" "<<tc<<endl;
		if (got>maxscore or tc>=minscore) {minscore=min(minscore,tc); break;}
		int extra=0;
		LL es=tc;
		int ms=maxscore;
		while (ms>=got+extra and es<=minscore){
			es+=sumx[ms];
			extra+=nx[ms];
			ms--;
		}
		if (ms+1==got+extra) minscore=min(minscore,es);
		
		
	   // cout<<minscore<<" "<<maxscore<<" "<<got<<" "<<tc<<endl;
	   // cout<<i.F<<" "<<i.S.F<<" "<<i.S.S<<endl;
		tc+=i.F;
		got++;
		nx[i.S.F]--;
		sumx[i.S.F]-=i.F;
		if (nx[maxscore]==0) {maxscore--;}
		ns[i.S.S]--;
	}
	
	printf("%I64d\n",minscore);
}