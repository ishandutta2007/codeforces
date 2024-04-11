//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue
#define move fjgjgjgjghd

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool no = 1;
    F(i, 1, n){
        if(s[i] < s[i - 1]){no = 0; brk;}
    }
    if(no){
        F(i, 0, n)cout << 1;
        cout << '\n';
        ret;
    }
    vector<int> col(n);
    F(la_one, 0, 10){
        col.assign(n, -1);
        int curr_dig = 0;
        bool ok = 1;
        F(i, 0, n){
            if(s[i] - '0' < curr_dig){
                ok = 0;
                brk;
            }
            if(s[i] - '0' < la_one && s[i] - '0' > curr_dig)
                curr_dig = s[i] - '0';
            if(s[i] - '0' == curr_dig)
                col[i] = 1;
        }
        if(!ok)cont;
        DF(i, n - 1, 0){
            if(col[i] == 1)brk;
            if(s[i] - '0' == la_one)
                col[i] = 1;
        }
        int prv = -1;
        F(i, 0, n){
            if(col[i] == 1)cont;
            if(prv > s[i] - '0'){ok = 0; brk;}
            prv = s[i] - '0';
            col[i] = 2;
        }
        if(!ok)cont;
        F(i, 0, n)cout << col[i];
        cout << '\n';
        ret;
    }
    cout << "-\n";
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}