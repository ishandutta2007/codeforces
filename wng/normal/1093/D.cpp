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

VI ved;
vector<VI> cs;
LL nba,nbb;

LL modpow(LL base, LL exp, LL modulus) {
  base %= modulus;
  LL result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

bool dfs(int u, bool col){
	ved[u]=col?1:-1;
	if (col) nba++;
	else nbb++;
	bool isok=true;
	for (auto c:cs[u]){
		if (!ved[c]) isok&=dfs(c,!col);
		else {
			//cout<<c<<" "<<u<<" "<<ved[c]<<" "<<ved[u]<<endl;
			if (ved[c]==ved[u]) return false;
		}
	}
	return isok;
}


LL mod =998244353 ;
int main(){
	DRI(t);
	REP(nbt,t){
		DRII(n,m);
		ved=VI(n,0);
		cs=vector<VI>(n,VI(0));
		REP(i,m){
			DRII(u,v);
			u--; v--;
			cs[u].PB(v);
			cs[v].PB(u);
		}
		bool isok=true;
		LL tr=1;
		REP(i,n){
			if (!ved[i]){
				nba=0;
				nbb=0;
				isok=dfs(i,true);
				if (!isok) break;
				//cout<<nba<<" "<<nbb<<endl;
				LL res=modpow((LL)2,nba,mod);
				res%=mod;
				res+=modpow((LL)2,nbb,mod);
				res%=mod;
				tr*=res;
				tr%=mod;
			}
		}
		if (isok) {printf("%I64d\n",tr);}
		else {printf("0\n");}
	}
}