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

int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

string s;
int main()
{
    sync;
    int r,c;
    cin>>r>>c;
    int cc;
    if(r==1&&c==1)
    {
        cout<<0<<endl;
        return 0;
    }
    if(c==1)
    {
        for(int i=1;i<=r;i++)
        {
            cout<<i+1<<endl;
        }
    }
    else
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            cc=r+j;
            cout<<i*cc/(gcd(i,cc))<<' ';
        }
        cout<<endl;
    }
    return 0;
}