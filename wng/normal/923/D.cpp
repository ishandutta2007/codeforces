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
	string s,t;
	cin>>s;
	cin>>t;
	int ns=s.size();
	int nt=t.size();
	VI bccums(ns);
	VI bccumt(nt);
	VI numas(ns);
	VI numat(nt);
	REP(i,ns)
	{
		char c=s[i];
		bccums[i]=((i>0)?bccums[i-1]:0);
		if (c=='A') {numas[i]=((i>0)?numas[i-1]:0)+1;}
		else {bccums[i]++;}
	}
	REP(i,nt)
	{
		char c=t[i];
		bccumt[i]=((i>0)?bccumt[i-1]:0);
		if (c=='A') {numat[i]=((i>0)?numat[i-1]:0)+1;}
		else {bccumt[i]++;}
	}
	int n;
	RI(n);
	REP(i,n){
		int a,b,c,d;
		RII(a,b);
		RII(c,d);
		a--;
		b--;
		c--;
		d--;
		int nas;
		int nat;
		int nbs=(bccums[b]-(a>0?bccums[a-1]:0));
		int nbt=(bccumt[d]-(c>0?bccumt[c-1]:0));
		nas=numas[b]- (nbs?0:(numas[a]-1));
		nat=numat[d]- (nbt?0:(numat[c]-1)); 
		if ((nas>=nat) and (nbs%2==nbt%2) and ((nbs < nbt or ((nbs == nbt) and (nas%3==nat%3))))) {
			if (nbs or (!nbt) or nas>nat){
			 printf("%d",1);
			}
			else{
				printf("%d",0);
			}
			 }
		else {printf("%d",0);
		//	cout<<endl<<nas<<" "<<nat<<" "<<nbs<<" "<<nbt<<" "<<numas[b]<<" "<<numas[d]<<endl;
		}
	}
    
}