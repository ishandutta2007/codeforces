#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

int u[N],v[N],cnt[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x,s;
    cin>>x>>s;
    if(x>s)
        cout<<-1,exit(0);
    if(x%2!=s%2)
        cout<<-1,exit(0);
    int a=x,b=(s-x)/2,c=(s-x)/2;
    if(!a&&!b)
        cout<<0<<"\n";
    else if(!a)
        cout<<2<<"\n"<<b<<" "<<c;
    else if(!b)
        cout<<1<<"\n"<<a;
    else if(!(a&b))
        cout<<2<<"\n"<<(a|b)<<" "<<c;
    else
        cout<<3<<"\n"<<a<<" "<<b<<" "<<c;
}