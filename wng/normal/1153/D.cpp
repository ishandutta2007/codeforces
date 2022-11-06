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
	/* OK je veux :
	 * - determiner le nbenfants (taille du subtree) de totu le monde
	 * - determiner le nb enfants qui comptent de tt le monde
	 */
	 
	VI ps(n);
	VI mm(n);
	REP(i,n) {RI(mm[i]);}
	VI nbc(n,0);
	vector<VI> cs(n,VI(0));
	REP(i,n-1) { DRI(x); x--; ps[i+1]=x; nbc[x]++; cs[x].PB(i+1);}
	VI enfantstraites(n,0);
	queue<int> tt;
	REP(i,n) { if (!nbc[i]) tt.push(i);}
	VI nbeqc(n,0);
	int nbl=0;
	while(!tt.empty()){
		int p=tt.front();
		tt.pop();
		if (nbc[p]){
			int toteqc=0;
			int mineqc=10000000;
			for (auto c:cs[p]){
				toteqc+=nbeqc[c];
				mineqc=min(mineqc,nbeqc[c]);
			}
			nbeqc[p]=mm[p]?(mineqc):(toteqc);
		}
		else {nbeqc[p]=1; nbl++;}
		if (p) {enfantstraites[ps[p]]++; 
			if (enfantstraites[ps[p]]==nbc[ps[p]]){
				tt.push(ps[p]);
			}
		}
	}
//	for (auto i:nbeqc){ cout<<i<<" ";} cout<<endl;
	printf("%d\n",nbl+1-nbeqc[0]);
}