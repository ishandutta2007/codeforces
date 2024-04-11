#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

int sum(int x,int l,int r)
{
//    cout<<"sum "<<x<<" "<<l<<" "<<r<<endl;
    int res=0;
    while(l<=r)
    {
        int val=x/l;
        int last=(val==0?r:min(r,x/val));
//        cout<<l<<" -> "<<val<<" "<<last<<endl;
        res+=(last-l+1)*val;
        l=last+1;
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        int ans=0,prev=-1;
        for(int b=1;b<=y;b++)
        {
            int cur=min(x,b*(b+1)-1)/(b+1);
//            cout<<b<<" -> "<<cur<<endl;
            ans+=cur;
            if(cur<=prev)
            {
                ans+=sum(x,b+2,y+1);
                break;
            }
            prev=cur;
        }
        cout<<ans<<"\n";
//        cout<<endl;
    }
}