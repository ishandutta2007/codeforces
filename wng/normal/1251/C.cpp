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
	int nt;
	cin>>nt;
	REP(nbt,nt){
		string s;
		cin>>s;
		int n=s.size();
		VI a(n);
		VI pa(0);
		VI im(0);
		REP(i,n){
			a[i]=s[i]-'0';
			if (a[i]%2) im.PB(a[i]);
			else pa.PB(a[i]);
		}
		int c1=0;
		int c2=0;
		while (c1<pa.size() and c2<im.size())
			if (pa[c1]<im[c2]) cout<<pa[c1++];
			else cout<<im[c2++];
		while (c1<pa.size()) cout<<pa[c1++];
		while (c2<im.size()) cout<<im[c2++];
		//REP(i,n) {cout<<a[i];}
		cout<<"\n";
	}

}