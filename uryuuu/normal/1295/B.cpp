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
const ll Mod=1e9+7;

string s;
int a[maxn];

int main()
{
    sync;
    int t;
    cin>>t;
    int n,x;
    string s;
    while(t--)
    {
        cin>>n>>x>>s;
        a[0]=0;
        int f=0;
        if(x==0)
            f++;
        for(int i=0;i<n;i++)
        {
            a[i+1]=a[i];
            if(s[i]=='1')
                a[i+1]--;
            else
                a[i+1]++;
            if(a[i+1]==x)
                f++;
        }
        int d=a[n];
        if(d==0)
        {
            if(f)
                cout<<-1<<endl;
            else
                cout<<0<<endl;
            continue;
        }
        f=0;
        if(x==0)
            f++;
        for(int i=1;i<=n;i++)
        {
            if((x-a[i])%d==0&&(x-a[i])/d>=0)
                f++;
        }
        cout<<f<<endl;
    }
    return 0;
}