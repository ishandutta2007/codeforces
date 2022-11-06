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


VI a;
int h;

bool cani(int k, int H){
	VI b(k);
	REP(i,k){
		b[i]=a[i];
	}
	int HH=H;
	sort(b.begin(),b.end());
	int i=0;
	while (i<k and b[i]<=H){
		if (i+1<k and b[i+1]<=H) {
			H-=b[i+1];
			i+=2;
		}
		else {i++; break;}
	}
	if (i==k) {return true;}
	i=1;
	H=HH-b[0];
	if (H<0) return false;
	while (i<k and b[i]<=H){
		if (i+1<k and b[i+1]<=H) {
			H-=b[i+1];
			i+=2;
		}
		else {i++; break;}
	}
	return (i==k);
}

int main(){
	DRI(n);
	RI(h);
	a = VI(n);
	REP(i,n) {RI(a[i]);}
	int tt=0;
	int k=1024;
    while (k){
        if (tt+k<=n and cani(tt+k,h)) tt+=k;
        k>>=1;
    }
    printf("%d\n",tt);
}