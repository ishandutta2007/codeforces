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
	int n;
	LL x,y;
	scanf("%d%I64d%I64d",&n,&x,&y);
	priority_queue<pair<LL,int>> q;
	vector<LL> ja(n+1,(LL)1E20);
	ja[n]=0;
	q.push({0,n});
	int exf=0;
	pair<LL,int> cq;
	while (!q.empty()){
	        cq=q.top(); q.pop();
		//	cout<<cq.first<<" "<<cq.S<<endl;
			int k = cq.second;
			if (exf==k) continue;
			vector<int> poss;
			LL plusmoins=cq.first-x;
			if (ja[k-1]>-plusmoins) {q.push({plusmoins,k-1}); 
				ja[k-1]=-plusmoins;
				if (not (k-1)) break;
				}
			if (k%2){
			    LL jj=-plusmoins+y;
				if (ja[(k+1)/2]>jj) {
				q.push({-jj,(k+1)/2}); 
				ja[(k+1)/2]=jj;}
			}
			else
				{
					LL fois=cq.first-y;
			//		cout<<k<<"  "<<fois<<" "<<ja[k/2]<<endl;
					if (ja[k/2]>-fois) 
					{
						q.push({fois,k/2}); 
						ja[k/2]=-fois;
					}
				}
				
		}
	printf("%I64d",ja[0]);
//	for (auto i:ja) cout<<i<<" ";
}