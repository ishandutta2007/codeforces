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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    F(i, 0, n)cin >> a[i];
    int kek = 0;
    F(i, 0, n){
        if(a[i]%2 == 0){
            b[i] = a[i]/2;
        }
        else{
            b[i] = a[i]/2;
            if(kek){
                if(a[i] < 0)--b[i];
            }
            else if(a[i] > 0)++b[i];
            kek ^= 1;
        }
        cout << b[i] << '\n';
    }
    return 0;
}