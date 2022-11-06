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
	int inf=1000000000;
	int n;
	RI(n);
 //	n=5000;
	VI a(n);
	REP(i,n){
	 //    a[i]=i+1;
   		RI(a[i]);
	}
	int nbm=(n+1)/2+1;
	VPII oc(2*nbm);
	oc[0]={0,-inf};
	VI tc(2*nbm);
	tc[0]=1;
	REP(i,n){
	    //if (!(i%100)) {printf("%d %d\n",i,tc.size());}
	    
		VPII nc(2*nbm,{inf,0});
	    VI ntc(2*nbm);
		REP(j,2*nbm){
			if (tc[j]){
				if (j<nbm){
					//pas de risque de creation hoje.
					// si 
					if (a[i]>oc[j].S) {
							nc[j+nbm]=min(nc[j+nbm],{oc[j].F,a[i]});
						//pas d'interet a baisser a[i] for now
					}
					else {
							nc[j+nbm]=min(nc[j+nbm],{oc[j].F+(oc[j].S-a[i]+1),a[i]});
							nc[j]=min(nc[j],{oc[j].F,a[i]});
							ntc[j]=1;
					}
							ntc[j+nbm]=1;
				}
				else{
					int jj=j%nbm;
					if (a[i]<oc[j].S) {
						nc[jj+1]=min(nc[jj+1],{oc[j].F,a[i]});
						//No need for : j ai un jj+1 moins cher nc[j]=min(nc[j],{oc[j].F+(oc[j].S-a[i]+1),a[i]});
							ntc[jj+1]=1;
					}
					else{
						if (a[i]>oc[j].S) {
							nc[j]=min(nc[j],{oc[j].F,a[i]});
							nc[jj+1]=min(nc[jj+1],{oc[j].F+(a[i]-oc[j].S+1),oc[j].S-1});
							ntc[j]=1;
							ntc[jj+1]=1;
						}
						else {
							//nc[j]=min(nc[j],{oc[j].F+1,a[i]});}
							nc[jj+1]=min(nc[jj+1],{oc[j].F+1,oc[j].S-1});
							nc[jj]=min(nc[jj],{oc[j].F,a[i]});
							ntc[jj]=1;
							ntc[jj+1]=1;
						}
					}
				}
			}
		}
		// trim tc : remove i<i' et cout(i)>=cout(i')
		tc=ntc;
	/*	printf("%d\n",i);
		REP(j,n) {if (ntc[j]) {
				printf("%d %d %d %d\n",j,j%nbm,nc[j].F,nc[j].S);
			}
		}*/
		oc=nc;
	}
	
	VI res(nbm);
	
	for (int j=nbm-1;j>0;j--){
		res[j]=(j==nbm-1)?min(oc[j+nbm-1].F,oc[j].F):min(res[j+1],min(oc[j+nbm-1].F,oc[j].F));
	}
	REPP(i,1,nbm){
		printf("%d%c",res[i],i==nbm-1?'\n':' ');
	}
	
}