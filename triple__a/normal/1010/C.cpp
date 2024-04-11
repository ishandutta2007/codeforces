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

const int maxn=100007;

int n,k;
int a[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>k;
    int g=k;
    rep(i,n){
        cin>>a[i];
        a[i]%=k;
        g=__gcd(g,a[i]);
    }
    cout<<k/g<<endl;
    cout<<0<<endl;
    for (int i=g;i<k;i+=g) cout<<i<<endl;
    return 0;
}