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
#include<map>
#include<set>
#include<bitset>
#include<functional>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=998244353 ;

ll gcd(ll x,ll y){
    if(x<y)swap(x,y);
    if(x%y==0)return y;
    return gcd(y,x%y);
}

bool isprime[1510101];
int main(){
    int m=1500000;
    REP(i,2,m)isprime[i]=true;
    vector<ll> prime;
    rep(i,m){
        if(!isprime[i])continue;
        prime.push_back(i);
        for(int j=2*i;j<m;j+=i)isprime[j]=false;
    }
    m=prime.size();
    vector<ll> v3,v4;
    rep(i,m){
        if(prime[i]>1300000)break;
        v3.push_back(prime[i]*prime[i]*prime[i]);
    }
    rep(i,m){
        if(prime[i]>400000)break;
        v4.push_back(prime[i]*prime[i]*prime[i]*prime[i]);
    }
    int n;cin>>n;
    map<int,ll> mp,mp2;
    ll x[n];
    bool ok[n];
    rep(i,n){
        cin>>x[i];
        mp2[x[i]]++;
        int y=lower_bound(v3.begin(),v3.end(),x[i])-v3.begin();
        if(x[i]==v3[y]){
            mp[prime[y]]+=3;
            ok[i]=true;
            continue;
        }
        y=lower_bound(v4.begin(),v4.end(),x[i])-v4.begin();
        if(x[i]==v4[y]){
            mp[prime[y]]+=4;
            ok[i]=true;
            continue;
        }
        ll left=1,right=2e9,mid;
        while(right-left>1){
            mid=(left+right)/2;
            if(mid*mid>x[i])right=mid;
            else left=mid;
        }
        if(left*left==x[i]){
            mp[left]+=2;
            ok[i]=true;
            continue;
        }
        ok[i]=false;
    }
    rep(i,n){
        if(ok[i])continue;
        rep(j,n){
            ll z=gcd(x[i],x[j]);
            if(z==x[i]||z==1LL)continue;
            else {
                mp[z]++;mp[x[i]/z]++;
                ok[i]=true;
                break;
            }
        }
    }
    ll cnt=1;
    for(auto e:mp){
        cnt*=(e.second+1);
        cnt%=mod;
    }
    rep(i,n){
        if(ok[i])continue;
        ll c=mp2[x[i]];
        cnt*=(c+1)*(c+1);
        cnt%=mod;
        mp2[x[i]]=0;
    }
    cout<<cnt<<endl;
    return 0;
}