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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=50010;;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;

int a[maxn],b[maxn];

string s;

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cin>>s;
        int f=0;
        for(int i=0;i<n;i++)
        {
            if(f==1)
            {
                if(s[i]=='2')
                {
                    a[i]=0;
                    b[i]=2;
                }
                else if(s[i]=='0')
                {
                    a[i]=0;
                    b[i]=0;
                }
                else
                {
                    a[i]=0;
                    b[i]=1;
                }
                continue;
            }
            if(s[i]=='2')
            {
                a[i]=1;
                b[i]=1;
            }
            else if(s[i]=='0')
            {
                a[i]=0;
                b[i]=0;
            }
            else
            {
                a[i]=1;
                b[i]=0;
                f=1;
            }
        }
        for(int i=0;i<n;i++)
            cout<<a[i];
        cout<<endl;
        for(int i=0;i<n;i++)
            cout<<b[i];
        cout<<endl;
    }
    return 0;
}