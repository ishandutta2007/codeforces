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
const int maxn=100005;
const ll Mod=1000000007;

string s[100];

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
            cin>>s[i];
        int f=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(s[i][j]=='A')
                {
                    f++;
                }
            }
        }
        if(f==0)
        {
            cout<<"MORTAL"<<endl;
            continue;
        }
        if(f==n*m)
        {
            cout<<0<<endl;
            continue;
        }
        f=0;
        for(int i=0;i<n;i++)
            if(s[i][0]!='A')
            {
                f=1;
                break;
            }
        if(f==0)
        {
            cout<<1<<endl;
            continue;
        }
        
        f=0;
        for(int i=0;i<n;i++)
            if(s[i][m-1]!='A')
            {
                f=1;
                break;
            }
        if(f==0)
        {
            cout<<1<<endl;
            continue;
        }
        
        
        f=0;
        for(int i=0;i<m;i++)
            if(s[0][i]!='A')
            {
                f=1;
                break;
            }
        if(f==0)
        {
            cout<<1<<endl;
            continue;
        }
        
        f=0;
        for(int i=0;i<m;i++)
            if(s[n-1][i]!='A')
            {
                f=1;
                break;
            }
        if(f==0)
        {
            cout<<1<<endl;
            continue;
        }
        
        if(s[0][0]=='A'||s[n-1][0]=='A'||s[0][m-1]=='A'||s[n-1][m-1]=='A')
        {
            cout<<2<<endl;
            continue;
        }
        
        int ff=0;
        for(int i=0;i<n;i++)
        {
            f=0;
            for(int j=0;j<m;j++)
            {
                if(s[i][j]!='A')
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
            {
                ff=1;
                break;
            }
        }
        for(int i=0;i<m;i++)
        {
            f=0;
            for(int j=0;j<n;j++)
            {
                if(s[j][i]!='A')
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
            {
                ff=1;
                break;
            }
        }
        
        if(ff)
        {
            cout<<2<<endl;
            continue;
        }
        
        
        
        
        
        f=0;
        for(int i=0;i<m;i++)
        if(s[n-1][i]=='A')
        {
            f=1;
            break;
        }
        for(int i=0;i<m;i++)
        if(s[0][i]=='A')
        {
            f=1;
            break;
        }
        for(int i=0;i<n;i++)
        if(s[i][m-1]=='A')
        {
            f=1;
            break;
        }
        for(int i=0;i<n;i++)
        if(s[i][0]=='A')
        {
            f=1;
            break;
        }
        
        if(f==1)
        {
            cout<<3<<endl;
            continue;
        }
        
        cout<<4<<endl;
        
        
    }
    return 0;
}