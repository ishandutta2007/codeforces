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
	DRI(q);
	int ml=0;
	int mh=0;
	REP(i,q){
		char c[2];
		int x,y;
		scanf("%s%d%d",c,&x,&y);
		if (x<y) swap(x,y);
		//cout<<c<<" "<<x<<" "<<y<<endl;
		set<PII> s;
		if (c[0]=='?'){
			
			//auto a=s.upper_bound({x,y});
			if (x>=ml and y>=mh) printf("YES\n");
			else printf("NO\n");
		}
		else{
			ml=max(ml,x);
			mh=max(mh,y);
			/*
			auto a=s.lower_bound({x,y});
			auto b=a;
			PII tp={x,y};
			while (b!=s.end() and (*b)<tp) b++;
			if (b!=a) {s.erase(a,b); s.insert(tp);}
			else {if (a==s.end()) s.insert(tp);}*/
		}
	}
}