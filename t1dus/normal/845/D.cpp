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
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
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

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	int ans = 0,speed,cur = 0,lim = INF;
	bool over = true;
	stack<int> st;
	WL(n){
	    int type; cin >> type;
	    if(type == 1){
            cin >> speed;	        
	    }
	    else if(type == 2){
	        ans += cur;
	        cur = 0;
	    }
	    else if(type == 3){
	        cin >> lim;
	        st.push(lim);
	    }
	    else if(type == 4){
	        over = true;
	        cur = 0;
	    }
	    else if(type == 5){
	        lim = INF;
	        while(!st.empty()) st.pop();
	    }
	    else{
	        cur ++;
	        over = false;
	    }
	    while (!st.empty() and st.top() < speed){
	        st.pop();
	        ans ++;
	    }
	}
	cout << ans << endl;
}

/*
1. Polycarp changes the speed of his car to specified (this event comes with a positive integer number);
2. Polycarp's car overtakes the other car;
3. Polycarp's car goes past the "speed limit" sign (this sign comes with a positive integer);
4. Polycarp's car goes past the "overtake is allowed" sign;
5. Polycarp's car goes past the "no speed limit";
6. Polycarp's car goes past the "no overtake allowed";
*/