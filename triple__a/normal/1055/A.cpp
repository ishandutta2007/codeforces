#include<bits/stdc++.h>
#define ULL unsigned long long
#define F first
#define S second
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define range(a) a.begin(), a.end()
#define PI pair<int,int>
#define VI vector<int>
 
using namespace std;
 
typedef long long ll;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn=2007;
int n,s,a[maxn][2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>s;
    rep(i,n) cin>>a[i][0];
    rep(i,n) cin>>a[i][1];
    if (!a[0][0]){
        cout<<"NO";
        return 0;
    }
    if (a[s-1][0]){
        cout<<"YES";
        return 0;
    }
    if (!a[s-1][1]){
        cout<<"NO";
        return 0;
    }
    for (int i=s;i<n;++i){
        if (a[i][0]&&a[i][1]) {cout<<"YES"; return 0;}
    }
    cout<<"NO";
    return 0;
}