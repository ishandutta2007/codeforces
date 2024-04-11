#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
const ll mod = 1e9+7;
mat mul(mat a,mat b)
{
    int n=a.size();
    mat c(n,vec(n));
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j) {
            for(int k=0;k<n;++k) {
                c[i][j]+=a[i][k]*b[k][j];
                while(c[i][j]>=mod*mod) c[i][j]-=mod*mod;
            }
            c[i][j] %= mod;
        }
    return c;
}
mat pow(mat a,ll b)
{
    ll n = a.size();
    mat c(n,vec(n));
    for(int i=0;i<n;++i) c[i][i]=1;
    while(b)
    {
        if(b&1) c=mul(c,a);
        a=mul(a,a);
        b>>=1;
    }
    return c;
}
int main()
{
    ll n,m;
    cin>>n>>m;
    if(n<m) {cout<<1<<endl;return 0;}
    mat a(m,vec(m));
    for(int i=1;i<m;++i) a[i][i-1]=1;
    a[0][0]=1,a[0][m-1]=1;
    mat c = pow(a,n-m+1);
    ll ans = 0;
    for(int i=0;i<m;++i) ans+=c[0][i];
    cout << ans%mod << endl;
}