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
	set<int> carnet;
	set<int> cv;
	set<int> ca;
	int nbf=0;
	LL res=1;
	int mod=1000000007;
	REP(q,n){
		char s[10];
		int i;
		RS(s);
		RI(i);
		if (s[1]=='D') {
			if (cv.size() and i>(*cv.begin())) cv.insert(i);
			else {if (ca.size() and i<-(*ca.begin())) ca.insert(-i);
				else carnet.insert(i);}
		}
		else{
			if (carnet.count(i)) nbf=1;
			else {
				if ((not cv.size() or *cv.begin()!=i) and (not ca.size() or *ca.begin()!=-i)) {
					printf("0\n"); return 0;
				}
				cv.erase(i);
				ca.erase(-i);
				nbf=0;}
			res*=(1+nbf);
			res%=mod;
			for (auto j:carnet){
				if (j<i){
					ca.insert(-j);
				}
				if (j>i){
					cv.insert(j);
				}
			}
			carnet.clear();
		}
		if (ca.size() and cv.size() and (-(*ca.begin())>*cv.begin())) { printf("0\n"); return 0;}
	}
	res*=carnet.size()+1;
	res%=mod;
	printf("%I64d\n",res);
}