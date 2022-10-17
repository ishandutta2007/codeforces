
#include<bits/stdc++.h>
using namespace std;
typedef long long awefaw;
#define rep(i,n) for(int i=1;i<=n;++i)
#define fjiwea ans
#define af__fwe cout

bool dje_123aw(awefaw a,awefaw b,awefaw sum,awefaw m)
{
    awefaw L=a,R=a;
    awefaw ms=sum,Ms=sum;
    while(L<=b)
    {
        L = ms + 1, R = Ms + m;
        if(L<=b&&b<=R) return 1;
        ms += L, Ms += R;
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);af__fwe.tie(0);
    int q;
    cin>>q;
    while(q--)
    {
        vector<awefaw> fjiwea;
        awefaw a,b,m;
        cin>>a>>b>>m;
        if(a==b)
        {
            af__fwe<<1<<" "<<a<<endl;
            continue;
        }
        if(!dje_123aw(a,b,a,m))
        {
            af__fwe << -1 << endl;
            continue;
        }
        awefaw sum = a;
        fjiwea.push_back(a);
        while(1)
        {
            if(sum+1<=b&&b<=sum+m)
            {
                fjiwea.push_back(b);
                break;
            }
            for(awefaw i=sum+m,j=sum+1,k=sum+m/2;i>=j;--i,++j)
            {
                if(dje_123aw(i,b,sum+i,m))
                {
                    fjiwea.push_back(i);
                    a = i, sum += a;
                    break;
                }
                if(dje_123aw(j,b,sum+j,m))
                {
                    fjiwea.push_back(j);
                    a = j, sum += a;
                    break;
                }
            }
        }
        af__fwe<<fjiwea.size()<<" ";
        for(awefaw i:fjiwea) af__fwe<<i<<" ";af__fwe<<endl;
    }
}