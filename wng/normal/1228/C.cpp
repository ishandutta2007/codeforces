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


LL modpow(LL base, LL exp, LL modulus) {
  base %= modulus;
  LL result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}


VI decompprime(int x){
	int i=2;
	VI res(0);
	while (i*i<=x){
		if (not (x%i)){
			res.PB(i);
			while (not (x%i)){
				x/=i;
			}
		}
		i++;
	}
	if (x>1){
		res.PB(x);
	}
	return res;
}

LL pf(int p, LL n){
	LL res= 0;
	LL pp=p;
	while (true){
		res+=n/pp;
		if (n/pp<p) break;
		pp*=p;
	}
	return res;
}



int main(){
	LL x,n;
	scanf("%I64d%I64d",&x,&n);
	int mod=1000000007;
	//cout<<modpow(2,104,mod)<<endl;
	VI dc=decompprime(x);
	//cout<<"dc done"<<endl;
	LL res=1;
	for (auto p:dc){
		res*=modpow(p,(int)(pf(p,n)%(mod-1)),mod);
		res%=mod;
		//cout<<p<<" "<<pf(p,n)<<" "<<modpow(p,(int)(pf(p,n)%(mod-1)),mod)<<" "<<res<<endl;
	}
	printf("%d\n",res);
}