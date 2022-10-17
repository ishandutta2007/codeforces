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
ll a[N];
int t[N];
void upd(int pos,int x){
    for (;pos<N;pos|=pos+1) t[pos]+=x;
}
int get(int pos){
    int sum=0;
    for (;pos>=0;pos&=pos+1,pos--) sum+=t[pos];
    return sum;
}
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) a[i]+=a[i-1];
    for (int i=1;i<=n;i++){
        if (a[i]<0){
            cout<<-1<<endl;
            return;
        }
    }
    for (int i=1;i<n;i++){
        if (a[i]>a[n]){
            cout<<-1<<endl;
            return;
        }
    }
    n--;

    vector<ll>cord;
    for (int i=1;i<=n;i++) cord.push_back(a[i]);
    sort(cord.begin(),cord.end());
    cord.erase(unique(cord.begin(),cord.end()),cord.end());
    for (int i=1;i<=n;i++){
        a[i]=lower_bound(cord.begin(),cord.end(),a[i])-cord.begin()+1;
    }
    ll res=0;
    for (int i=n;i>=1;i--){
        res+=get(a[i]-1);
        upd(a[i],1);
    }
    cout<<res<<'\n';
    for (int i=1;i<=n;i++){
        upd(a[i],-1);
    }




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