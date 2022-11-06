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
	DRI(q);
	REP(nt,q){
		LL n,m,k;
		scanf("%I64d%I64d%I64d",&n,&m,&k);
		//LL mindist=min(n,m)+abs(n-m);
		
		//tps pour arriver a cote du pts
		LL t=(LL)min(n,m)+((LL)abs(n-m)/2)*2;
		if (((n-m)%2 and t<k)){
			printf("%I64d\n",k-1);
			continue;
		}
		if (((n-m+1)%2 and t<=k)){
		    if ((k-t+1)%2){
		        printf("%I64d\n",k);
			    continue;
		    }
		    if ((k-t)%2 and t<k) {
			    printf("%I64d\n",k-2);
		    }
			continue;
		}
		else{
			printf("-1\n"); 
		}
		/*if (mindist>k) {printf("-1\n"); continue;}
		
		if ((k-mindist)%2){
			if (n==m){
				mindist=min(n,m)+1;
				if (mindist>k) {printf("-1\n"); continue;}
				printf("%I64d\n",k-abs(n-m)-2);
			}
		}
		else{
			printf("%I64d\n",k-abs(n-m));
		}*/
	}
}