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
 
 
int a[maxn],b[maxn];
int v[maxn];

int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        b[i]=a[i];
    int zx=0;
    int cnt=unique(b+1,b+n+1)-b-1;
//    for(int i=1;i<=cnt;i++)
//        cout<<b[i]<<' ';
//    cout<<endl;
    int s=0;
    for(int i=1;i<=cnt;i++)
    {
        s=0;
        zx++;
        if(i+1<=cnt&&b[i]==b[i+1]-1)
        {
            s++;
            if(i+2<=cnt&&b[i]==b[i+2]-2)
            {
                s++;
            }
        }
        else if(i+1<=cnt&&b[i]==b[i+1]-2)
        {
            s++;
        }
        i+=s;
    }
    int zd=0;
    for(int i=1;i<=n;i++)
    {
        if(v[a[i]-1]==0)
        {
            v[a[i]-1]=1;
            zd++;
            continue;
        }
        if(v[a[i]]==0)
        {
            v[a[i]]=1;
            zd++;
            continue;
        }
        if(v[a[i]+1]==0)
        {
            v[a[i]+1]=1;
            zd++;
            continue;
        }
    }
    cout<<zx<<' '<<zd<<endl;
    return 0;
}