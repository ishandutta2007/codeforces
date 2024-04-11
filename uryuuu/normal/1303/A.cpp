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


string s;

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        int l,r;
        int f=0;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                r=i;
                if(f==0)
                    l=i;
                f=1;
            }
        }
        if(f==0)
        {
            cout<<0<<endl;
            continue;
        }
        int ss=0;
        for(int i=l;i<=r;i++)
        {
            if(s[i]=='0')
                ss++;
        }
        cout<<ss<<endl;
    }
    return 0;
}