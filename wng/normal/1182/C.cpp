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
map<int,map<char,VI>> m;
    
bool isvow(char c){
	return (c=='a' or c=='e' or c=='i' or c=='o' or c=='u');
}
vector<string> ss;

int count(){
	VPII couplesthatrhyme;
	VPII othercouples;
	for (auto it:m){
		VI oth;
		for (auto it2:it.S){
			int nb=it2.S.size();
			REP(i,nb/2){
				couplesthatrhyme.PB({it2.S[2*i],it2.S[2*i+1]});
			}
			if (nb%2) {oth.PB(it2.S[nb-1]);}
		}
		REP(i,oth.size()/2){
			othercouples.PB({oth[2*i],oth[2*i+1]});
		}
	}
	int res=min(couplesthatrhyme.size(),othercouples.size()+(couplesthatrhyme.size()-othercouples.size())/2);
	cout<<res<<"\n";
	if (res==couplesthatrhyme.size()){
		 REP(i,res){
		 cout<<ss[othercouples[i].F]<<" "<<ss[couplesthatrhyme[i].F]<<"\n";
		 cout<<ss[othercouples[i].S]<<" "<<ss[couplesthatrhyme[i].S]<<"\n"; 
		 }
	}
	else{
		int kk=othercouples.size();
		REP(i,res){
			if (i<kk){
			 cout<<ss[othercouples[i].F]<<" "<<ss[couplesthatrhyme[i].F]<<"\n";
			 cout<<ss[othercouples[i].S]<<" "<<ss[couplesthatrhyme[i].S]<<"\n"; 
		 }
		 else{
			 cout<<ss[couplesthatrhyme[kk+2*(i-kk)].F]<<" "<<ss[couplesthatrhyme[kk+2*(i-kk)+1].F]<<"\n";
			 cout<<ss[couplesthatrhyme[kk+2*(i-kk)].S]<<" "<<ss[couplesthatrhyme[kk+2*(i-kk)+1].S]<<"\n"; 
		 }
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    ss=vector<string> (n);
    REP(i,n) 
    {
		cin>>ss[i];
		char lw=' ';
		int nbv=0;
		for (auto c:ss[i]){
			if (isvow(c)){
				nbv++;
				lw=c;
			}
		}
		m[nbv][lw].PB(i);
	}
    
    count();
}