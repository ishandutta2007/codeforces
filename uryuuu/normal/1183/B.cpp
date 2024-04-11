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
const ll Mod=1e9+7;
using namespace std;
int dd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int a[105];
int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int n,k;
        int zd=-2;
        int zx=100000008;
        cin>>n>>k;
        int w;
        for(int i=0;i<n;i++)
        {
            cin>>w;
            zx=min(w,zx);
            zd=max(w,zd);
        }
        if((zd-zx)>2*k)
        {
            cout<<-1<<endl;
        }
        else
            cout<<zx+k<<endl;
    }
    return 0;
}