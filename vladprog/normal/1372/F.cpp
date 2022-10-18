#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int a[N];

pii ask(int l,int r)
{
    cout<<"? "<<l<<" "<<r<<endl;
    int x;
    cin>>x;
    if(x==-1)
        exit(0);
    int f;
    cin>>f;
    return {x,f};
}

void solve(int l,int r)
{
    if(l>r)
        return;
    int x,f;
    tie(x,f)=ask(l,r);
    int l1=r+1-f,r1=l-1+f;
    if(l1<=r1)
    {
        for(int i=l1;i<=r1;i++)
            a[i]=x;
        solve(l,l1-1);
        solve(r1+1,r);
    }
    else
    {
        int m=(l+r)/2;
        solve(l,m);
        solve(m+1,r);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    solve(1,n);
    cout<<"! ";
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}