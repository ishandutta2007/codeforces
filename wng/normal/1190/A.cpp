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
	//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    
    LL n,k;
    int m;
    scanf("%I64d %d %I64d",&n,&m,&k);
    VL p(m);
    REP(i,m){
    scanf("%I64d",(&p[i]));}
	int curri=0;
    int lag=0;
    int nbo=0;
    while (curri<m){
		LL ist=p[curri];
		LL nbp= (p[curri] -1 - lag )/k;
		LL ep=(nbp+1)*k+1+lag;
		while (curri<m-1 and p[curri+1]<ep) {curri++;}
		nbo++;
		lag=curri+1;
		curri++;
		//cout<<ep<<" "<<nbp<<" "<<curri<<endl;
	}
	printf("%d\n",nbo);
}