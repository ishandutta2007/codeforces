#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define al(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pc(x) __builtin_popcount(x)
#define pb push_back

int main() {
    int t;
    cin >> t;
    auto chk = [&](string &s) {
        int f = 0;
        for(char c: s) {
            if(isdigit(c)) f |= 1;
            if(islower(c)) f |= 2;
            if(isupper(c)) f |= 4;
        }
        return f == 7;
    };
    while(t--) {
        string s;
        cin >> s;
        int f = 0;
        for(char c: s) {
            if(isdigit(c)) f |= 1;
            if(islower(c)) f |= 2;
            if(isupper(c)) f |= 4;
        }
        int cnt = 3 - __builtin_popcount(f);
        if(cnt == 0) {
            cout << s << endl;
        } else if(cnt == 2) {
            if(f == 1) {
                s[1] = 'A';
                s[2] = 'a';
            } else if(f == 2) {
                s[1] = '1';
                s[2] = 'A';
            } else {
                s[1] = '1';
                s[2] = 'a';
            }
            cout << s << endl;
        } else {
            for(int i=0;i<s.size();++i) {
                char tmp = s[i];
                if(f == 3) s[i] = 'A';
                else if(f == 5) s[i] = 'a';
                else if(f == 6) s[i] = '1';
                else assert(0);
                if(chk(s)) {
                    cout << s << endl;
                    break;
                }
                s[i] = tmp;
            }
        }
    }
}