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
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=100005;
 
const ll Mod=1000000007;
 
int a[maxn],v[1000005],c[maxn],vis[maxn];
 
int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int pos=1;
    int cnt=0;
    int s=0;
    int d=1;
    int f=0;
    int cc=0;
    while(pos<=n)
    {
        if(a[pos]>0)
        {
            if(v[a[pos]])
            {
                if(s==0&&v[a[pos]]==2)
                {
                    s=1;
                    c[cnt++]=pos-d;
                    d=pos;
                    for(int i=0;i<cc;i++)
                    {
                        v[vis[i]]=0;
                    }
                    v[a[pos]]=1;
                    cc=0;
                    vis[cc++]=a[pos];
                }
                else
                {
                    f=1;
//                    if(a[1]==160486)
//                    cout<<pos<<' '<<s<<' '<<cnt<<' '<<v[a[pos]]<<' '<<cc<<' '<<endl;
//                    cout<<"JK"<<endl;
                    break;
                }
            }
            else
            {
                v[a[pos]]=1;
//                cout<<a[pos]<<' '<<v[a[pos]]<<endl;
                s++;
                vis[cc++]=a[pos];
            }
        }
        if(a[pos]<0)
        {
            if(v[-a[pos]]==1)
            {
                v[-a[pos]]=2;
                s--;
                if(s==0)
                {
                    c[cnt++]=pos-d+1;
                    d=pos+1;
                    for(int i=0;i<cc;i++)
                    {
                        v[vis[i]]=0;
                    }
                    cc=0;
                }
            }
            else
            {
//                cout<<pos<<' '<<a[pos]<<' '<<v[-a[pos]]<<endl;
//                cout<<"JK"<<endl;
                f=1;
                break;
            }
        }
        pos++;
    }
    if(f==1)
    {
        cout<<-1<<endl;
    }
    else
    {
        if(s==0)
        {
            if(n-d+1)
                cout<<cnt+1<<endl;
            else
                cout<<cnt<<endl;
            for(int i=0;i<cnt;i++)
            {
                cout<<c[i]<<' ';
            }
            if(n-d+1)
                cout<<n-d+1<<endl;
            else
                cout<<endl;
        }
        else
            cout<<-1<<endl;
    }
    return 0;
}