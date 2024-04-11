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


 
struct frac{
    public:
        int num,den;
        frac(){}
        frac(int a) {num=a;}
        frac(int a,int b) {
			num=a;den=b;}
};

bool isinf(frac f1,frac f2) {return ((LL)f1.num*f2.den<(LL)f2.num*f1.den);}
vector<frac> e,s;

bool comp1(int i,int j){
		if (isinf(e[i],e[j])) return true;
		else{
			if (isinf(e[j],e[i])) return false;
			else{
					if (isinf(s[j],s[i])) return true;
					else{
						if (isinf(s[i],s[j])) return false;
						else{
							return (i>j);
//							if (j<i) return false;
//							else return true;
						}
					}
				}
		}
	}
	
bool comp2(int i,int j){
		if (isinf(s[i],s[j])) return true;
		else{
			if (isinf(s[j],s[i])) return false;
			else{
					if (isinf(e[j],e[i])) return true;
					else{
						if (isinf(e[i],e[j])) return false;
						else{
							return (j>i);
//							if (j<i) return false;
//							else return true;
						}
					}
				}
		}
	}
	
int main(){
	int n,w;
	RII(n,w);
	VI x(n);
	VI v(n);
	e.resize(n);
	s.resize(n);
	VI ways(n);
	VI o1(n);
	VI o2(n);
	REP (i,n) {
		RII(x[i],v[i]);
		o1[i]=i;
		o2[i]=i;
		e[i]=frac(abs(x[i]),abs(v[i]-w));//{abs(x[i])/p,(abs(v|i])+w)/p};
		s[i]=frac(abs(x[i]),abs(v[i]+w));
		
	}
	sort(o1.begin(),o1.end(),comp1);
	sort(o2.begin(),o2.end(),comp2);
	//for (auto i:o1){cout<<i<<" ";} cout<<endl;
	//for (auto i:o2){cout<<i<<" ";} cout<<endl;
	int ii=0;
	VI do2(n);
	for (auto i:o2)	{
		ii++;
		do2[i]=ii;
	}
//	for (auto i:do2){cout<<i<<" ";} cout<<endl;
	VI tree(n+1,0);
	LL res=0;
	int kk=0;
	for (auto i:o1){
		int ii=do2[i];
		res+=kk;
		while (ii>0){
			res-=tree[ii];
			ii-=ii&-ii;
		}
		ii=do2[i];
		while (ii<=n){
			tree[ii]+=1;
			ii+=ii&-ii;
		}
		kk++;
	//	for (auto i:tree){cout<<i<<" ";} cout<<endl;
	}
	printf("%I64d",res);
}