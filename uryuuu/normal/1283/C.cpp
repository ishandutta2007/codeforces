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
 
 
int a[maxn];
int v[maxn];
int b[maxn];
int s[maxn];
int main()
{
    sync;
    int n;
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==0)
        {
            s[cnt++]=i;
        }
        else
        {
            v[a[i]]=1;
        }
    }
    int p=0;
    for(int i=1;i<=n;i++)
    {
        if(v[i]==0)
            b[p++]=i;
    }
    sort(b,b+cnt);
    sort(s,s+cnt);
    for(int i=0;i<cnt;i++)
    {
        a[s[i]]=b[(i+1)%cnt];
    }
    for(int i=0;i<cnt-1;i++)
    {
        if(a[s[i]]==s[i])
        swap(a[s[i]],a[s[i+1]]);
    }
    if(a[s[cnt-1]]==s[cnt-1])
        swap(a[s[cnt-2]],a[s[cnt-1]]);
    for(int i=1;i<=n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
    
    return 0;
}