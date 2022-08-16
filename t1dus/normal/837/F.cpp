#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
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

int n,k;
vi a;
vvi mat;
vvi iden;

int brute(){
    if (*max_element(all(a)) >= k) return 0;
    int s = 1;
    while (true){
        FOR(i,1,n) a[i] = min(a[i-1]+a[i],k);
        if (a[n-1] >= k) return s;
        s ++;
    }
}

vvi mult(vvi mat1, vvi mat2){
    vvi c(n,vi(n,0));
    REP(i,n){
        REP(j,n){
            int cur = 0;
            REP(l,n){
                ll x = mat1[l][j];
                ll y = mat2[i][l];
                // cur = min(k,cur+x*y);
                if (x != 0 and y > (k/x)) cur = k;
                else if (x*y > k-cur) cur = k;
                else cur = min(k,cur+(x*y));
            }
            c[i][j] = cur;
        }
    }
    return c;
}

vvi expo(vvi mat,int b){
    if (b == 0) return iden;
    if (b == 1) return mat;
    vvi x = expo(mat,b/2);
    if (b%2 == 1){
        return mult(mult(x,x),mat);
    }
    else{
        return mult(x,x);
    }
}

bool check(int mid){
    // cout << mid  << "--------------\n";
    if (mid == 0) return *max_element(all(a)) >= k;
    vvi cur = expo(mat,mid);
    int res = 0;
    // REP(i,n){
    //     REP(j,n){
    //         cout << cur[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    REP(j,n){
        int x = a[j];
        int y = cur[n-1][j];
        if (x != 0 and y > (k/x)) res = k;
        else if(x*y > k-res) res = k;
        else res = min(k,res+(x*y));
    }
    // cout << res << endl;
    return res >= k;
}

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    cin >> n >> k; bool zz = false;
    REP(i,n){
        int x;
        cin >> x;
        if (x != 0 or zz){
            a.pb(x);
            zz = true;
        }
    }
    n = a.size();
    if (n >= 10){
        cout << brute() << endl;
        return 0;
    }
    mat.resize(n);
    iden.resize(n);
    REP(i,n){
        REP(j,n){
            if (i >= j) mat[i].pb(1);
            else mat[i].pb(0);
            if (i == j) iden[i].pb(1);
            else iden[i].pb(0);
        }
    }
    int low = 0;
    int high = k;
    int mid,ans = -1;
    while (low <= high){
        mid = (low+high)/2;
        if (check(mid)){
            high = mid-1;
            ans = mid;
        }
        else{
            low = mid+1;
        }
    }
    cout << ans << endl;
}