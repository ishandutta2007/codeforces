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

class trie{
};


int main(){
	int n,m;
	RII(n,m);
	vector<VI> c;
	vector<VI> r;
	REP (i,n) {c.PB(VI(m));}
	REP (i,m) {r.PB(VI(n));}
	char l;
	scanf("%c",&l);
	REP (i,n) {REP(j,m){scanf("%c",&l); c[i][j]=l-'a';}scanf("%c",&l);}
//	for (auto k:c[i]){cout<<k<<" ";} cout<<endl;}
	REP (i,m) {REP(j,n){scanf("%c",&l); r[i][j]=l-'a';}scanf("%c",&l);}
	int mod=987654323;
	vector<LL> p26(1,1);
	LL last=1;
	REP(i,201){last*=26;last%=mod;p26.PB(last);};
	vector<LL> sigc;
	map<vector<LL>,int> possigs;
	REP(i,n) {
		LL ta=0;
		REP(j,m){ta+=c[i][j]*p26[m-j-1];}
		ta%=mod;
		sigc.PB((int)ta);
		if (i>=m-1){
			vector<LL> vta;
			REPP(j,i-m+1,i+1){vta.PB(sigc[j]);}
			possigs[vta]=i-m+1;
	       // if (i==7) {for (auto k:vta){cout<<k<<" ";} cout<<endl;}
		}
	}
	vector<LL> currsig(m,0);
	REP(i,n) {
		REP(j,m){
		currsig[j]=((LL)currsig[j]*26+r[j][i])%mod;
		}
		if (i>=m-1){
			if (possigs.count(currsig)){
				int tocheck=possigs[currsig];
				bool isok=true;
				REP(icheck,m){
					REP(jcheck,m){
						if (c[tocheck+icheck][jcheck]!=r[icheck][i-m+1+jcheck]) {isok=false;}
						if (!isok) break;
					}
					if (!isok) break;
				}
				if (isok) { cout<<tocheck+1<<" "<<i-m+2<<endl; return 0;}
			}
		//	cout<<i-m+1<<endl;
	      //  if (i==9) {for (auto k:currsig){cout<<k<<" ";} cout<<endl;}
			REP(j,m) {currsig[j]=(((LL)currsig[j]-p26[m-1]*r[j][i-m+1])%mod +mod)%mod;}
	    //     for (auto k:currsig){cout<<k<<" ";} cout<<endl;
		}
	}
//	for (auto i:sigc){cout<<i<<" ";} cout<<endl;
//	REP(i,m){cout<<p26[i]<<" ";} cout<<endl;
		cout<<"-1"<<endl;
		return 0;
}