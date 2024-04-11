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



pair<int, pair<int, int> > bezout(int a, int b) {
    int x = 1, y = 0;
    int xLast = 0, yLast = 1;
    int q, r, m, n;
    while(a != 0) {
        q = b / a;
        r = b % a;
        m = xLast - q * x;
        n = yLast - q * y;
        xLast = x, yLast = y;
        x = m, y = n;
        b = a, a = r;
    }
    return make_pair(b, make_pair(xLast, yLast));
}

int mul_inv(int a, int b) {
    pair<int, pair<int, int> > r= bezout(a,b);
    if (r.F==1) {return r.S.F;}
    return 0;
}

const int mod = 1000000007;

PII adfracmod(int p,int q,int pp,int qq) {
  int nd=((LL)q*qq)%mod;
  int np=(((LL)p*qq)%mod + ((LL)q*pp)%mod + mod) %mod;
  return {np,nd};
}


int main(){
	LL n;
	int k;
	scanf("%I64d %d",&n,&k);
	int mq=0;
	vector<pair<LL,int>> divs;
	for (int i=2;(LL)i*i<=n;i++){
		if (n%i==0){
			int ta=i;
			int hm=0;
			while (n%i==0) {hm++; n/=i;}
			divs.PB({(LL)ta,hm});
			mq=max(mq,hm);
		}
	}
	if (n>1) {
		divs.PB({n,1});
		mq=max(mq,1);
	}
	VI invmod(mq+1,1);
	
	REP(i,mq+1){
		invmod[i]=mul_inv(i+1,mod);
	}
	
	LL resn=1;
	LL resd=1;
	for (auto i:divs){
		//cout<<i.F<<" "<<i.S<<endl;
		vector<VI> num(i.S+1,VI(k+1,0));
		vector<VI> den(i.S+1,VI(k+1,1));
		REP(j,i.S+1){
			num[j][0]=modpow(i.F,j,mod);
			den[j][0]=1;
		}
		REPP(kk,1,k+1){
			//cout<<kk<<endl;
			num[0][kk]=1;
			den[0][kk]=1;
			REPP(j,1,i.S+1){
				PII stays={num[j][kk-1],(((LL)den[j][kk-1]*(j+1))%mod)};
				PII goes={((LL)num[j-1][kk]*j)%mod,(((LL)den[j-1][kk]*(j+1))%mod)};
				//cout<<num[j-1][kk]<<" "<<den[j-1][kk]<<endl;
				PII ta=adfracmod(stays.F,stays.S,goes.F,goes.S);
				num[j][kk]=ta.F;
				den[j][kk]=ta.S;
				//cout<<j<<" "<<kk<<" "<<stays.F<<"/"<<stays.S<<" "<<goes.F<<"/"<<goes.S<<" "<<ta.F<<"/"<<ta.S<<endl;
			}
		}
		resn*=num[i.S][k];
		resn%=mod;
		resd*=den[i.S][k];
		resd%=mod;
	}
	//cout<<resn<<" "<<resd<<endl;
	int res = ((resn*mul_inv(resd,mod))%mod+mod)%mod;
	cout<<res<<endl;
}