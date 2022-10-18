#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int MOD=1e9+7;

int A(int n,int k)
{
    if(n<0||k<0||k>n)
        return 0;
    int res=1;
    for(int i=n-k+1;i<=n;i++)
        res=res*i%MOD;
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,x,pos;
    cin>>n>>x>>pos;
    int l=0,r=n;
    int ls=0,gr=0;
    while(l<r)
    {
        int m=(l+r)/2;
        if(m==pos)
//            cout<<l<<".."<<r<<" -> "<<m<<": =\n",
            l=m+1;
        else
        {
            if(pos>=m)
//                cout<<l<<".."<<r<<" -> "<<m<<": <\n",
                ls++,
                l=m+1;
            else
//                cout<<l<<".."<<r<<" -> "<<m<<": >\n",
                gr++,
                r=m;
        }
    }
//    cout<<ls<<" "<<gr<<"\n";
//    cout<<x-1<<" "<<ls<<" "<<n-x<<" "<<gr<<" "<<n-ls-gr-1<<"\n";
    cout<<A(x-1,ls)*A(n-x,gr)%MOD*A(n-ls-gr-1,n-ls-gr-1)%MOD;
}