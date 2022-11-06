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
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<string> s(n);
    REP(i,n){
		cin>>s[i];
	}
	vector<VI> nbl(n,VI(m,0));//nombre de emcs en dessous avant que ca change
	REP(j,m){
		for (int i=n-2;i>=0;i--){
			nbl[i][j]=(s[i][j]==s[i+1][j])?(nbl[i+1][j]+1):0;
		}
	}
	
	int hn=0;
	int hnp=0;
	int ncr=0; //next change row
	LL res=0;
	REP(i,n-2){
		int j =0;
		while(j<m){
			int ij=j;
			int hb=nbl[i][j];
			if (i+2*hb+2<n){
				while (j<m and s[i][j]==s[i][ij] and s[i+hb+1][j]==s[i+hb+1][ij] and s[i+2*hb+2][j] == s[i+2*hb+2][ij] and 
				nbl[i][j]==hb and nbl[i+hb+1][j]==hb and nbl[i+2*hb+2][j]>=hb) j++;
			}
			int larg=j-ij;
			res+=(larg*(larg+1))/2;
			if (!larg) j++;
		}
	}
	cout<<res<<endl;
}