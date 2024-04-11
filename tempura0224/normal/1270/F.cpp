#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<unordered_map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    string s;
    cin>>s;
    vector<int> a;
    ll n=s.size();
    a.push_back(-1);
    rep(i,n){
        if(s[i]=='1')a.push_back(i);
    }
    a.push_back(n);
    int m=a.size();
    ll ans = 0;
    const int B = 1600;
    REP(i,1,B+1){
        if(i>m-2)break;
        int l = 1, r = i;
        while(r+1<m){
            int L = a[l]-a[l-1], R =a[r+1]-a[r];
            int target = i-(a[r]-a[l]+1)%i;
            if(target==i)target=0;
            ans += (ll)(L/i)*(R/i)*i;
            ans += L%i*(R/i);
            ans += R%i*(L/i);
            L%=i;R%=i;
            int mi = max(0,target-R+1);
            int ma = min(L,target+1);
            ans += max(ma-mi,0);
            target += i;
            mi = max(0,target-R+1);
            ma = min(L,target+1);
            ans += max(ma-mi,0);
            ++l;++r;
        }
    }
    REP(i,1,126){
        unordered_map<ll,int> mp;
        unordered_map<ll,int> it;
        ll sum = 0;
        int x = 0;
        queue<pair<int,ll>> q;
        q.emplace(0,0);
        rep(j,n){
            ++sum;
            if(s[j]=='1')++x,sum -= i;
            while(q.front().first<x-B){
                mp[q.front().second]++;
                q.pop();
            }
            ans += mp[sum];
            q.emplace(x,sum);
        }
    }
    cout<<ans<<endl;
    return 0;
}