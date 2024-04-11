#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second\

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(b*c<a)
        {
            cout<<-1<<"\n";
            continue;
        }
        int k=min((a+(b*d)-1)/(b*d),(c-1)/d+1);
//        cout<<k<<" -> ";
        cout<<k*a-k*(k-1)/2*b*d<<"\n";
    }
}