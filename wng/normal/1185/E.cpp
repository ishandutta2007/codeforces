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
    int nbt;
    cin>>nbt;
    REP(numtest,nbt){
		int n,m;
		cin>>n>>m;
		VPII minc(26,{n+1,m+1});
		VPII maxc(26,{-1,-1});
		int maxl=-1;
		vector<string> t(n);
		REP(i,n){
			cin>>t[i];
			REP(j,m){
				if (t[i][j]!='.'){
					maxl=max(maxl,t[i][j]-'a');
					minc[t[i][j]-'a'].F=min(minc[t[i][j]-'a'].F,i);
					minc[t[i][j]-'a'].S=min(minc[t[i][j]-'a'].S,j);
					maxc[t[i][j]-'a'].F=max(maxc[t[i][j]-'a'].F,i);
					maxc[t[i][j]-'a'].S=max(maxc[t[i][j]-'a'].S,j);
				}
			}
		}
		bool isok=true;
		vector<VI> isc(26,VI(26,0));
		VI nbp(26,0);
		int nbl=0;
		REP(k,26){
			int x0,y0,x1,y1;
			x0=minc[k].F;
			if (x0<n){
				nbl++;
				y0=minc[k].S;
				x1=maxc[k].F;
				y1=maxc[k].S;
				if ((y1-y0)*(x1-x0)) {isok=false; break;}
				REPP(i,min(x0,x1),max(x0,x1)+1){
					REPP(j,min(y0,y1),max(y0,y1)+1){
						if (t[i][j]=='.') {isok=false; break;}
						if (t[i][j]!=t[x0][y0]) {isc[k][t[i][j]-'a']=1; if (t[i][j]-'a'<k) {isok=false; break;}}
					}
				}
			}
			else{
				nbp[k]=-1;
			}
		}
		if (!isok) {printf("NO\n"); continue;}
		REP(i,26){
			REP(j,26){
				if (isc[i][j]) nbp[j]++;
			}
		}
		vector<pair<PII,PII>> res(0);
		REP(x,maxl+1){
			if (nbp[x]>0) {break;}
			if (nbp[x]==0){ 
				nbl--;
				res.PB({minc[x],maxc[x]});
				REP(i,26){
					if (isc[x][i]) {nbp[i]--;}
				}
			}
			if (nbp[x]==-1) {res.PB({{-1,-1},{-1,-1}});}
		}
		for (int i=maxl-1; i>=0;i--){
			if (res[i].F.F==-1) {res[i]=res[i+1];}
		}
		if (nbl)  {printf("NO\n"); continue;}
		printf("YES\n");
		printf("%d\n",res.size());
		REP(i,res.size()){
			printf("%d %d %d %d\n",res[i].F.F+1,res[i].F.S+1,res[i].S.F+1,res[i].S.S+1);
		}
	}
}