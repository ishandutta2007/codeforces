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
const int maxn=105;
const ll Mod=1e9+7;

string s;

struct node
{
    int x,y;
}a[1050];

bool cmp(node a,node b)
{
    if(a.x==b.x)
    {
        return a.y<b.y;
    }
    return a.x<b.x;
}

int main()
{
    sync;
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i].x>>a[i].y;
        }
        int f=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i].x>a[j].x&&a[i].y<a[j].y)
                {
                    f=1;
                    break;
                }
            }
            if(f==1)
                break;
        }
        if(f==1)
        {
            cout<<"NO"<<endl;
            continue;
        }
        sort(a,a+n,cmp);
        s="";
        int x=0,y=0;
        for(int i=0;i<n;i++)
        {
            while(x<a[i].x)
            {
                s+='R';
                x++;
            }
            while(y<a[i].y)
            {
                s+='U';
                y++;
            }
        }
        cout<<"YES"<<endl;
        cout<<s<<endl;
    }
    return 0;
}