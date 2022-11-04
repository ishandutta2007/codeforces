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
const int maxn=405;
const ll Mod=1000000007;


int dp[maxn][maxn];
string s,t;

int jz(string a,string b)
{
    int id=0;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]==b[id])
            id++;
        if(id==b.length())
            return 1;
    }
    return 0;
}

int check(string a,string t1,string t2)
{
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
   
    for(int i=0;i<a.length();i++)
    {
        for(int j=0;j<=t1.length();j++)
        {
            if(dp[i][j]>=0)
            {
                if(j<t1.length()&&t1[j]==a[i])
                {
                    dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
                }

                if(dp[i][j]<t2.length()&&t2[dp[i][j]]==a[i])
                {
                    dp[i+1][j]=max(dp[i+1][j],dp[i][j]+1);
                }

                dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
            }
        }
    }

    int r1=dp[a.length()][t1.length()];
    int r2=t2.length();
//    cout<<dp[a.length()][t1.length()]<<' '<<t2.length()<<' '<<(dp[a.length()][t1.length()]>=t2.length())<<endl;
//    cout<<r1<<' '<<r2<<' '<<(r1>=r2)<<endl;
    if(r1>=r2)
    {
//    if(dp[a.length()][t1.length()]>=t2.length())
        return 1;
    }
    return 0;
}


void fun()
{
    if(jz(s,t))
    {
        cout<<"YES"<<endl;
        return;
    }
    for(int i=0;i<t.length()-1;i++)
    {
        string a="",b="";
        for(int j=0;j<=i;j++)
        {
            a+=t[j];
        }
        for(int j=i+1;j<t.length();j++)
            b+=t[j];
        if(check(s,a,b))
        {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
    return;
}



int main()
{
    sync;
    int T;
    cin>>T;
    while(T--)
    {
        cin>>s>>t;
        fun();
    }
    return 0;
}