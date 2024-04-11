#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

int n;
int a[N],s[N];

int sum(int l,int r)
{
    l=max(l,1ll);
    r=min(r,n);
    return s[r]-s[l-1];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int d,b;
    cin>>n>>d>>b;
    for(int i=1;i<=n;i++)
        cin>>a[i],
        s[i]=s[i-1]+a[i];
    int x1=0;
    for(int i=1;i<=(n+1)/2;i++)
    {
        int cnt=sum(i-i*d,i+i*d);
//        cout<<i<<" -> "<<i-i*d<<".."<<i+i*d<<" -> "<<cnt<<" -> "<<cnt/b<<" -> "<<i-cnt/b<<"\n";
        cnt/=b;
        x1=max(x1,i-cnt);
    }
    int x2=0;
    for(int i=1;i<=n/2;i++)
    {
        int cnt=sum(n+1-i-i*d,n+1-i+i*d);
//        cout<<i<<" -> "<<n+1-i-i*d<<".."<<n+1-i+i*d<<" -> "<<cnt<<" -> "<<cnt/b<<" -> "<<i-cnt/b<<"\n";
        cnt/=b;
        x2=max(x2,i-cnt);
    }
    cout<<max(x1,x2);
}