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
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define tm(a,b,c) max(max(a,b),c)
#define inf 0x3f3f3f3f
const ll Mod=998244353;
using namespace std;
int dd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a=-100000,w=100000,s=-100000,d=100000;
        int n;
        cin>>n;
        int x,y,f1,f2,f3,f4;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d%d%d%d",&x,&y,&f1,&f2,&f3,&f4);
            if(f1==0)
                a=max(x,a);
            if(f2==0)
                w=min(y,w);
            if(f3==0)
                d=min(x,d);
            if(f4==0)
                s=max(s,y);
        }
        if(a>d||s>w)
            cout<<0<<endl;
        else
            cout<<1<<' '<<a<<' '<<s<<endl;
    }
    return 0;
}