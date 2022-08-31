/*input
7 6
6 4 1 10 3 2 4
2 1 7
2 4 5
1 3 5
2 4 4
1 5 7
2 1 7
*/      
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
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;
 
int power(int a,int b,int m = MOD){
    if(b == 0) return 1;
    if(b == 1) return a;
    int x = power(a,b/2,m)%m;
    x = (x*x)%m;
    if(b%2) return (x*a)%m;
    return x;
}
 
int n,m;
int seg[600005],d[1000005];
 
void upd(int ind){
    ind += n;
    seg[ind] = d[seg[ind]];
    ind /= 2;
    while(ind){
        seg[ind] = seg[ind*2]+seg[ind*2+1];
        ind /= 2;
    }
}
 
int quer(int l,int r){
    l += n;
    r += n+1;
    int res = 0;
    while(l < r){
        if(l%2) res += seg[l++];
        if(r%2) res += seg[--r];
        l /= 2;
        r /= 2;
    }
    return res;
}
 
void solve(){
    set<pii> s;
    REP(i,n) scanf("%lld",&seg[i+n]),s.insert({i,seg[i+n]});
    for(int i = n-1; i > 0; i--) seg[i] = seg[i*2]+seg[i*2+1];
    WL(m){
        int type,x,y; 
        scanf("%lld%lld%lld",&type,&x,&y);
        if(x > y) swap(x,y);
        x --;
        y --;
        if(type == 1){
            auto lol1 = s.lower_bound({x,0});
            vector<pii> v;
            while(lol1 != s.end()){
                pii lol2 = *lol1;
                if(lol2.F > y) break;
                v.pb(lol2);
                lol1++;
            }
            for(pii lol:v){
                upd(lol.F);
                s.erase(lol);
                int hehe = d[lol.S];
                if(hehe > 2){
                    s.insert({lol.F,hehe});
                }
            }
        }
        else{
            printf("%lld\n",quer(x,y));
        }
    }
}
 
signed main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    FOR(i,1,1000005){
        for(int j = i; j <= 1000000; j += i) d[j] ++;
    }
 
    scanf("%lld%lld",&n,&m);

    solve();
}