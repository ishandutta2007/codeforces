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


int n;
string s;
int a[1000];

int main()
{
    sync;
    cin>>n>>s;
    int b=0,w=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='B')
            b++;
        else
            w++;
    }
    if(b%2&&w%2)
    {
        cout<<-1<<endl;
        return 0;
    }
    int cnt=0;
    if(b%2==0)
    {
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=='B')
            {
                a[cnt++]=i+1;
                if(s[i+1]=='B')
                    s[i+1]='W';
                else
                    s[i+1]='B';
            }
        }
    }
    else
    {
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=='W')
            {
                a[cnt++]=i+1;
                if(s[i+1]=='B')
                    s[i+1]='W';
                else
                    s[i+1]='B';
            }
        }
    }
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++)
        cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}