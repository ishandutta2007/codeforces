#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

int a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed<<setprecision(10);

    int t;
    cin>>t;
    while(t--)
    {
        int n,l;
        cin>>n>>l;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int i=1,j=n;
        int v=1,u=1;
        ld x=0,y=l,t=0;
        while(i<=j)
        {
            ld d1=(a[i]-x)/v;
            ld d2=(y-a[j])/u;
            if(d1<d2)
            {
                x=a[i];
                v++;
                t+=d1;
                i++;
                y-=d1*u;
            }
            else
            {
                y=a[j];
                u++;
                t+=d2;
                j--;
                x+=d2*v;
            }
//            cout<<t<<" :\n"<<i<<" "<<j<<"\n"<<x<<" "<<y<<"\n"<<v<<" "<<u<<"\n\n";
        }
        t+=(y-x)/(v+u);
        cout<<t<<"\n";
    }
}