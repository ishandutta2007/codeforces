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
#include<sstream>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define tm(a,b,c) max(max(a,b),c)
#define inf 0x3f3f3f3f
const ll Mod=1e9+7;
#define maxn 50010
using namespace std;
int dd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int vv[1000005],oo[1000005];
string s;
int main()
{
    cin>>s;
    int len=s.length();
    int v=0,o=0,ss=0,vvv=0,ooo=0;
    ll sum=0;
    int flag=0,ff=0;
    int i=0;
    while(i<len)
    {
        if(s[i]=='v')
        {
            if(i<len-1&&s[i+1]=='v')
            {
                if(o)
                {
                    oo[ooo++]=o;
                    o=0;
                }
                while(s[i]=='v')
                {
                    v++;
                    i++;
                }
            }
            else
                i++;
        }
        else if(s[i]=='o')
        {
            if(v>1)
            {
                vv[vvv++]=v-1;
                v=0;
            }
            if(vvv)
            {
                while(s[i]=='o')
                {
                    o++;
                    i++;
                }
            }
            else
                i++;
        }
    }
    if(v>1)
    {
        vv[vvv++]=v-1;
        v=0;
    }
    if(vvv<2)
        cout<<0;
    else
    {
        for(int i=1;i<=vvv;i++)
        {
            vv[i]=vv[i]+vv[i-1];
        }
        for(int i=0;i<vvv;i++)
        {
            sum+=(1ll*oo[i]*vv[i]*(vv[vvv-1]-vv[i]));
        }
        cout<<sum<<endl;
    }
    return 0;
}