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
	RI(n);
	VI a(n);
	int ma=0;
	REP(i,n) {RI(a[i]);  ma=max(ma,a[i]);a[i]--;}
	VI d(n);
	set<int> diffs;
	REPP(i,1,n) {d[i-1]=abs(a[i]-a[i-1]);diffs.insert(d[i-1]); if (diffs.size()>2) break;}
	//for (auto i: a){cout<<i<<" ";} cout<<endl;
	//for (auto i: d){cout<<i<<" ";} cout<<endl;
	//for (auto i: diffs){cout<<i<<" ";} cout<<endl;
	if (diffs.count(0)) {printf("NO\n"); return 0;}
	if (diffs.size()==0) {printf("YES\n"); printf("%d 1",ma); return 0;}
	if (diffs.size()>2) {printf("NO\n"); return 0;}
	if (diffs.size()==1) 
		{
			int cols=*diffs.begin();
			int nbk=(ma-1)/cols+1;
			if (max(nbk,cols)<=1000000000) {
			printf("YES\n");
			printf("%d %d\n",nbk,cols);}
			else printf("NO\n");
			return 0;
		}
	int un=*diffs.begin();
	int f2=*(++diffs.begin());
	if (un!=1) {printf("NO\n"); return 0;}
	bool isok=true;
	REP(i,n-1) {
		if (d[i]==1 and a[i]/f2!=a[i+1]/f2){
				isok=false;
				break;
			}
		}
	if (isok){
			int cols=f2;
			int nbk=(ma-1)/cols+1;
			if (max(nbk,cols)<=1000000000) {
			printf("YES\n");
			printf("%d %d\n",nbk,cols);}
			else printf("NO\n");
			return 0;
	}
	else {printf("NO\n"); return 0;}
}