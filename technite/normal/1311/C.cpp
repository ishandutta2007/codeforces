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
        int n,m;
        string s;
        cin>>n>>m>>s;
        vector <long> a(26), b(n);
        for(int i=0;i<m;i++)
        {
            int k;
            cin>>k;
            b[k-1]++;
        }
        int j=1;
        for(int i=n;i>0;i--)
        {
            j+=b[i-1];
            a[(s[i-1])-'a']+=j;
        }
        for(auto x : a)
            cout<<x<<' ';
        cout<<"\n";
    }
}