#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N=1e5+100;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,s;
        cin>>n>>s;
        int sum=0,mx=0,pos=0;
        int best=-1,ans=-1;
        #define upd(new_best,new_ans) (new_best>best?(best=new_best,ans=new_ans):0)
        for(int i=1;i<=n;i++)
        {
            int a;
            cin>>a;
            if(a>mx)
                mx=a,
                pos=i;
            sum+=a;
            if(sum<=s)
                upd(i,0);
            if(sum-mx<=s)
                upd(i-1,pos);
        }
        cout<<ans<<"\n";
    }
}