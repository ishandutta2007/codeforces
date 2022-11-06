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
	VI i2m(m);
	REP(i,m){
		i2m[i]=(i*i)%m;
	}
	int r00=0;
	int r10=0;
	int r01=0;
	int r11=0;
	int nmm=n%m;
	REP(i,m){
		REP(j,m){
			if (not ((i2m[(i+1)%m]+i2m[(j+1)%m])%m)){
				r00++;
				if (i<nmm) {r10++;}
				if (j<nmm) {r01++;}
				if (max(i,j)<nmm) {r11++;}
			}
		}
	}
	LL res=0;
	LL nsm=n/m;
	//cout<<r00<<" "<<r01<<" "<<r10<<" "<<r11<<" "<<nmm<<" "<<nsm<<endl;
	//cout<<nsm*nsm*r00<<" "<<nsm*(r10+r01)<<" "<<r11<<endl;
	res=nsm*nsm*r00+nsm*(r10+r01)+ r11;
	printf("%I64d\n",res);
}