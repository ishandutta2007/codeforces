#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
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

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int a[1 << 20];
	REP(i,1<<20) a[i] = 0;
	int q;cin >> q;
	WL(q){
	    char type;
	    cin >> type;
	    if(type == '+'){
	        int b;
	        cin >> b;
	        int cur = 1;
	        int cnt = 0;
	        while(b){
	            if (b%2 == 1){
	                cnt += cur;
	            }
	            b /= 10;
	            cur *= 2;
	        }
	       // cout << "+ -> " << cnt << endl;
	        a[cnt] ++;
	    }
	    else if(type == '-'){
	        int b;
	        cin >> b;
	        int cur = 1;
	        int cnt = 0;
	        while(b){
	            if (b%2 == 1){
	                cnt += cur;
	            }
	            b /= 10;
	            cur *= 2;
	        }
	       // cout << "- -> " << cnt << endl;
	        a[cnt] --;
	    }
	    else{
	        int b;
	        cin >> b;
            int cur = 1;
	        int cnt = 0;
	        while(b){
	            if (b%2 == 1){
	                cnt += cur;
	            }
	            b /= 10;
	            cur *= 2;
	        }
	        cout << a[cnt] << endl;
	    }
	}
}