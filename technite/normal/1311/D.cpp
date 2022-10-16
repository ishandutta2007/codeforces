#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define append push_back
#define forn(i, n) for(int i = 0; i < n; ++i)
#define forl(i, n) for(long long i=0;i<n;++i)

typedef long long ll;
ll exp(ll n, ll m, ll md){
    ll a = 1;
    while (m > 0){
        if (m&1) a = (a * n%md) % md;
        m /= 2;
        n = (n*n) % md;
    }
    return a % md;
}
int main()
{
    long t;
    cin>>t;
    while(t--)
    {
        int a, b, c;
        cin>>a>>b>>c;
        int ans=INT_MAX;
        int a1, b1, c1;
        for(int i = 1;i <= 10000;i++) {
            for(int j = i;j <= 14000;j += i) {
                int sum=abs(i - a) + abs(j - b) + min(c%j,j-c%j);
                if (ans>sum) 
                {
                    ans=sum;
                    a1=i;
                    b1=j;
                    if (c%j<j-c%j) c1=c-c%j;
                    else c1=c+j-c%j;
                }
            }
        }
        cout<<ans<<"\n";
        cout<<a1<<" "<<b1<<" "<<c1<<"\n";
    }
}