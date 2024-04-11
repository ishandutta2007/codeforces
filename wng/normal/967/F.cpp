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
    map<int,set<int>> oc;
    REP(i,m) {
		int u,v;
		RII(u,v);
		u--;
		v--;
		if (!oc.count(u)) {oc[u]=set<int>();}
		oc[u].insert(v);
		if (!oc.count(v)) {oc[v]=set<int>();}
		oc[v].insert(u);
		}
	if (!oc.count(0)) {printf("-1\n"); return 0;}
	vector<int> visited(n,-1);
	queue<pair<int,PII>> tovisit;
	tovisit.push({0,{0,0}});
	int haslvl2=0;
	while (!tovisit.empty() and tovisit.front().S.S<=3) {
		pair<int,PII> tv=tovisit.front();
		if (!~visited[tv.F]){
			if (tv.S.S==2) {haslvl2=tv.F;}
			visited[tv.F]=tv.S.F;
			if (oc.count(tv.F) and tv.S.S<3) {
				for (auto i: oc[tv.F]){
					tovisit.push({i,{tv.F,tv.S.S+1}});
				}
			}	
		}
		tovisit.pop();
	}
//	for (auto i:visited) {cout<<i<<" ";} cout<<endl;
	if (~visited[n-1])
	{
		VI vis(1,n-1);
		int curr=n-1;
		while (curr){
			curr=visited[curr];
			vis.PB(curr);
		}
		printf("%d\n",vis.size()-1);
		for (int i=vis.size()-1;~i;i--){
			printf("%d%c",vis[i]+1,i?' ':'\n');
		}
		return 0;
	}
	if (haslvl2){
		printf("4\n");
		printf("1 %d %d 1 %d",visited[haslvl2]+1,haslvl2+1,n);
		return 0;
	}
	//OK now the last case : there is no level2 !!!  (and there is a lvl1)
	//There is a solution iff there are 2 non equivalent edge connected to A
	//i.e. 2 edges that are connected to 1 and together and whose connected sets
	//are not the same. In that case, if A and B are these edges, B being
	//connected to a edge C, then  1 A B C A n is solution. Else, no solution.
	vector<bool> dejateste(n,false);
	dejateste[0]=true;
	for (auto ca:oc[0]){
		if (!dejateste[ca]){
			dejateste[ca]=true;
			int A,B,C;
			for (auto j:oc[ca]){
			    if (j) {
			        //for all children of each children of a ca, check if all his neighbours are the same than a. 
			        // if so, then j sucks and we don't even need to test it in the future (cause all his chidren are treated now)
					auto ita=oc[ca].begin();
					auto itb=oc[j].begin();
					int arediff=0;
					while (true) {
						if (ita!=oc[ca].end() and *ita==j) {ita++;}
						if (itb!=oc[j].end() and *itb==ca) {itb++;}
						if (ita==oc[ca].end() and itb==oc[j].end()) {break;}
						if (ita==oc[ca].end() and itb!=oc[j].end()) {arediff=*itb; A=ca; B=j; C=arediff;  assert(arediff); break;}
						if (ita!=oc[ca].end() and itb==oc[j].end()) {arediff=*ita; A=j; B=ca; C=arediff;  assert(arediff); break;}
						if (ita!=oc[ca].end() and itb!=oc[j].end() and *ita!=*itb) {arediff=min(*ita,*itb); A=*ita<*itb?j:ca; B=ca+j-A; C=arediff;  assert(arediff); break;}
						ita++;
						itb++;
					}
    				dejateste[j]=true;
    				if (arediff) {//on a gagne!!
    					printf("5\n");
    					printf("1 %d %d %d %d %d",A+1,B+1,C+1,A+1,n);
    					return 0;
    				}
			    }
			}
		}
	}
	//We lost : all children of A are equivalence groups disconnected from each other
	printf("-1\n");
	return 0;
	
	
}