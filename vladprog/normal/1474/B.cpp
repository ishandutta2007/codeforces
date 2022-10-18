#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int D=25000;

int lp[D+1];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    set<int> pr;
    for(int i=2;i<=D;i++)
    {
        if(lp[i]==0)
            lp[i]=i,
            pr.insert(i);
        for(int p:pr)
        {
            if(p>lp[i]||p*i>D)
                break;
            lp[p*i]=p;
        }
    }

    int t;
    cin>>t;
    while(t--)
    {
        int d;
        cin>>d;
        int p=*pr.lower_bound(d+1);
        int q=*pr.lower_bound(p+d);
        cout<<min(p*p*p,p*q)<<"\n";
    }
}