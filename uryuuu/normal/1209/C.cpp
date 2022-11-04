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
const int  maxn=100005;

string s;
int a[200005],b[200005],c[200005],d[200005];

int main()
{
    sync
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cin>>s;
        for(int i=0;i<n;i++)
        {
            a[i]=int(s[i]-'0');
            b[i]=a[i];
        }
        sort(b,b+n);
        int tot=1,tt=1;
        c[0]=0;
        c[1]=0;
        d[0]=0;
        int fl=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]<=b[tot-1])
            {
                d[tot]=a[i];
                a[i]=1;
                if(d[tot]<d[tot-1])
                {
                    fl=1;
                    break;
                }
                tot++;
            }
            else
            {
                c[tt]=a[i];
                a[i]=2;
                if(c[tt]<c[tt-1])
                {
                    fl=1;
                    break;
                }
                tt++;
            }
        }
        if(fl)
        {
            cout<<"-"<<endl;
            continue;
        }
        if(d[tot-1]>c[1]&&(tt!=1))
        {
            cout<<"-"<<endl;
            continue;
        }
        for(int i=0;i<n;i++)
        {
            cout<<a[i];
        }
        cout<<endl;
    }
    return 0;
}