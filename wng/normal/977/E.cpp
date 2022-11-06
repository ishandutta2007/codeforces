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
	int n,m;
	RII(n,m);
	vector<VI> c(n,VI());
	REP(i,m){
		int u,v;
		RII(u,v);
		u--;
		v--;
		c[u].PB(v);
		c[v].PB(u);
	}
	
	int res=0;
	VI visited(n,0);
	REP(i,n){
		//cout<<i<<":";
		//for (auto j:c[i]) {cout<<j<<" ";} cout<<endl;
		if (!visited[i]){
			bool isc=true;
			queue<int> q;
			q.push(i);
			while (!q.empty()){
				int a=q.front();
				if (isc){
					if (c[a].size()!=2) {isc=false;}
				}
				for (auto j:c[a]){if (!visited[j]) {q.push(j);}}
				visited[a]=1;
			//	cout<<"visited "<<a<<endl;
				q.pop();
			}
			if (isc) {res++;}
		//	cout<<i<<" "<<isc<<endl;
		}
	}
	printf("%d\n",res);
}