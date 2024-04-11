#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; i++ )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
int dx[4]={1,0,-1,0} , dy[4]={0,1,0,-1} ;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    ll l[n],r[n];
    vector<ll> v;
    rep(i,n){
        cin>>l[i]>>r[i];
        r[i]++;
        v.push_back(l[i]);
        v.push_back(r[i]);
    }
    sort(v.begin(),v.end());
    v.push_back(longinf);
    v.erase(unique(v.begin(), v.end()),v.end());
    int m=v.size();
    int a[m+1];
    rep(i,m)a[i]=0;
    rep(i,n){
        int x=lower_bound(v.begin(),v.end(),l[i])-v.begin();
        int y=lower_bound(v.begin(),v.end(),r[i])-v.begin();
        a[x]++;
        a[y]--;
    }
    rep(i,m)a[i+1]+=a[i];
    ll ans[n+1];
    rep(i,n+1)ans[i]=0;
    rep(i,m-1)ans[a[i]]+=v[i+1]-v[i];
    rep(i,n)cout<<ans[i+1]<<" ";
    cout<<endl;
    return 0;
}