#include<bits/stdc++.h>

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
        int n,k;
        cin>>n>>k;
        multiset<int> s;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin>>a;
            a%=k;
            a=k-a;
            a%=k;
            if(a)
                s.insert(a);
        }
        int x=0;
        while(!s.empty())
        {
            auto it=s.lower_bound(x%k);
            if(it==s.end())
                it=s.begin();
//            cout<<x<<" -> "<<*it<<"\n";
            x+=(*it-x%k+k)%k;
            s.erase(it);
            x++;
        }
        cout<<x<<"\n";
    }
}