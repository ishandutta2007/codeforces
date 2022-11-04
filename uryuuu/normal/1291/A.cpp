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


string s;
int a[3005];

int main()
{
    sync;
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        cin>>n>>s;
        int z=0;
        int f=0;
        int pos;
        for(int i=n-1;i>=0;i--)
        {
            if(int(s[i]-'0')%2)
            {
                pos=i;
                f=1;
                break;
            }
        }
        if(f==0)
        {
            cout<<-1<<endl;
            continue;
        }
        int p;
        int sum=int(s[pos]-'0');
        for(int i=pos-1;i>=0;i--)
        {
            if(int(s[i]-'0')%2)
            {
                p=i;
                z=1;
            }
            sum+=int(s[i]-'0');
        }
        if(sum%2==0)
        {
            for(int i=0;i<=pos;i++)
                cout<<s[i];
            cout<<endl;
            continue;
        }
        if(z==1)
        {
            for(int i=0;i<=pos;i++)
            {
                if(s[i]=='0')
                    continue;
                if(i==p)
                    continue;
                cout<<s[i];
            }
            cout<<endl;
            continue;
        }
        cout<<-1<<endl;
    }
    return 0;
}