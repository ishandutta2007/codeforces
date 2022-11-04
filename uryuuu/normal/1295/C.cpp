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

int t;
string s,h;
int a[maxn][30];

int id(char s)
{
    return int(s-'a')+1;
}
int main()
{
    sync;
    cin>>t;
    while(t--)
    {
        cin>>s>>h;
        int n=s.length();
        int len=h.length();
        for(int i=0;i<=26;i++)
        {
            a[n][i]=9999999;
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=1;j<=26;j++)
                a[i][j]=a[i+1][j];
            a[i][id(s[i])]=i;
        }
        int cnt=1;
        int p=0;
        int f=0;
        for(int i=0;i<len;i++)
        {
//            cout<<h[i]<<' ';
            int x=id(h[i]);
            if(p==n)
            {
               p=0;
               cnt++;
            }
            if(a[p][x]==9999999)
            {
                cnt++;
                p=0;
                if(a[p][x]==9999999)
                {
                    f=1;
//                    cout<<h[i]<<endl;
                    break;
                }
            }
            p=a[p][x]+1;
//            cout<<p<<' ';
        }
        if(f)
            cout<<-1<<endl;
        else
            cout<<cnt<<endl;
    }
    return 0;
}