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
	DRII(n,m);
	VPII e;
	VI potes1(n+1);
	REP(i,m){
		DRII(x,y);
		e.PB({x,y});
		if (x==1) potes1[y]=1;
	}
	VI gp1(n+1);
	VI gpx(n+1);
	VI gpy(n+1);
	int exautre=0;
	REPP(i,1,n+1){
		if (!potes1[i]) gp1[i]=1;
		else exautre=i;
	}
	VI potesx(n+1);
	for (auto ed:e){
		int x,y;
		x=ed.F;
		y=ed.S;
		if (x==exautre) {potesx[y]=1;}
		if (y==exautre) {potesx[x]=1;}
	}
	REPP(i,1,n+1){
		if (!gp1[i])
			if (not potesx[i]) gpx[i]=1;
			else gpy[i]=1;
	}
	//cout<<1<<" "<<exautre<<endl;
	//for (auto i:gp1) {cout<<i<<" ";} cout<<endl;
	////for (auto i:gpx) {cout<<i<<" ";} cout<<endl;
	//for (auto i:gpy) {cout<<i<<" ";} cout<<endl;
	VI groupes(n);
	VL nb(4);
	REP(i,n){
		if (gp1[i+1]) groupes[i]=1;
		if (gpx[i+1]) groupes[i]=2;
		if (gpy[i+1]) groupes[i]=3;
		nb[groupes[i]]++;
	}
	//printf("%d",groupes[0]);
	//REPP(i,1,n){
	//	printf(" %d",groupes[i]);
	//}
	//printf("\n");
	LL toget=nb[1]*nb[2]+nb[2]*nb[3]+nb[3]*nb[1];
	//cout<<toget<<endl;
	if (nb[1] and nb[2] and nb[3] and toget==m){
		bool isok=true;
		for (auto ed:e){
			int x,y;
			x=ed.F;
			y=ed.S;
			if (groupes[x-1]==groupes[y-1]) {isok=false; break;}
		}
		if (isok){
			printf("%d",groupes[0]);
			REPP(i,1,n){
				printf(" %d",groupes[i]);
			}
			printf("\n");
			return 0;
		}
	}
	printf("-1\n");
}