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


VI SieveOfEratosthenes(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
 
    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
	VI res;
    // Print all prime numbers
    for (int p=2; p<=n; p++)
       if (prime[p]) res.PB(p);
    
    return res;
}




int main(){
	VI ps=SieveOfEratosthenes(10000);
	VI squares;
	for (auto i:ps){
		squares.PB(i*i);
	}
	int n;
	RI(n);
	VI(a);
	REP(i,n){
		int ca;
		RI(ca);
		if (ca){
			for (auto j:squares){
				while (!(ca%j)) {
					ca=ca/j;
				}
				if (abs(ca)<j) {break;}
			}
		}
		a.PB(ca);
	}
//	for (auto i:a) {cout<<i<<" ";} cout<<endl;
	VI res(n,0);
	int cnt=1;
	unordered_map<int,int> st;
	st[0]=0;
	VI ra;
	REP(i,n) {
	    if (!st.count(a[i])) st[a[i]]=cnt++;
	    ra.PB(st[a[i]]);
	}
//	for (auto i:ra) {cout<<i<<" ";} cout<<endl;
	REP(i,n){
		VI ishere(n+1,0);
        ishere[0]=1;
        int ms=-1;
		REPP(j,i,n){
			if (!ishere[ra[j]]){
			    ishere[ra[j]]=1;
    			ms+=1;
			}    
			res[max(ms,0)]++;
		}
	}
	REP(i,n){
		printf("%d%c",res[i],i==n-1?'\n':' ');
	}
}