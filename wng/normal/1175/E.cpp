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
	DRII(n,m);
	int k=0;
	while ((1<<k)<=n) {k++;}
	VPII its;
	REP(i,n){
		DRII(x,y);
		its.PB({x,y});
	}
	sort(its.begin(),its.end());
	int limax=500000;
	vector<VI> a(limax+5,VI(k));
	auto it=its.begin();
	int maxend=0;
	int i=it->F;
	while (it!=its.end()){
		int beg=it->F;
		int en=it->S;
		maxend=max(maxend,en);
		it++;
		while (it!=its.end() and it->F==beg) {
			maxend=max(maxend,it->S);
			it++;
		}
		if (it!=its.end()){
    		for (;i<min(it->F,maxend);i++){
    		   // cout<<"doing "<<i<<endl;
    			a[i][0]=maxend;
    		}		
    		i=max(i,it->F);
		}
		else 
    		for (;i<maxend;i++){
    			a[i][0]=maxend;
    		}
	}
	//a[i][j] = plus loin que je peux atteindre de i en j coups
	REPP(j,1,k){
		for (int i=limax;i>=0;i--){
			a[i][j]=max(a[i][j-1],a[a[i][j-1]][j-1]); 
		}
	}
	/*	REPP(i,1,10){
		    cout<<"a["<<i<<"]:";
		    REP(j,k){
		        cout<<a[i][j]<<" ";
		    }
		    cout<<endl;
		}*/
	REP(i,m){
		DRII(l,r);
		int tt=k-1;
		int ii=l;
		int nbm=0;
		while (tt>=0){
		  // cout<<nbm<<" "<<tt<<" "<<ii;
			while (tt>=0 and a[ii][tt]>=r) tt--;
		//	cout<<" "<<tt<<endl;
			if (tt<0) break;
			nbm+=1<<tt;
			ii=a[ii][tt];
			tt--;
		}
			if (a[ii][0]>=r) {printf("%d\n",nbm+1);}
			else printf("-1\n");
	}
}