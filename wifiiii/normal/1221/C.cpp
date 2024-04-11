#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'
 
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q;
    cin>>q;
    while(q--)
    {
        int c,m,x;
        cin>>c>>m>>x;
        int lo = 0, hi = 1e8;
        while(lo < hi)
        {
            int mid = (lo+hi+1)/2;
            int ok = 1;
            if(c < mid || m < mid) ok = 0;
            if(c+m-mid-mid+x < mid) ok = 0;
            if(ok) lo = mid;
            else hi = mid-1;
        }
        cout<<lo<<"\n";
    }
}