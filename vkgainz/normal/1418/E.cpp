#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 998244353;
ll inv(ll b, ll p){
    if(b==1) return 1;
    if(p==0) return 1;
    ll x = inv(b,p/2);
    if(p%2==1){
        return (((x*x)%mod*b)%mod+mod)%mod;
    }
    else{
        return ((x*x)%mod+mod)%mod;
    }
}
struct fraction{
    ll x,y;
    void reduce(){
        x%=mod;
        y%=mod;
        if(x<0) x+=mod;
        if(y<0) y+=mod;
        ll gcd = __gcd(x,y);
        x/=gcd;
        y/=gcd;
    }
    fraction add(fraction a){
        reduce();
        a.reduce();
        fraction ret;
        ret.x = x*a.y+y*a.x;
        ret.y = y*a.y;
        ret.reduce();
        return ret;
    }
    fraction subtract(fraction a){
        reduce();
        a.reduce();
        fraction ret;
        ret.x = x*a.y-a.x*y;
        ret.y = y*a.y;
        ret.reduce();
        return ret;
    }
    fraction multiply(fraction a){
        reduce();
        a.reduce();
        fraction ret;
        ret.x = x*a.x;
        ret.y = y*a.y;
        ret.reduce();
        return ret;
    }
};
fraction ans[200001];
ll sumgreater;
ll sumless;
ll sumtot;
int g,l;
multiset<int> vals;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        int d; scanf("%d",&d);
        sumtot+=d;
        vals.insert(d);
    }
    sumgreater = sumtot;
    vector<pair<pair<int,int>,int>> queries;
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        queries.push_back(make_pair(make_pair(b,a),i));
    }
    sort(queries.begin(),queries.end());
    g = n;
    for(int i=0;i<m;i++){
        int a = queries[i].first.second;
        int b = queries[i].first.first;
        auto it = vals.begin();
        while(it!=vals.end() && (*it)<b){
            sumgreater-=(*it);
            sumless+=(*it);
            --g; ++l;
            vals.erase(it++);
            sumless%=mod;
            sumgreater%=mod;
        }
        if(a<=g){
            fraction first;
            first.x = a*sumless;
            first.y = g+1;
            fraction second;
            second.x = a*sumgreater;
            second.y = g;
            first = first.add(second);
            ans[queries[i].second] = first;
        }
        else{
            ans[queries[i].second].x = sumtot;
            ans[queries[i].second].y = 1;
        }
    }
    for(int i=0;i<m;i++){
        fraction take;
        take.x = sumtot;
        take.y = 1;
        ans[i] = take.subtract(ans[i]);
        ans[i].x*=inv(ans[i].y,mod-2);
        ans[i].x%=mod;
        if(ans[i].x<0) ans[i].x+=mod;
        cout << ans[i].x << endl;
    }
}