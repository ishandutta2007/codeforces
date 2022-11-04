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
#include<bitset>
//#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200010;
//const ll Mod=1000000007;
const ll Mod=998244353;


string s;

int main()
{
    sync;
    int pos;
    int sum=0;
    int k;
    cin>>s>>k;
    int f=0;
    int n=s.length();
    int ss=n;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='?'||s[i]=='*')
        {
            ss-=2;
            sum++;
        }
        if(s[i]=='*')
        {
            f=1;
            pos=i;
        }
    }
    if(ss>k)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    if(ss+sum<k&&f==0)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    if(f)
    {
        int d=k-ss;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='?'||s[i]=='*')
                continue;
            if(i<n-1&&s[i+1]=='?')
                continue;
            if(i<n-1&&s[i+1]=='*')
            {
                if(i+1==pos)
                {
                    for(int j=1;j<=d;j++)
                    {
                        cout<<s[i];
                    }
                }
                continue;
            }
            cout<<s[i];
        }
        cout<<endl;
    }
    else
    {
        int d=k-ss;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='?'||s[i]=='*')
                continue;
            if(i<n-1&&s[i+1]=='?')
            {
                if(cnt<d)
                {
                    cout<<s[i];
                    cnt++;
                }
                continue;
            }
            cout<<s[i];
        }
        cout<<endl;
    }
    
    return 0;
}