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
	int n,x,y;
	RIII(n,x,y);
	vector<VI> c(n+1);
	REP(i,n-1){
		int a,b;
		RII(a,b);
		c[a].PB(b);
		c[b].PB(a);
	}
	vector<int> visited(n+1);
	visited[x]=x;
	queue<int> s;
	s.push(x);
	int nbv=0;
	while (!s.empty()){
		int tv=s.front();
		s.pop();
		if (tv!=y){
			nbv++;
			for (auto i:c[tv]){
				if (!visited[i]){
					visited[i]=tv;
					s.push(i);
				}
			}
		}
	}
//	for (auto i:visited){cout<<i<<" ";} cout<<endl;
	int py=visited[y];
	int entre=0;
	int lastp=y;
	while (py!=x) {lastp=py; py=visited[py]; entre++;}
	int cy= n - nbv-1;
	int cx=-1;
	
	vector<int> visited2(n+1);
	visited2[x]=x;
	s.push(x);
	while (!s.empty()){
		int tv=s.front();
		    s.pop();
			cx++;
			for (auto i:c[tv]){
				if (!visited2[i] and i!=lastp){
					visited2[i]=tv;
					s.push(i);
				}
			}
	}
	
//	cout<<entre<<" "<<cy<<" "<<cx<<" "<<nbv<<" "<<lastp<<endl;
	// routes OK = routes totales - 1/2 routes contenant y et x
	LL res= (LL)n*(n-1)-(LL)(cx+1)*(cy+1);
	printf("%I64d\n",res);
	return 0;
}