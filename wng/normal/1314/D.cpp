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
	
	DRII(n,k);
	vector<VI> m(n,VI(n,0));
	REP(i,n){
		REP(j,n){
			RI(m[i][j]);
			if (i==j) m[i][j]=1000000009;
		}
		// bon bon maintenant je dois dterminer pour tout (u,v) le classement des w tel que u->w->v soit minimum
	}
	vector<vector<VPII>> r2(n,vector<VPII>(n));
	REP(u,n){
		REP(v,n){
			REP(w,n){
				if (w!=u and w!=v){
					r2[u][v].PB({m[u][w]+m[w][v],w});
				}
			}
			sort(ALL(r2[u][v]));
		}
	}
	VI start(k/2+1,0);
	VI forbidden(n,0);
	forbidden[0]=k/2+1;
	int mincost=1000000009;
	while (true){
	//for (auto i: start) {cout<<i<<" ";} cout<<endl;
	int c=0;
//	cout<<"cost";
	bool isrok=true;
	REP(i,k/2){
	    bool isok=false;
		for (auto z: r2[start[i]][start[i+1]]){
			if (!forbidden[z.S]) {c+=z.F;  /*cout<<z.F<<"("<<z.S<<"),";*/ isok=true; break; }
		}
		isrok&=isok;
	}
	if (!isrok) c=1000000008;
//	cout<<"="<<c<<endl;
	mincost=min(mincost,c);
	// increment by 1
	int startend=k/2-1;
	while (start[startend]==n-1) {start[startend]=0; startend--; forbidden[n-1]--; forbidden[0]++;}
	if (startend==0) {break;}
	else {forbidden[start[startend]++]--; forbidden[start[startend]]++;}
	}
	
	printf("%d\n",mincost);
}