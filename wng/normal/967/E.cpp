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
	int n;
	RI(n);
	vector<LL> b(n);
	REP(i,n) cin>>b[i];
	sort(b.rbegin(),b.rend());
	LL m=(LL)1<<60;
	int c=60;
	VI poss(61,1);
	VI nb(61);
	int k=0;
	int pk=0;
	while (k<=n){
		if (k==n or !(m&b[k])) 
		{
			nb[c]=k-pk;
			pk=k;
			if (nb[c]>poss[c]) {printf("No\n");return 0;}
			if (k<n){
				while (!(m&b[k])){
				m>>=1;
				c--;
				REP(j,k){
					poss[c]+=(m&b[j])?1:0;
				}
			    }
			}
		}
		k++;		
	}
//	for (auto ii:nb){cout<<ii<<" ";}cout<<endl;
	//Ok si je suis encore la y a moyen, faut juste bien les ordonner now
	vector<LL> res;
	k=0;
	for (int i=60;i>=0;i--){
		if (nb[i]){
			LL di=(LL)1<<i;
			vector<LL> nr(k+nb[i]);
			int i0=0;
			int i1=0;
			int tp=k+nb[i];
			bool ok=true;
			REP(j,tp){
				if (ok and i0<nb[i]){
					nr[j]=b[k+i0];
					i0++;
					ok=false;
				}
				else{
					nr[j]=res[i1];
					if (res[i1]&di) {ok=true;}
					i1++;
				}
			}
	//		cout<<i<<" "<<i0<<" "<<i1<<" "<<res.size()<<" "<<nb[i]<<endl;
		//	for (auto ii:nr){cout<<ii<<" ";}cout<<endl;
			k+=nb[i];
			res=nr;
		}
	}
	printf("Yes\n");
	REP(i,n) {printf("%lld%c",res[i],i<n-1?' ':'\n');}
}