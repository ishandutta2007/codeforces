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
typedef pair<int,int> pii;
const int maxn=200005;
const ll Mod=1000000007;
 
 
int a[maxn],b[maxn<<1];
map<int,int>mp;
//map<int,int>v;

int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    int cnt=0;
    int last=0;
    int x;
    int ct;
    ll sum=0;
    while(cnt<m)
    {
        ct=cnt;
        if(cnt==0)
        {
            for(int i=0;i<n;i++)
            {
                x=a[i]-1;
                if(mp[x]==0)
                {
                    b[cnt++]=x;
                    mp[x]=1;
                    sum++;
//                    cout<<x<<' '<<a[i]<<endl;
                }
                if(cnt==m)
                    break;
                x=a[i]+1;
                if(mp[x]==0)
                {
                    b[cnt++]=x;
                    mp[x]=1;
                    sum++;
//                    cout<<x<<' '<<a[i]<<endl;
                }
                if(cnt==m)
                    break;
            }
        }
        else
        {
            for(int i=last;i<ct;i++)
            {
                x=b[i]-1;
                if(mp[x]==0)
                {
                    b[cnt++]=x;
                    mp[x]=mp[b[i]]+1;
//                    cout<<x<<' '<<mp[x]<<' '<<mp[b[i]]<<endl;
                    sum+=1ll*mp[x];
                }
                if(cnt==m)
                    break;
                x=b[i]+1;
                if(mp[x]==0)
                {
                    b[cnt++]=x;
                    mp[x]=mp[b[i]]+1;
//                    cout<<x<<' '<<mp[x]<<' '<<mp[b[i]]<<endl;
                    sum+=1ll*mp[x];
                }
                if(cnt==m)
                    break;
            }
        }
        last=ct;
    }
    cout<<sum<<endl;
    for(int i=0;i<m;i++)
        cout<<b[i]<<' ';
    cout<<endl;
    return 0;
}