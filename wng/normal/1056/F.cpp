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
	DRI(tc);
	REP(nt,tc){
		DRI(n);
		VPII ps;
		VI has(1001);
		has[0]=1;
		double c,tmax;
		//scanf("%.3f%.3f",&c,&tmax);
		cin>>c>>tmax;
		//cout<<c<<"  "<< tmax<<endl;
		REP(i,n){
			DRII(u,v);
			ps.PB({u,v});
			//cout<<ps[i].F<<" ah"<< ps[i].S<<endl;
		}
		sort(ps.begin(),ps.end());
		vector<vector<pair<double,int>>> T(1001);
		T[0].PB({0.0,0});
		REP(i,n){
			for (int j=1000;j>=0;j--){
				if (has[j]){
			//		cout<<j<<" eh"<< ps[i].S<<endl;
					if (!has[j+ps[i].S]){
						has[j+ps[i].S]=1;
						for (auto k: T[j]){
							T[j+ps[i].S].PB({(ps[i].F+k.F)/0.9,k.S+1});
						}
					}
					else{
						vector<pair<double,int>> newt;
						auto it=T[j+ps[i].S].begin();
						auto it2=T[j].begin();
						while (it!=T[j+ps[i].S].end() and it2!=T[j].end()){
							if (it->F > (ps[i].F+it2->F)/0.9){
								if (it->S >= (it2->S +1)) {
									it++;
								}
								else{
									newt.PB({(ps[i].F+it2->F)/0.9,it2->S+1});
									it2++;
								}
							}
							else{
								if (it->S > (it2->S +1)) {
									newt.PB(*it);
									it++;
								}
								else{
									it2++;
								}
							}
						}
						while (it!=T[j+ps[i].S].end()) {newt.PB(*it); it++;}
						while (it2!=T[j].end()) {newt.PB({(ps[i].F+it2->F)/0.9,it2->S+1}); it2++;}
						T[j+ps[i].S]=newt;
					}
				}
			}
		}
		int ms=0;
		REPP(s,1,1001){
			if (has[s]){
				//cout<<s<<endl;
				for (auto i:T[s]){
					//cout<<s<<" "<<i.F<<" "<<i.S<<" "<<10*i.S+ (sqrt(i.F/c)+(sqrt(c*i.F)-1)/c)<<endl;
					if (10*i.S+ ((c*i.F)>1?(sqrt(i.F/c)+(sqrt(c*i.F)-1)/c):i.F)<=tmax){
						ms=max(ms,s);
						break;
					}
				}
			
			}
		}
		printf("%d\n",ms);
	}
}