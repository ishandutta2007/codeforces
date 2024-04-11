#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define pii pair<int,int>
using namespace std;
const ll Mod=1e9+7;
const int maxn=200005;
ll s[60];
int main()
{
    sync;
    ll a,b;
    cin>>a>>b;
    s[0]=1;
    int pos;
    for(int i=1;i<=55;i++)
    {
        s[i]=s[i-1]*2;
    }
    ll d;
    int f=0;
    for(int i=1;i<=40;i++)
    {
        a-=b;
        if(a<=0)
        {
            cout<<-1<<endl;
            return 0;
        }
        d=a;
        for(int j=1;j<=i;j++)
        {
            pos=upper_bound(s,s+50,d)-s-1;
            if(d-s[pos]<(i-j))
            {
                f=0;
                pos--;
                while(pos>=0)
                {
                    if(d-s[pos]<(i-j))
                        pos--;
                    else
                    {
                        d-=s[pos];
                        f=1;
                    }
                }
                if(f==0)
                    break;
            }
            else
                d-=s[pos];
        }
        if(d==0)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}