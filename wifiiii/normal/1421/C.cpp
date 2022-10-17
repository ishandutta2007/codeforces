#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int,int> pii;

//string rev(string s) {
//    reverse(all(s));
//    return s;
//}
int main() {
    string s;
    cin >> s;
    int n = s.size();
		cout << 5 << endl;
    cout << 'L' << " " << 2 << endl;
//    s = s.substr(1, 1) + s;
    ++n;
    cout << 'L' << " " << 2 << endl;
//    s = s.substr(1, 1) + s;
    ++n;
    cout << 'R' << " " << 3 << endl;
//    s += rev(s.substr(2, s.size()-3));
    n+=n-3;
    cout << 'R' << " " << n-1 << endl;
//    s += s.substr(s.size()-2, 1);
    ++n;
    cout << 'R' << " " << n-1 << endl;
//    s += s.substr(s.size()-2, 1);
//    cout << s << endl;
//    assert(s == rev(s));
}