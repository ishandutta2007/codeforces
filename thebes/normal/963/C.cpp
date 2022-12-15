#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double eps = 1e-13;
const ll MN = 2e5+5;
map<ll,ll> x, y, cx, cy;
struct idk{ll a, b, c;}arr[MN];
vector<ll> vec[MN];
ll n, g[MN], r, c, i, j; bool flag;
ll gcd(ll a,ll b){return !a?b:gcd(b%a,a);}

int main(){
    for(scanf("%lld",&n),i=1;i<=n;i++){
        scanf("%lld%lld%lld",&arr[i].a,&arr[i].b,&arr[i].c);
        x[arr[i].a]=0; y[arr[i].b]=0;
    }
    auto it = x.begin();
    for(i=0;it!=x.end();it++) it->second=++i;
    it = y.begin();
    for(i=0;it!=y.end();it++) it->second=++i;
    for(i=1;i<=n;i++){
        arr[i].a=x[arr[i].a];
        arr[i].b=y[arr[i].b];
        cx[arr[i].a]++;
        cy[arr[i].b]++;
    }
    for(auto v : cx)
        if(v.second != y.size()) flag = 1;
    for(auto v : cy)
        if(v.second != x.size()) flag = 1;
    if(flag) printf("0\n");
    else{
        sort(arr+1,arr+n+1,[](idk i,idk j){return i.a==j.a?i.b<j.b:i.a<j.a;});
        for(i=1;i<=n;i++) vec[arr[i].a].push_back(arr[i].c);
        r = x.size(); c = y.size();
        for(i=1;i<=r;i++) vec[i].insert(vec[i].begin(),0);
        for(j=1;j<=c;j++){
            for(i=1;i<=r;i++)
                g[j]=gcd(g[j],vec[i][j]);
        }
        for(j=1;j<c;j++){
            long double rt = (vec[1][j]/g[j])/(long double)(vec[1][j+1]/g[j+1]);
            for(i=2;i<=r;i++){
                long double rt2 = (vec[i][j]/g[j])/(long double)(vec[i][j+1]/g[j+1]);
                if(abs(rt-rt2)>eps) flag = 1;
            }
        }
        if(flag) printf("0\n");
        else{
            ll lol = 0;
            for(i=1;i<=n;i++)
                lol = gcd(lol, arr[i].c);
            ll ans = 0;
            for(ll i=1;i*i<=lol;i++){
                if(lol%i==0){
                    if(i*i!=lol) ans++;
                    ans ++;
                }
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}