#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef pair<int,int> pii;
#define pb push_back
#define INF 1000000000
#define mp make_pair
#define MOD 1000000007
#define F first
#define S second
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REPD(i,n) for(int i=(n);i>=0;i--)
#define FORD(i,a,b) for(int i=(a);i>=b;i--)
#define all(v) v.begin(),v.end()
#define itr ::iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define remin(a,b) (a) = min((a),(b))
#define remax(a,b) (a) = max((a),(b))

int k;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> k;
	if(k%2 == 0) cout << "NO\n";
	else{
	    cout << "YES\n";
	    if(k == 1) cout << "2 1\n1 2\n";
	    else{
	        cout << 2*k+4 << " " << k*k+2*k << endl;
	        cout << 1 << " " << k+3 << endl;;
	        FOR(i,2,k+1){
	            cout << 1 << " " << i << endl;
	            cout << i << " " << k+1 << endl;
	            cout << i << " " << k+2 << endl;
	        }
	        cout << k+1 << " " << k+2 << endl;
	        FOR(i,2,k+1){
	            FOR(j,i+1,k+1){
	                if(j-1 == i and j%2 == 1) continue;
	                cout << i << " " << j << endl;
	            }
	        }
	        
	        
	       //  ----__----__----__----__----
	       
	        FOR(i,2,k+1){
	            cout << 1+k+2 << " " << i+k+2 << endl;
	            cout << i+k+2 << " " << k+1+k+2 << endl;
	            cout << i+k+2 << " " << k+2+k+2 << endl;
	        }
	        cout << k+1+k+2 << " " << k+2+k+2 << endl;
	        FOR(i,2,k+1){
	            FOR(j,i+1,k+1){
	                if(j-1 == i and j%2 == 1) continue;
    	            cout << i+k+2 << " " << j+k+2 << endl;
	            }
	        }
	    }
	}
}