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
    DRI(n);
    VI a(n);
    VI s(n);
    VI w(n);
    REP(i,n) {RI(a[i]);}
    REP(i,n) {RI(s[i]); if (s[i]) {w[s[i]-1]=i+1;}}
    //startneg
    int minstartposs=0;
	int issnok=0;
    if (s[n-1]){
		bool isok=true;
		int k=0;
		int startneg=-s[n-1];
		while ((s[n-1]-k>=1) and s[n-1-k]==s[n-1]-k) k++;
		if (s[n-1]==k) {
		    minstartposs=startneg;
    		int sn=minstartposs;
    		issnok=sn;
    		REPP(i,s[n-1],n){
	            //cout<<i<<" "<<w[i]<<" "<<issnok<<" "<<i-s[n-1]<<endl;
    			if (w[i] and w[i]>i-s[n-1]) {
    				issnok=0;
    				break;
    			}
    		}
		}
	}
	//cout<<w[0]<<" "<<issnok<<endl;
	if (issnok) {printf("%d\n",n+issnok);}
	else{
		minstartposs=0;
		REP(i,n){
		    //cout<<w[i]<<" "<<minstartposs<<endl;
			if (w[i]) minstartposs=max(minstartposs, w[i]-i);
		}
		printf("%d\n",minstartposs+n);
	}
}