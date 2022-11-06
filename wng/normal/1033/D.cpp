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

int is_perfect_square(LL n) {
    if (n < 0)
        return false;
    int root(round(sqrt(n)));
    return (n == (LL)root * root)?root:0;
}

int is_perfect_cube(LL n) {
    int root(round(cbrt(n)));
    return (n == (LL)root * root * root)?root:0;
}

map<LL,int> mp;

int main(){
	int mod=998244353;
	vector<LL> left;
	DRI(n);
	REP(i,n){
		LL q;
		cin>>q;
		int sc=is_perfect_cube(q);
		int ss=is_perfect_square(q);
		if (sc){
			mp[sc]+=3;
		}
		else{
			if (ss){
				int s4=is_perfect_square(ss);
				if (s4){
					mp[s4]+=4;
				}
				else{
					mp[ss]+=2;
				}
			}
			else{
				left.PB(q);
			}
		}
	}
	VPII res(left.size(),{-1,-1});
	map<LL,int> rll;
	REP(i,(int)left.size()){
		for (auto k:mp){
			LL pg=__gcd(left[i],k.F);
			if (pg>1) res[i]={pg,left[i]/pg};
		}
		REPP(j,i+1,(int)left.size()){
			LL pg=__gcd(left[i],left[j]);
			if (pg>1 and pg<left[i]){
				res[i]={pg,left[i]/pg};
				res[j]={pg,left[j]/pg};
			}
		}
		if (res[i].F==-1){
			rll[left[i]]++;
		}
		else{
			mp[res[i].F]++;
			mp[res[i].S]++;
		}
	}
	LL rr=1;
	for (auto i:mp){
	    //cout<<i.F<<"  "<<i.S<<endl;
		rr*=(1+i.S);
		rr%=mod;
	}
	for (auto j:rll){
	    //cout<<j.F<<"  "<<j.S<<endl;
		rr*=(j.S+1)*(j.S+1);
		rr%=mod;
	}
	cout<<rr<<endl;
	fflush(stdout);
}