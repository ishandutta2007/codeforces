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
        int n;
        cin>>n;
        int a[n+1];
        for(int i=1;i<=n;i++)
            cin>>a[i];
        bool yes=false;
        for(int mask=1;;mask++)
        {
            int temp=mask;
            int sum=0;
            for(int i=1;i<=n;i++)
            {
                int cur=temp%3;
                if(cur==1)
                    sum-=a[i];
                else if(cur==2)
                    sum+=a[i];
                temp/=3;
            }
            if(temp)
                break;
            if(!sum)
            {
//                cout<<mask<<" ";
                yes=true;
                break;
            }
        }
        cout<<(yes?"YES\n":"NO\n");
    }
}