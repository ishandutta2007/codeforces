// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
 
#define int long long
#define double long double
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
// typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
const int mod=1e9+7;
const int INF=LLONG_MAX/2;
const double EPS=1e-9;
const int N=500007;
const int K=20;
mt19937 rng(1234);

int n;
int a[N];

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    int _;
    cin>>_;
    while (_--){
        cin>>n;
        rep(i,n) cin>>a[i];
        if (n==1){
            cout<<"yes\n";
            continue;
        }
        int sum=0;
        rep(i,n) sum+=a[i];
        map<int,int> mp;
        rep(i,n) mp[a[i]]++;
        int L=1,R=0;
        while (sum){
            int nL=0, nR=0;
            if (sum&1){
                nL=L, nR=L+R*2;
            } 
            else{
                nL=2*L+R, nR=R;
            }
            sum/=2;
            if (mp[sum]){
                int dec=min(nL,mp[sum]);
                nL-=dec, mp[sum]-=dec;
            }
            if (mp[sum+1]){
                int dec=min(nR,mp[sum+1]);
                nR-=dec, mp[sum+1]-=dec;
            }
            L=nL, R=nR;
        }
        if (L||R){
            cout<<"no\n";
        }
        else{
            cout<<"yes\n";
        }
    }
    return 0;
}


/*
14
1
327
2
869 541
2
985214736 985214737
3
2 3 1
3
2 3 3
6
1 1 1 1 1 1
6
100 100 100 100 100 100
8
100 100 100 100 100 100 100 100
8
2 16 1 8 64 1 4 32
10
1 2 4 7 1 1 1 1 7 2
10
7 1 1 1 3 1 3 3 2 3
10
1 4 4 1 1 1 3 3 3 1
10
2 3 2 2 1 2 2 2 2 2
4
999999999 999999999 999999999 999999999
*/