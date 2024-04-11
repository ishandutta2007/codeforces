#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair

const int INF=1e18;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n,m,cl,ce,v;
    cin>>n>>m>>cl>>ce>>v;
    set<int> l{-INF,INF};
    while(cl--)
    {
        int x;
        cin>>x;
        l.insert(x);
    }
    set<int> e{-INF,INF};
    while(ce--)
    {
        int x;
        cin>>x;
        e.insert(x);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        if(x1==x2)
            cout<<abs(y1-y2)<<"\n";
        else
        {
            int ans=INF,p;
            p=*l.lower_bound(y1);       ans=min(ans,abs(y1-p)+(abs(x1-x2)+1-1)/1+abs(p-y2));
            p=*prev(l.upper_bound(y1)); ans=min(ans,abs(y1-p)+(abs(x1-x2)+1-1)/1+abs(p-y2));
            p=*e.lower_bound(y1);       ans=min(ans,abs(y1-p)+(abs(x1-x2)+v-1)/v+abs(p-y2));
            p=*prev(e.upper_bound(y1)); ans=min(ans,abs(y1-p)+(abs(x1-x2)+v-1)/v+abs(p-y2));
            cout<<ans<<"\n";
        }
    }
}