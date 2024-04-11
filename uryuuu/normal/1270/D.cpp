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
const int maxn=300005;
const ll Mod=1e9+7;


int a[1000],b[1000],c[10];

string s;
int main()
{
    sync;
    int n,k,pos,x;
    cin>>n>>k;
    for(int i=1;i<=k+1;i++)
    {
        cout<<"?";
        for(int j=1;j<=k+1;j++)
        {
            if(j!=i)
            {
                cout<<' '<<j;
            }
        }
        cout<<endl;
        cin>>pos>>x;
        a[pos]++;
        b[pos]=x;
    }
    int cnt=0;
    for(int i=1;i<=k+1;i++)
    {
        if(a[i])
        {
            if(cnt==0)
                c[cnt++]=i;
            else
            {
                cout<<"! ";
                if(b[i]>b[c[0]])
                    cout<<a[i]<<endl;
                else
                    cout<<a[c[0]]<<endl;
            }
        }
    }
    return 0;
}