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
	DRI(n);
	char s[300009];
	RS(s);
	VI tf;
	int to=0;
	int tc=0;
	vector<char> res(n);
	REP(i,n){
		if (s[i]=='(') to++;
		if (s[i]==')') tc++;
	}
	int lefto=n/2-to;
	REP(i,n){
		if (s[i]=='?'){
			if (lefto>0) {lefto--; res[i]='(';}
			else res[i]=')';
		}
		else res[i]=s[i];
	}
	int tot=(res[0]=='(')? 1:-1;
	//cout<<tot<<endl;
	if (n%2) {printf(":(\n"); return 0;}
	int i=1;
	for (;tot>0 and i<n;i++){
		tot += (res[i]=='(')? 1:-1;
	   // cout<<i<<" "<<tot<<endl;
	}
	if (tot or i!=n) {printf(":(\n"); return 0;}
	else {
		REP(i,n){
			printf("%c",res[i]);
		}
		printf("\n");
	}
}