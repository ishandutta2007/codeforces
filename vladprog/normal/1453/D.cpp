#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        if(k%2)
        {
            cout<<-1<<"\n";
            continue;
        }
        k/=2;
        vector<int> ans;
        while(k)
        {
            int len=1;
            while( (1ll<<(len+1))-1 <= k )
                len++;
            ans.push_back(1);
            ans.insert(ans.end(),len-1,0);
            k-=(1ll<<len)-1;
//            cout<<len<<" "<<k<<endl;
        }
        cout<<ans.size()<<"\n";
        for(int x:ans)
            cout<<x<<" ";
        cout<<"\n";
    }
}