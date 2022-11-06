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
	DRII(m,k);
	DRII(n,s);
	VI a(m);
	REP(i,m) {RI(a[i]);}
	VI req(500005,0);
	int nbt=0;
	REP(i,s) {
		DRI(x);
		if (!req[x]++) nbt++;
		}
	VI req2(500005,0);
	REP(i,500005) {req2[i]=req[i];}
	map<int,VI> rr;
	VI done(500005,0);
	set<PII> xx; // set of the blocking beats
	int minrem=m;
	int startrem=-1;
	REP(i,m){
		if (req2[a[i]]) {
			if (!(--req[a[i]])) { if (!done[a[i]]) {nbt--;} done[a[i]]=1;}
			xx.insert({i,a[i]});
			int nbr=0;
			if (req[a[i]]<0 and (xx.begin()->S==a[i])){
				auto it=xx.begin();
				while (req[it->S]<0) {
					req[it->S]++;
					it++;
					nbr++;
				}
				xx.erase(xx.begin(),it);
				//cout<<nbr<<" -> "<<xx.size()<<endl;
			}
			if (!nbt) {
				int start=xx.begin()->F;
				int end=i;
				int nbtr=max(0,(start%k)+(end+1-start-k));
				if (nbtr<minrem){
					minrem=nbtr;
					startrem=start-start%k;
				}
	//			cout<<start<<" "<<end<<" "<<nbtr<<" "<<minrem<<" "<<startrem<<endl;
			}
		}
	}
	//cout<<minrem<<" "<<req2[1]<<" "<<req[1]<<" "<<done[1]<<" "<<nbt<<endl;
	if (m-minrem>=n*k){
		if (startrem>(n-1)*k) { /*cout<<startrem<<" "<<(n-1)*k<<"hey\n";*/ int tr=(n-1)*k-startrem; startrem+=tr; minrem-=tr;}
		printf("%d\n",minrem);
		if (minrem){
			REPP(i,startrem,m){
				if (req2[a[i]]>0) {req2[a[i]]--;}
				else{
					printf("%d%c",i+1,(--minrem)?' ':'\n');
					if (!minrem) break;
				}
			}
		}
		assert(!minrem);
	}
	else{
		printf("-1\n");
	}
}