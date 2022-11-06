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

VI visited;

void visit(int i){
	
}

int main(){
	int n,m,q;
	RIII(n,m,q);
	vector<VI> cs(n+m);
	REP(i,q){
		int r,c;
		RII(r,c);
		r--;
		c--;
		c+=n;
		cs[r].PB(c);
		cs[c].PB(r);
	}
	
	int k=0;
	VI visited(n+m);
	REP(i,n+m){
		queue<int> tovisit;
		if (!visited[i]) {tovisit.push(i); k++; }
		while (!tovisit.empty()){
			int j=tovisit.front();
			tovisit.pop();
			if (!visited[j]) {
				visited[j]=k;
				for (auto ii:cs[j]){
					tovisit.push(ii);
				}
			}
		}
	}
	printf("%d\n",k-1);
}