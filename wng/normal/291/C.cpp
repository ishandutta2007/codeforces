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
    DRII(n,k);
	VL s(n);
	REP(i,n){
		int a,b,c,d;
		scanf("%d.%d.%d.%d",&a,&b,&c,&d);
		LL z=(1LL<<24)*a+(1LL<<16)*b+(1LL<<8)*c+d;
		s[i]=z;
	//	cout<<z<<" ";
	}
	//cout<<endl;
	int rep=0;
	LL w=0;
	REP(i,31){
		w+=(1LL<<(31-i));
		set<LL> m;
		REP(j,n) m.insert(s[j]&w);
	  //cout<<i<<" "<<w<<" "<<SZ(m)<<endl;
		if (SZ(m)==k) {rep=i+1; break;}
	}
	if (rep){
		int a,b,c,d;
		d=w%256;
		w/=256;
		//cout<<w<<" ";
		c=w%256;
		w/=256;
		//cout<<w<<" ";
		b=w%256;
		w/=256;
		//cout<<w<<" ";
		a=w%256;
		w/=256;
		//cout<<w<<" ";
		printf("%d.%d.%d.%d\n",a,b,c,d);
	}
	else {printf("-1\n");}
	
}