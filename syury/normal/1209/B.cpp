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

const int T = 1000;
int cnt[T];
int n;

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    cin >> n;
    string s;
    cin >> s;
    F(i, 0, n){
        int b, a;
        cin >> a >> b;
        int curr = b;
        int state = s[i] - '0';
        F(j, 0, T){
            if(curr == j){
                state ^= 1;
                curr += a;
            }
            cnt[j] += state;
        }
    }
    cout << *max_element(cnt, cnt + T) << endl;
    return 0;
}