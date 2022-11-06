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

vector<set<int>> cs;

VI ved;
VI ving;
VI L;

bool dfs(int i){
	ving[i]=1;
	bool tr=true;
	for (auto c:cs[i]){
		if (ving[c]) {return false;}
		if (!ved[c]) {tr&=dfs(c);}
	}
	ving[i]=0;
	ved[i]=true;
	L.PB(i);
	return tr;
}


int main(){
	DRII(n,m);
	ved=VI(n);
	ving=VI(n);
	cs=vector<set<int>>(n);
	char s[300005];
	RS(s);
	REP(i,m){
		DRII(u,v);
		if (u==v) {printf("-1\n"); return 0;}
		cs[u-1].insert(v-1);
		}
	REP(i,n){
		if (!ved[i]){
			if (!dfs(i)) {printf("-1\n"); return 0;}
		}
	}
	reverse(L.begin(),L.end());
	//for (auto i:L) {cout<<i<<" ";} cout<<endl;
	vector<VI> res(300000,VI(26));
	int mr=0;
	for (auto i:L){
		res[i][s[i]-'a']++;
		mr=max(mr,res[i][s[i]-'a']);
		REP(j,26){
			if (res[i][j]){
				for (auto c:cs[i]){
					res[c][j]=max(res[c][j],res[i][j]);
				}
			}
		}
	}
	printf("%d\n",mr);
}