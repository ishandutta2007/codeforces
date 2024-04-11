#include<bits/stdc++.h>
using namespace std;

#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
#define spa << " " <<
#define rep(i,n,m) for(int i=int(n);i<int(m);i++)
#define rrep(i,n,m) for(int i=int(m)-1;i>=n;i--)
using ll=long long;
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){
    if(a>b){
        a=b;
        return true;
    }
    return false;
}
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){
    if(a<b){
        a=b;
        return true;
    }
    return false;
}

int main(){
    ll t;cin>>t;
    while(t--) {
        vector<int> a(3);
        rep(i, 0, 3)cin >> a[i];
        sort(ALL(a));
        if (a[0] + a[1] == a[2]) {
            cout << "YES" << endl;
        } else cout << "NO" << endl;
    }
    return 0;
}