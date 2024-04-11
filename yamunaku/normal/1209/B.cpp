//
// Created by yamunaku on 2019/09/14.
//

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repl(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perl(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD9 998244353
#define MOD1 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)
#define CST(x) cout<<fixed<<setprecision(x)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> mti;
typedef vector<ll> vl;
typedef vector<vector<ll>> mtl;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vi st(n);
    rep(i,n) st[i]=s[i]-'0';
    vi a(n),b(n);
    rep(i,n) cin >> a[i] >> b[i];
    int ans=0;
    rep(j,n){
        ans+=st[j];
    }
    int tmp;
    rep(i,100000){
        tmp=0;
        rep(j,n){
            if(i>=b[j]&&(i-b[j])%a[j]==0) st[j]=1-st[j];
            tmp+=st[j];
        }
        ans=max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}