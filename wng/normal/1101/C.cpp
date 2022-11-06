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
	DRI(t);
	REP(nt,t){
		DRI(n);
		set<PII> events;
		set<int> in;
		VI res(n,-1);
		REP(i,n){
			DRII(x,y);
			events.insert({x,-(i+1)});
			events.insert({y,(i+1)});
		}
		bool ja=false;
		int resbase=1;
		for (auto i:events){
			int who=i.S;
			if (who>0) {in.erase(who-1);}
			if (who<0) {
				int ww=abs(who)-1;
				if (in.size()) res[ww]=resbase;
				else {resbase=ja?2:1; ja=true; res[ww]=resbase;}
				in.insert(ww);
				//cout<<resbase<<" "<<ja<<" "<<res[ww]<<" "<<in.size()<<endl;
				}
		}
		if ((resbase==1)) {printf("-1\n");}
		else {
				REP(i,n){
					assert(res[i]!=-1);
					printf("%d%c",res[i],i==n-1?'\n':' ');
				}
			}
	}
}