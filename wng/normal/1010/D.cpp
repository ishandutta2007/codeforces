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
	VI t(n);
	VI v(n,-1);
	vector<VI> cs(n);
	VI ps(n,-1);
	VI tt;
	int c;
	int b;
	map<string,int> trad;
	trad["OR"]=0;
	trad["AND"]=1;
	trad["XOR"]=2;
	trad["NOT"]=3;
	trad["IN"]=4;
	REP(i,n){
		char s[10];
		RS(s);//cin>>s;
		int typ=trad[s];
		t[i]=typ;
		if (typ==4){
			RI(b);
			tt.PB(i);
			v[i]=b;
		}
		else{
			if (typ==3){
				RI(b);
				ps[b-1]=i;
			}
			else{
				RII(b,c);
				ps[b-1]=i;
				ps[c-1]=i;			
			}
		}
	}
	
	int root;
	while (tt.size()){
		VI ntt;
		for (auto i:tt){
			if (v[i]==-1){
				if (t[i]==0) {v[i]=v[cs[i][0]]|v[cs[i][1]];}
				if (t[i]==1) {v[i]=v[cs[i][0]]&v[cs[i][1]];}
				if (t[i]==2) {v[i]=v[cs[i][0]]^v[cs[i][1]];}
				if (t[i]==3) {v[i]=1-v[cs[i][0]];}
			}
			root=i;
			if (ps[i]!=-1){
				cs[ps[i]].PB(i);
				if (t[ps[i]]==3){
					ntt.PB(ps[i]);
				}
				else{
					if ((int)cs[ps[i]].size()==2) ntt.PB(ps[i]);
				}
			}
		}
		tt=ntt;
	}
	VI doichange(n);
	VI tocheck(1,root);
	doichange[root]=1;
	while (tocheck.size()){
		VI ntc;
		for (auto i:tocheck){
			if (t[i]==0){
				int a=cs[i][0];
				int b=cs[i][1];
				if (v[a]&(!v[b])) {
					doichange[a]=1;
					ntc.PB(a);
				}
				else{
					if (v[b]&(!v[a])) {
						doichange[b]=1;
						ntc.PB(b);
					}
					else{
						if (!(v[a]|v[b])){
							doichange[a]=1;
							doichange[b]=1;
							ntc.PB(a);
							ntc.PB(b);
						
						}
					}
				}
			}
			if (t[i]==1){
				int a=cs[i][0];
				int b=cs[i][1];
				if (v[a]&(!v[b])) {
					doichange[b]=1;
					ntc.PB(b);
				}
				else{
					if (v[b]&(!v[a])) {
					doichange[a]=1;
					ntc.PB(a);
					}
					else{
						if ((v[a]&v[b])){
							doichange[a]=1;
							doichange[b]=1;
							ntc.PB(a);
							ntc.PB(b);
						}
					}
				}
			}
			if (t[i]==2){
				int a=cs[i][0];
				int b=cs[i][1];
				doichange[a]=1;
				doichange[b]=1;
				ntc.PB(a);
				ntc.PB(b);
			}
			if (t[i]==3){
				int a=cs[i][0];
				doichange[a]=1;
				ntc.PB(a);
			}
		}
		tocheck=ntc;
	}
	int valeur=v[root];
	//cout<<root<<" "<<valeur<<endl;
//	for (auto i:v){ cout<<i<<" ";} cout<<endl;
	
	VI res;
	REP(i,n){
		if (t[i]==4){
			printf("%d",doichange[i]?1^valeur:valeur);
		}
	}
	printf("\n");
}