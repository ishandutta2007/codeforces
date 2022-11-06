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
	cin.tie(0);
	int n;
	cin>>n;
	vector<string> a(n);
	vector<string> b(n);
	REP(i,n) {cin>>a[i];}
	REP(i,n) {cin>>b[i];}
	string mbeg="";
	string mend="";
	string mimp="";
	bool ja=false;
	int jaindex=-1;
	int s1;
	int s2;
	int t1i;
	int t2i;
	int lendif;
	VI autorise(n,3000);
	string nwelse;
	REP(i,n) {
		int mindif=3001;
		int maxdif=-1;
		REP(j,(int)a[i].size()){
		    //cout<<j<<" "<<a[i].size()<<" "<<a[i][j]<<b[i][j]<<endl;
			if (a[i][j]!=b[i][j]){
				mindif=min(mindif,j);
				maxdif=max(maxdif,j);
			}
		}
		if (maxdif>-1){
			autorise[i]=mindif;
			if (!ja){
				ja=true;
				jaindex=i;
				s1=mindif;
				s2=maxdif+1;
				t1i=0;
				t2i=a[i].size();
				lendif=s2-s1;
			}
			else{
				if (maxdif+1-mindif!=s2-s1  or a[i].substr(mindif,lendif)!=a[jaindex].substr(s1,lendif) or b[i].substr(mindif,lendif)!=b[jaindex].substr(s1,lendif)) {
				   // cout<<a[i]<<" "<<a[jaindex]<<endl;
				    //cout<<maxdif<<" "<<mindif<<" "<<s1<<" "<<s2<<" "<<lendif<<endl;
					cout<<"NO"<<endl; return 0;
				}
				REPP(j,t1i,s1){
					int indlag=mindif-s1+j;
					if (indlag<0 or a[i][indlag]!=a[jaindex][j]) t1i=j+1;
				}
				for (int j=t2i-1; j>=s2;j--){
					int indlag=maxdif+1-s2+j;
					if (indlag>a[i].size() or a[i][indlag]!=a[jaindex][j]) t2i=j;
				}
			}
		}
	}
	nwelse=a[jaindex].substr(t1i,t2i-t1i);
	int autoadj=t1i-s1;
	//cout<<nwelse<<" "<<autoadj<<endl;
	REP(i,n){
		if (a[i].find(nwelse)<autorise[i]+autoadj){//(autorise[i]+autoadj+nwelse.size()-1<a[i].size() and a[i].substr(0,autorise[i]+autoadj+nwelse.size()-1).find(nwelse)!=string::npos){
		  //  cout<<a[i].find(nwelse)<<" "<<autorise[i]<<endl;
			cout<<"NO"<<endl; return 0;
		}
	}
	cout<<"YES\n";
	cout<<a[jaindex].substr(t1i,t2i-t1i)<<endl;
	cout<<b[jaindex].substr(t1i,t2i-t1i)<<endl;
//	cout<<string::npos<<endl;/**/
}