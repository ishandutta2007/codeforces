#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<set>
#include<map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define maxn 300050
using namespace std;
int a[105];
int main()
{
    int t,n,m,k;
    cin>>t;
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        int w=0;
        int flag=0;
        while(w<n-1)
        {
            int r=max(a[w+1]-k,0);
            if(a[w]>=r)
            {
                m+=(a[w]-r);
            }
            else
            {
                if(m<r-a[w])
                {
                    flag=1;
                    break;
                }
                else
                {
                    m-=(r-a[w]);
                }
            }
            w++;
        }
        if(flag==1)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}