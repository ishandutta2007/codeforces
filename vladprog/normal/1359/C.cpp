#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const ld one=1;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int h,c,t;
        cin>>h>>c>>t;
        h-=c,t-=c;
        h*=2,t*=2;
        if(t<=h/2)
        {
            cout<<2<<"\n";
            continue;
        }
        int x=h/(2*t-h);
        if(x%2==0)
            x--;
        if(x<1)
            x=1;
        int y=x+2;
        int a=h*(x*y+y)-2*x*y*t;
        int b=h*(x*y+x)-2*x*y*t;
        if(a<0) a=-a;
        if(b<0) b=-b;
        if(a<=b)
            cout<<x<<"\n";
        else
            cout<<y<<"\n";
    }
}