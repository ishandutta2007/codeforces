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
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    REP(i,n){
	string s,t;
	cin>>s;
	cin>>t;
	int ns=s.size();
	int nt=t.size();
	int ps=0;
	int pt=0;
	int ppt=pt;
	bool isok=true;
	while (isok and ps<ns){
		int pps=ps;
		ppt=pt;
		while (pps<ns and s[pps]==s[ps]) pps++;
		isok&=(s[ps]==t[pt]);
		while (ppt<nt and t[ppt]==t[pt]) ppt++;
		isok&=(ppt-pt>=pps-ps);
		ps=pps;
		pt=ppt;
	}
	isok&=(ppt==nt);
	if (isok) {cout<<"YES\n";}
	else cout<<"NO\n";
	}
}