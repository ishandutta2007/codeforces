#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
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

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin >> n;
    char a[2000005];
    REP(i,2000005) a[i] = 'a';
    int prev = 0;
    vector<string> s;
    vector<pair<pii,int> > b;
    REP(i,n){
        string c;
        cin >> c;
        s.pb(c);
        int l = c.length();
        int k;
        cin >> k;
        REP(j,k){
            int x;
            cin >> x;
            b.pb({{x-1,i},l});            
        }
    }
    sort(all(b));
    for(auto i: b){
        if (i.F.F+i.S > prev){
            FOR(j,max(i.F.F,prev),i.F.F+i.S) a[j] = s[i.F.S][j-i.F.F];
            prev = i.F.F+i.S;
        }
    }
    REP(i,prev) cout << a[i];
}
/*from functools import cmp_to_key
def compare(a,b):
    if a[0] < b[0]: return -1
    elif b[0] < a[0]: return 1
    elif a[2] > b[2]: return -1
    elif b[2] > a[2]: return 1
    return 0
n = int(input())    
a = ['a']*(int(2e6)+5)
prev = 0
s = []
b = []
for i in range(n):
    c = input().split()
    s.append(c[0])
    l = len(c[0])
    for j in c[2:]:
        b.append([int(j)-1,i,l])
b = sorted(b,key=cmp_to_key(compare))
for i in b:
    if i[0]+i[2] > prev:
        for j in range(max(i[0],prev),i[0]+i[2]):
            a[j] = s[i[1]][j-i[0]]
        prev = i[0]+i[2]    
print("".join(a[:prev]))        
*/