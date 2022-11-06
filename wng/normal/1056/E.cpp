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

int mbase;

int mod=1000000007;

VI hp,mods;

bool is_prime(int n){
	if ((n+1)&1) return false;
	for (int i=3;i*i<=n;i+=2){
		if (!(n%i)) return false;
	}
	return true;
}

void init() {
    srand(time(0));
    for (mod = 1e9 + 1000 + (rand() % 1000)*1000; ; mod++) if (is_prime(mod)) break;
    for (mbase = 30 + (rand() % 200); ; mbase++) if (is_prime(mbase)) break;
}


int hashcode(int start,int len){
	int nextlen=((hp[start+len]-((LL)hp[start]*mods[len]))%mod + mod)%mod;
	return nextlen;
}

int main(){
	init();
	ios_base::sync_with_stdio(false);
	int mbase=127;
	cin.tie(NULL);
	string s,t;
	cin>>s>>t;
	int lt=t.size();
	int nb[2]={0,0};
	for (auto c:s){
		if (c=='0') nb[0]++;
		else nb[1]++;
	}
	hp=VI(lt+1);
	mods=VI(lt+1);
	mods[0]=1;
	REP(i,lt) {
		hp[i+1]=((LL)hp[i]*mbase+(t[i]-'a'))%mod;
		mods[i+1]=((LL)mods[i]*mbase)%mod;
	}
	int i=1;
	int res=0;
	while (i*nb[0]<lt){
		if (!((lt-i*nb[0])%nb[1])){
			int j=(lt-i*nb[0])/nb[1];
			int hasha=-1;
			int hashb=-1;
			int st=0;
			bool isok=true;
			for (auto k:s){
				if (k=='0'){
					if (nb[0]>1 or i==j){
						if (hasha==-1){hasha=hashcode(st,i); if (hasha==hashb) {isok=false;}}
						else {if (hasha!=hashcode(st,i)) {isok=false;break;}}
					}
					st+=i;
				}
				else {
					if (nb[1]>1 or j==i){
					if (hashb==-1){hashb=hashcode(st,j); if (hasha==hashb) {isok=false;}}
					else {if (hashb!=hashcode(st,j)) {isok=false;break;}}
					}
					st+=j;
				}
				
				if (not isok ) break;
			}
			if (isok) {res++; }//cout<<a<<" "<<b<<endl;}
		}
		i++;
	}
	cout<<res<<endl;
}