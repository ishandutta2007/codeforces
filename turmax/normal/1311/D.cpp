#include <bits/stdc++.h>

using namespace std;
#define int long long
pair<int,int> dist(int x,int y)
{
    int a=x-(x/y)*y;
    int b=(x/y+1)*y-x;
    if(a<=b)
    {
        return {a,(x/y)*y};
    }
    else
    {
        return {b,(x/y+1)*y};
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int cyc=0;cyc<t;++cyc)
    {
        int a,b,c;
        int res[3];
        cin>>a>>b>>c;
        int ans=1e18;
        for(int i=1;i<=30000;++i) {
            int s = abs(a - i);
            if (i == 0) {
                continue;
            }
            for (int j = i; j <= 30000; j += i)
            {
                if(j==0)
                {
                    continue;
                }
                int s1=abs(b-j);
                pair <int,int> o=dist(c,j);
                if(ans>(o.first)+s+s1)
                {
                    ans=o.first+s+s1;
                    res[0]=i;
                    res[1]=j;
                    res[2]=o.second;
                }
            }
        }
        cout<<ans<<endl;
        cout<<res[0]<<" "<<res[1]<<" "<<res[2]<<endl;
    }
    return 0;
}