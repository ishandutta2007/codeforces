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
	int n,k;
	cin>>n>>k;
	vector<VI> t(n,VI(n));
	REP(i,n){
		string s;
		cin>>s;
		REP(j,n){
			if (s[j]=='B') t[i][j]=1;
		}
	}
	int wanyway=0;
	vector<VI> r(n-k+1,VI(n-k+1,0));
	int m=n-k+1;
	//rows
	REP(i,n){
		int minb=-1;
		int maxb=-1;
		REP(j,n){
			if (t[i][j]) { if (minb==-1) minb=j; maxb=j;}
		}
		if (minb==-1) wanyway++;
		else {
			if (maxb-minb<k) {
				//chouette, tous les erasers qui contiennent les deux marchent, c'est a dire qui commencent apres  max(0,maxb-k+1) et avant minb
				REPP(j,max(0,i-k+1),min(m,i+1)) {
					r[j][max(0,maxb-k+1)]++;
					if (minb+1 < m) r[j][minb+1]--;
				}
			}
		}
	}
	/*cout<<"res :\n";
	REP(i,m){
		REP(j,m){
			cout<<r[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;*/
	//cols
	REP(i,n){
		int minb=-1;
		int maxb=-1;
		REP(j,n){
			if (t[j][i]) { if (minb==-1) minb=j; maxb=j;}
		}
		if (minb==-1) wanyway++;
		else {
			if (maxb-minb<k) {
				//chouette, tous les erasers qui contiennent les deux marchent, c'est a dire qui commencent apres  max(0,maxb-k+1) et avant minb
				REPP(j,max(0,maxb-k+1),min(m,minb+1)) { //max(0,i-k+1),min(m,i+1)) {
					r[j][max(0,i-k+1)]++;
					if (i+1 < m) r[j][i+1]--;
				}
			}
		}
	}
	/*cout<<"res :\n";
	REP(i,m){
		REP(j,m){
			cout<<r[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;*/
	int maxres=0;
	REP(i,m){
		int cr=0;
		REP(j,m){
			cr+=r[i][j];
			maxres=max(maxres,cr);
		}
	}
	cout<<wanyway+maxres<<endl;
}