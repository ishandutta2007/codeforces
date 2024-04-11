#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
#define int ll

typedef pair<int,int> pii;
#define x first
#define y second

typedef pair<int,int> frac;
#define num first
#define den second

frac norm(frac a)
{
    int g=__gcd(a.num,a.den);
    a.num/=g;
    a.den/=g;
    if(a.den<0)
        a.num*=-1,
        a.den*=-1;
    return a;
}

frac add(frac a,frac b)
{
    a=norm(a);
    b=norm(b);
    int den=a.den/__gcd(a.den,b.den)*b.den;
    a.num*=den/a.den;
    b.num*=den/b.den;
    return norm(frac(a.num+b.num,den));
}

const int N=1e5+100;

int a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    frac ans(0,1);
    for(int i=1;i<=n;i++)
    {
        ans=add(ans,frac(a[i],n));
        ans=add(ans,frac(a[i]*(n-1)*(i-1),n*(n-1)));
        ans=add(ans,frac(a[i]*(n-1)*(i-1),n*(n-1)));
        ans=add(ans,frac(-a[i]*(n-1)*(n-i),n*(n-1)));
        ans=add(ans,frac(-a[i]*(n-1)*(n-i),n*(n-1)));
    }
    cout<<ans.num<<" "<<ans.den;
}