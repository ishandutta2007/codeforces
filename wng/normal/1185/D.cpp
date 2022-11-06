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
    VPII b(n);
    REP(i,n){
		DRI(x);
		b[i]={x,i};
	}
	sort(b.begin(),b.end());
	if (n<=3){
		printf("1\n");
		return 0;
	}
	int res=-1;
	// test virer le 1
	LL len0=(LL)b[n-1].F-b[1].F;
	if (!(len0%(n-2))){
		LL raison=(len0/(n-2));
		int nbj=0;
		bool isgood=true;
		LL next=b[1].F;
		REPP(i,1,n){
			if (b[i].F==next) next+=raison;
			else {
				if (nbj) nbj--;
				else {isgood=false; break;}
			}
		}
		if (isgood) res=b[0].S+1;
	}
	// test virer le n
	len0=(LL)b[n-2].F-b[0].F;
	if (!(len0%(n-2))){
		LL raison=(len0/(n-2));
		int nbj=0;
		bool isgood=true;
		LL next=b[0].F;
		REPP(i,0,n-1){
			if (b[i].F==next) next+=raison;
			else {
				if (nbj) nbj--;
				else {isgood=false; break;}
			}
		}
		if (isgood) res=b[n-1].S+1;
	}
	// test virer anything else
	len0=(LL)b[n-1].F-b[0].F;
	if (res==-1 and !(len0%(n-2))){
		LL raison=(len0/(n-2));
		int nbj=1;
		int indj=-1;
		bool isgood=true;
		LL next=b[0].F;
		REPP(i,0,n){
	        //cout<<next<<" "<<i<<" "<<" "<<b[i].F<<" "<<nbj<<endl;
			if (b[i].F==next) next+=raison;
			else {
				if (nbj) {nbj--; indj=b[i].S;}
				else {isgood=false; break;}
			}
		}
		if (isgood) res=indj+1;
	}
	
	printf("%d\n",res);
}