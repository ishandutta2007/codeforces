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
#include <functional>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define tm(a,b,c) max(max(a,b),c)
#define inf 0x3f3f3f3f
const ll Mod=1e9+7;
#define maxn 11000
using namespace std;
int a[300005],b[300005];
int aa[1500010],bb[1500010];
int dd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int s=0;
void jh(int q,int w)
{
    aa[s]=min(q,w);
    bb[s++]=max(q,w);
    swap(b[a[q]],b[a[w]]);
    swap(a[q],a[w]);
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=i)
        {
            int id=b[i];
            int d=i;
            if(2*(id-d)>=n)
                jh(id,d);
            else if(2*(d-1)>=n)
            {
                jh(1,d);
                jh(1,id);
                jh(1,d);
            }
            else if(2*(n-id)>=n)
            {
                jh(n,d);
                jh(n,id);
                jh(n,d);
            }
            else
            {
                jh(n,d);
                jh(1,id);
                jh(1,n);
                jh(n,d);
                jh(1,id);
            }
        }
    }
    cout<<s<<endl;
    for(int i=0;i<s;i++)
    {
        cout<<aa[i]<<' '<<bb[i]<<endl;
    }
    return 0;
}