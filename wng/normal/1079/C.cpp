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
	VI a(n);
	VI b(n-1);
	REP(i,n){
		RI(a[i]);
		if (i){
			if (a[i]>a[i-1]) b[i-1]=1;
			if (a[i]<a[i-1]) b[i-1]=-1;
		}
	}
	if (n==1) {printf("1\n"); return 0;}
	b.PB(3);
	//for (auto i:a) {cout<<i<<" "; } cout<<endl;
	//for (auto i:b) {cout<<i<<" "; } cout<<endl;
	vector<pair<PII,int>> phases;
	int current=b[0];
	int st=0;
	REP(i,n){
		if (b[i]!=current){
			phases.PB({{st,i},current});
			current=b[i];
			st=i;
		}
	}
	int m=phases.size();
	bool isok=true;
	VI res;
	int startphase=(phases[0].S==1)?0:((phases[0].S==0)?1:4);
	
	REP(i,m){
		auto p=phases[i];
		//cout<<p.F.F<<" "<<p.F.S<<" "<<p.S<<endl;
		/*if (p.S and (p.F.S-p.F.F)>4) {isok=false; break;}
		if (p.S and i<m-2 and (p.F.S-p.F.F)==4 and phases[i+1].S==0 and phases[i+2].S*p.S==-1 
			    and(phases[i+2].F.S-phases[i+2].F.F)==4 and (phases[i+1].F.S-phases[i+1].F.F)==1 ) {
						isok=false; break;
		}*/
		if (not p.S){
			int ot=1;
			while (ot==startphase) ot++;
			int ott=ot+1;
			while (ott==startphase) ott++;
			res.PB(startphase);
			REPP(j,p.F.F+1,p.F.S){
				res.PB(j%2?ot:ott);
			}
			int osf=startphase;
			if (i<m-1) {startphase=(phases[i+1].S==1)?0:4;
					if ((p.F.S-p.F.F)==1 and startphase==osf){
						if (phases[i+1].S==1) startphase++;
						else startphase--;
					}
				}
			else startphase=p.F.S%2?ot:ott;
		}
		if (p.S==1){
			int dur=p.F.S-p.F.F;
			REPP(jj,startphase,startphase+dur){
				res.PB(jj);
			}
			if (i<m-1) startphase=(phases[i+1].S==-1)?4:startphase+dur;
			else startphase=startphase+dur;
		}
		if (p.S==-1){
			int dur=p.F.S-p.F.F;
			REP(jj,dur){
				res.PB(startphase-jj);
			}
			if (i<m-1) startphase=(phases[i+1].S==1)?0:(startphase-dur);
			else startphase=startphase-dur;
		}
	}
	res.PB(startphase);
	
	//check its ok
	
	REP(i,n-1){
		if (res[i]==res[i+1] or res[i]<0 or res[i]>4 or res[i+1]<0 or res[i+1]>4) isok=false;
		if ((a[i]-a[i+1])*(res[i]-res[i+1])<0) isok=false;
	}/**/
	
	if (isok){
		REP(i,n){
			printf("%d%c",res[i]+1,i==n-1?'\n':' ');
		}
	}
	else {
			printf("-1\n");
	}
}