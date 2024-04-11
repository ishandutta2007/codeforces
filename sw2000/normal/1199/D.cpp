#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=2e5+10;

int arr[maxn];

struct INS
{
    int a,b,c;
    bool can=1;
}ins[maxn];

bool visit[maxn];

int main()
{
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>ins[i].a>>ins[i].b;
        if(ins[i].a==1)cin>>ins[i].c;
    }

    int ma=-inf;
    for(int i=m-1;i>=0;i--)
    {
        if(ins[i].a==2)ma=max(ma,ins[i].b);

        if(ins[i].a==1)
        {
            if(!visit[ins[i].b])
            {
                visit[ins[i].b]=1;
                if(ins[i].c<=ma)
                {
                    ins[i].c=ma;
                }
            }
            else
            {
                ins[i].can=0;
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        arr[i]=max(arr[i],ma);
    }

    for(int i=0;i<m;i++)
    {
        if(ins[i].a==1&&ins[i].can)
        {
            arr[ins[i].b]=ins[i].c;
        }
    }

    for(int i=1;i<=n;i++)cout<<arr[i]<<' ';
    return 0;
}