#include<bits/stdc++.h>
 
typedef long long ll;
using namespace std;
//random_device rng;
//mt19937 rd(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

#define int ll
int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        if(a>b) swap(a,b);
        // a <= b
        if(b > 2*a)
        {
            cout << "NO" << endl;
            continue;
        }
        int lo=0,hi=a/3;
        int ok=0;
        while(lo<=hi)
        {
            int mid=(lo+hi)>>1;
            int bb=b-3*mid,aa=a-3*mid;
            if(bb > 2*aa) hi=mid-1;
            else if(bb < 2*aa) lo=mid+1;
            else {ok=1;break;}
        }
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}