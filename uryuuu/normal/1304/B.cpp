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
const int maxn=100005;
const ll Mod=1000000007;

map<string,int>mp;

string a[105],b[105];

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
    int sum=0;
    string s="";
    for(int i=0;i<n;i++)
    {
        b[i]="";
        for(int j=m-1;j>=0;j--)
        {
            b[i]+=a[i][j];
        }
        if(a[i]==b[i])
            continue;
        if(mp[b[i]])
        {
            s+=a[i];
            mp[a[i]]=0;
            mp[b[i]]=0;
            sum+=m;
        }
    }
//    cout<<s<<endl;
    string ss="";
    int f=0,ff=0;
    for(int i=0;i<n;i++)
    {
        f=0;
       if(mp[a[i]])
       {
           for(int j=0;j<m;j++)
           {
              if(a[i][j]!=a[i][m-1-j])
              {
                  f=1;
                  break;
              }
           }
           if(f==0)
           {
               ss+=a[i];
               ff=1;
               break;
           }
       }
    }
    string c="";
    for(int i=0;i<sum;i++)
    {
        c+=s[i];
    }
    if(ff)
        c+=ss;
    for(int i=sum-1;i>=0;i--)
    {
        c+=s[i];
    }
    sum*=2;
    if(ff)
        sum+=m;
    cout<<sum<<endl;
    cout<<c<<endl;
    return 0;
}