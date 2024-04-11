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

//    int t;
//    cin>>t;
//    while(t--)
//    {
        int n,k;
        cin>>n>>k;
        vector<int> x,y,z;
        while(n--)
        {
            int t,a,b;
            cin>>t>>a>>b;
            if(a)
                if(b)
                    x.push_back(t);
                else
                    y.push_back(t);
            else
                if(b)
                    z.push_back(t);
        }
        sort(y.begin(),y.end());
        sort(z.begin(),z.end());
        for(int i=0;i<min(y.size(),z.size());i++)
            x.push_back(y[i]+z[i]);
        sort(x.begin(),x.end());
        if(x.size()>=k)
            cout<<accumulate(x.begin(),x.begin()+k,0ll)<<"\n";
        else
            cout<<-1<<"\n";
//    }
}