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
const int maxn=300010;
//const ll Mod=1000000007;
const ll Mod=998244353;


string t;
string s;
int vis[40];

int main()
{
    sync;
    cin>>t;
    int m=t.length();
    if(m==1)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    int n=m/2;
    int f=0;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(vis[ch(t[i])]==0)
        {
            cnt++;
            vis[ch(t[i])]++;
        }
    }
    if(cnt==1)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    
    for(int k=1;k<=n;k++)
    {
        s="";
        for(int i=k;i<m;i++)
        {
            s+=t[i];
        }
        for(int i=0;i<k;i++)
        {
            s+=t[i];
        }
        f=0;
        if(s==t)
            continue;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=s[m-i-1])
            {
                f=1;
                break;
            }
        }
        if(f==0)
        {
            cout<<1<<endl;
            return 0;
        }
    }
    
    cout<<2<<endl;
    
    
    
    return 0;
}