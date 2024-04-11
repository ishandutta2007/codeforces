#include<iostream>
#include<stdio.h>
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
#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=200005;
const ll Mod=1000000007;



int main()
{
    sync;
    int n,sx,sy,x,y;
    cin>>n>>sx>>sy;
    int a=0,b=0,c=0,d=0;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        if(x<sx)
            a++;
        if(x>sx)
            c++;
        if(y>sy)
            b++;
        if(y<sy)
            d++;
    }
    int zd=max(max(a,b),max(c,d));
    cout<<zd<<endl;
    if(a==zd&&(sx>0))
    {
        cout<<sx-1<<' '<<sy<<endl;
    }
    else if(b==zd&&(sy<1000000000))
    {
        cout<<sx<<' '<<sy+1<<endl;
    }
    else if(c==zd&&(sx<1000000000))
    {
        cout<<sx+1<<' '<<sy<<endl;
    }
    else
    {
        cout<<sx<<' '<<sy-1<<endl;
    }
    return 0;
}