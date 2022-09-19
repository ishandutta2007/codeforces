#include <bits/stdc++.h>

using namespace std;
#define int long long
#define cd complex<double>
const double pi=3.14159265358979;
const double eps=1e-3;
mt19937 rnd;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rnd.seed(228);
    int n;cin>>n;string s;cin>>s;vector<int> a(n);cd ans;for(int i=0;i<n;++i) {a[i]=s[i]-'0';}
    for(int iter=0;iter<100;++iter)
    {
        int u=rnd()%n;if(__gcd(u,n)>1) {--iter;continue;}
    ans=0;for(int i=0;i<n;++i) {ans+=((a[i]+0.0)*(cd(cos(2*pi*i*u/n),sin(2*pi*i*u/n))));}
    if(abs(ans)>eps)
    {
        cout<<"NO";return 0;
    }
    }
    cout<<"YES";
    return 0;
}