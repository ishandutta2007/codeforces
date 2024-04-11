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
	int n,m,k,s;
	RII(n,m);
	RII(k,s);
	VI a(n);
	vector<vector<int>> qs(k);
	REP(i,n){RI(a[i]); qs[--a[i]].PB(i);}
	vector<VI> ms(n,VI(k));
	vector<VI> cs(n);
	REP(i,m){
		int a,b;
		RII(a,b);
		a--;
		b--;
		cs[a].PB(b);
		cs[b].PB(a);
	}
	REP(i,k){
		vector<bool> visited(n,false);
		int level=0;
		while (qs[i].size()){
			VI nqs;
			for (auto j:qs[i]){
				visited[j]=true;
				ms[j][i]=level;
			}
			for (auto j:qs[i]){
				for (auto jj:cs[j]){
					if (!visited[jj]){
						nqs.PB(jj);
					}
				}
			}
			qs[i]=nqs;
			level++;
		}
	}
	
	REP(i,n){
	    //for (auto ii:ms[i]) {cout<<ii<<" ";} cout<<endl;
		sort(ms[i].begin(),ms[i].end());
		int resi=0;
		REP(j,s){resi+=ms[i][j];}
		printf("%d%c",resi,i==n-1?'\n':' ');
	}
}