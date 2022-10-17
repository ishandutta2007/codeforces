#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
typedef long long ll; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k=1,score=0;
    cin>>n;
    priority_queue<pair<ll,ll> > good;
    rep(i,0,n){
        ll a1,b1,a2,b2;
        cin>>a1>>b1>>a2>>b2;
        ll x=a1+b1, y=a2+b2, t=a1+a2-b1-b2;
        if(x>y) good.push({x,-y}), score += t;
        else if(+t > y-x) score += 2*(a1-b2);
        else if(-t > y-x) score += 2*(a2-b1);
    }
    while(!good.empty()){
        ll a=good.top().first, b=good.top().second;
        good.pop();
        score += a*k;
        if(b != 1) good.push({-b,1});
        k = -k;
    }
    cout<<score/2<<endl;
    return 0;
}