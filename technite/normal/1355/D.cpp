#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define pb push_back
#define forn(i, n) for(int i = 0; i < n; ++i)
#define forl(i, n) for(long long i=0;i<n;++i)
typedef double dd;
typedef long long ll;

int main()
{
    int n,s;
    cin>>n>>s;
    vector<int> v(n);
    if(s>=2*n)
    {
        cout<<"YES"<<"\n";
        for(int i=0;i<n-1;i++)
        {
            cout<<2<<" ";
        }
        cout<<s-2*(n-1);
        cout<<"\n"<<1<<"\n";
    }
    else cout<<"NO";

}