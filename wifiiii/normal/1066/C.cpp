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

char op[200005];
int cnt[200005][2], lst[200005];
int main() {
    int n;
    cin >> n;
    for(int i=1;i<=n;++i) {
        char c;
        cin >> c;
        op[i] = c;
        int x;
        cin >> x;
        cnt[i][0] = cnt[i-1][0];
        cnt[i][1] = cnt[i-1][1];
        if(c == 'L') {
            cnt[i][0]++;
            lst[x] = i;
        } else if(c == 'R') {
            cnt[i][1]++;
            lst[x] = i;
        } else {
            int cntl = 0, cntr = 0;
            if(op[lst[x]] == 'L') {
                cntl = cnt[i][0] - cnt[lst[x]][0];
                cntr = cnt[lst[x]-1][0] + cnt[lst[x]-1][1] + cnt[i][1] - cnt[lst[x]][1];
            } else {
                cntr = cnt[i][1] - cnt[lst[x]][1];
                cntl = cnt[i][0] - cnt[lst[x]][0] + cnt[lst[x]-1][0] + cnt[lst[x]-1][1];
            }
            cout << min(cntl, cntr) << endl;
        }
    }
}