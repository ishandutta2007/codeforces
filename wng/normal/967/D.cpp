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
	int n,x1,x2;
	RIII(n,x1,x2);
	int inf=1000000000+2;
	VI c(n);
	VPII ca(n);
	REP(i,n) {RI(c[i]);
		ca[i]={c[i],i+1};
		}
	sort(c.begin(),c.end());
	sort(ca.begin(),ca.end());
	map<int,int> m;
	m[inf]=0;
	REP(i,n) {m[c[n-1-i]]=i+1;} //m[k] = nb de serveurs de capacite >=k
//	for (auto i:m) {cout<<i.F<<" "<<i.S<<endl;}
	int k1min=1;
	int k2min=1;
	int minsize=(x1-1)/k1min+1;
	auto flb=m.lower_bound(minsize);
	while (k1min<n and flb->S<k1min){
		k1min++;
		minsize=(x1-1)/k1min+1;
		flb=m.lower_bound(minsize);
	}
	minsize=(x2-1)/k2min+1;
	flb=m.lower_bound(minsize);
	while (k2min<n and flb->S<k2min){
		k2min++;
		minsize=(x2-1)/k2min+1;
		flb=m.lower_bound(minsize);
	}
//	cout<<k1min<<" "<<k2min<<endl;
	if (k1min+k2min>n) {
		printf("No\n");
		return 0;
	}
	//checkposs en gardant k1min au debut
	int k2s=k2min;
	minsize=(x2-1)/k2s+1;
	flb=m.lower_bound(minsize);
	while (k1min+k2s<=n and flb->S<k1min+k2s){
		k2s++;
		minsize=(x2-1)/k2s+1;
		flb=m.lower_bound(minsize);
	}
	if (k1min+k2s<=n){
		printf("Yes\n");
	//	cout<<flb->F<<" "<<flb->S<<endl;
		printf("%d %d\n",k1min,k2s);
		REP(i,k1min){printf("%d%c",ca[n-1-i].S,i==k1min-1?'\n':' ');}
		REP(i,k2s){printf("%d%c",ca[n-1-k1min-i].S,i==k2s-1?'\n':' ');}
		return 0;
	}
	
	//checkposs en gardant k1min au debut
	int k1s=k1min;
	minsize=(x1-1)/k1s+1;
	flb=m.lower_bound(minsize);
	while (k2min+k1s<=n and flb->S<k1s+k2min){
		k1s++;
		minsize=(x1-1)/k1s+1;
		flb=m.lower_bound(minsize);
	}
	if (k1s+k2min<=n){
		printf("Yes\n");
		printf("%d %d\n",k1s,k2min);
		REP(i,k1s){printf("%d%c",ca[n-1-k2min-i].S,i==k1s-1?'\n':' ');}
		REP(i,k2min){printf("%d%c",ca[n-1-i].S,i==k2min-1?'\n':' ');}
		return 0;
	}
	printf("No\n");
	return 0;
	}