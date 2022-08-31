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

int area(pii a, pii b){
    return a.F*a.S + b.F*b.S;
}

bool poss(int x, int y, int l1, int b1, int l2, int b2){
    if (l1+l2 <= x){
        return max(b1,b2) <= y;
    }
    else{
        return max(l1,l2) <= x and (b1+b2) <= y; 
    }
}

bool pos(int x, int y, int l1, int b1, int l2, int b2){
    return poss(x,y,l1,b1,l2,b2) or poss(x,y,l1,b1,b2,l2) or poss(x,y,b1,l1,l2,b2) or poss(x,y,b1,l1,b2,l2);
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,x,y;
	cin >> n >> x >> y;
	int ans = 0;
	pii a[n];
	REP(i,n) cin >> a[i].F >> a[i].S;
	REP(i,n) FOR(j,i+1,n) if (pos(x,y,a[i].F,a[i].S,a[j].F,a[j].S)) remax(ans,area(a[i],a[j]));
	cout << ans << endl;
}