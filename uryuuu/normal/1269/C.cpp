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
const ll Mod=1e9+7;

int a[maxn],b[maxn];

string s;

int main()
{
    sync;
    int n,k;
    cin>>n>>k;
    cin>>s;
    for(int i=0;i<n;i++)
        a[i]=int(s[i]-'0');
    int f=0;
    int d;
    int p;
    for(int i=k;i<n;i++)
    {
        if(a[i]<a[i-k])
            break;
        if(a[i]>a[i-k])
            f=1;
    }
    
    
    for(int i=0;i<k;i++)
    {
        d=a[i];
        if(d<9)
            p=i;
        for(int j=i;j<n;j+=k)
        {
            a[j]=d;
        }
    }
    
    if(f)
    {
        d=a[p];
        for(int j=p;j<n;j+=k)
        {
            a[j]=d+1;
        }
        for(int i=p+1;i<k;i++)
       {
           for(int j=i;j<n;j+=k)
           {
               a[j]=0;
           }
       }
    }
    
    cout<<n<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i];
    cout<<endl;
    return 0;
}