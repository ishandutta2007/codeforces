#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,sse")
#include <bits/stdc++.h>
#define y1 y_1
//#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
#define prev aboba
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<vector<char> >frame;
const int N=600010;
const ll mod=998244353;
const ll inf=1e18;

int a[N];
int cnt[2];
int col[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        a[i]=(a[i]%3>0);
        cnt[a[i]]++;
    }
    if (cnt[0]>=cnt[1]){
        int black=0;
        for (int i=1;i<=n && black<n/2;i++){
            if (!a[i]){
                black++;
                col[i]=1;
            }
        }
        cout<<2<<endl;
    } else {
        int black=0;
        for (int i=1;i<=n && black<n/2;i++){
            if (a[i]){
                black++;
                col[i]=1;
            }
        }
        cout<<0<<endl;
    }
    for (int i=1;i<=n;i++) cout<<col[i];
    cout<<endl;




}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
//    cin>>tt;

    while (tt--){
        solve();
    }
    return 0;

}
///WRONG CYCLE
//124x
//xx3_
//xxxx



/*
4 4
bcex
adfd
gh_k
zghz
///0, 1, 2, 1, 2, 0, 2, 0, 1, 1, 2, 0, 2, 0, 1, 0, 1, 2, 2, 0, 1, 0, 1, 2, 1, 2, 0
1111111111111111111111111111111111111111111111111111111111111111
*/