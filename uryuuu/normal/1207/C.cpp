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
#define lb(x) (x&(-x));
#define add(a,b) ((a+=(b))%=Mod)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=1000005;
const ll Mod=1000000007;


string s;


int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        ll a,b;
        cin>>n>>a>>b;
        cin>>s;
        int f=0;
        int pos;
        int flag;
        for(int i=0;i<n;i++)
        {

            if(s[i]=='1')
            {
                if(f==0)
                    pos=i;
                f=1;
            }
        }
        ll sum=(a+b)*n+b;
        if(f==0)
        {
            cout<<sum<<endl;
            continue;
        }
        f=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                if(f==0)
                {
                    sum+=b;
                    sum+=a;
                    f=1;
                }
                sum+=b;
            }
            else if(s[i]=='0')
            {
                if(f==1)
                {
                    int d=0;
                    flag=0;
                    pos=n;
                    for(int j=i;j<n;j++)
                    {
                        if(s[j]=='0')
                            d++;
                        else
                        {
                            pos=j;
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0||2ll*a<(pos-i-1)*b)
                    {
                        f=0;
                        sum+=a;
                    }
                    else
                    {
                        sum+=(pos-i)*b;
                    }
                    i=pos-1;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}