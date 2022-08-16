#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
#define mp make_pair
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define remax(a,b) a = max(a,b)
#define remin(a,b) a = min(a,b)
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define F first
#define S second
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define itr :: iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))

int power(int a,int b,int m = MOD){
	if(b == 0) return 1;
	if(b == 1) return a;
	int x = power(a,b/2,m)%m;
	x = (x*x)%m;
	if(b%2) return (x*a)%m;
	return x;
}

int n,k;
vector<pii> v;

signed main(){
	cin >> n >> k;
	int i = 2;
	while(i*i <= n){
	    if(n%i == 0){
	        int cnt = 0;
	        while(n%i == 0){
	            cnt ++;
	            n /= i;
	        }
	        v.pb({i,cnt});
	    }
	    i ++;
	}
	int num = 1,den = 1;
	if(n > 1) v.pb({n,1});
	for(auto x:v){
	    pii dp[x.S+5][k+5];
	    REP(i,x.S+1){
	        REP(j,k+1){
	            if(j == 0){
	                dp[i][j] = {power(x.F,i),1};
	            }
	            else if(i == 0){
	                dp[i][j] = {1,1};
	            }
	            else{
                    pii cur = {0,1};
	                REP(l,i+1){
	                    cur = {cur.F*dp[l][j-1].S+cur.S*dp[l][j-1].F, cur.S*dp[l][j-1].S};
	                   // int g = gcd(cur.F,cur.S);
	                   // cur = {cur.F/g,cur.S/g};
	                    cur = {cur.F%MOD,cur.S%MOD};
	                }
	                cur.S *= i+1;
	               // int g = gcd(cur.F,cur.S);
	               // cur = {cur.F/g,cur.S/g};
                    cur = {cur.F%MOD,cur.S%MOD};
                    dp[i][j] = cur;   
	            }
	        }
	    }
	    num = (num*dp[x.S][k].F)%MOD;
	    den = (den*dp[x.S][k].S)%MOD;
	}
	cout << ((num)*power(den,MOD-2))%MOD;
}