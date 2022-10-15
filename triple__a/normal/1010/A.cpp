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
int n,k;
int a[maxn],b[maxn];
vector<int> vec;
double ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout.precision(15);
    cin>>n>>k;
    rep(i,n) cin>>a[i];
    rep(i,n) cin>>b[i];
    vec.pb(b[0]);
    for (int i=n-1;i>0;--i){
        vec.pb(a[i]), vec.pb(b[i]);
    }
    vec.pb(a[0]);
    ans=k;
    for (auto c:vec){
        if (c==1){
            puts("-1");
            return 0;
        }
        ans*=1.0*c/(c-1);
    }
    cout<<ans-k<<endl;
    return 0;
}