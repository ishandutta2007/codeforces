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
#include<unordered_map>
#include<time.h>
#include<cstdlib>
#include <chrono>
#include <random>
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=200005;
//const ll Mod=1000000007;
const ll Mod=998244353;


int x[maxn],y[maxn];

int main()
{
    sync;
    int a,b,k;
    cin>>a>>b>>k;

    if(a==0&&b==1&&k==0)
    {
        cout<<"Yes"<<endl;
        cout<<1<<endl;
        cout<<1<<endl;
        return 0;
    }
    
    if(b==1&&k>0)
    {
        cout<<"No"<<endl;
        return 0;
    }
    
    if(a==0&&k>0)
    {
        cout<<"No"<<endl;
        return 0;
    }
    
    if(a+b-2<k)
    {
        cout<<"No"<<endl;
        return 0;
    }
    
    cout<<"Yes"<<endl;
    
    if(k==0)
    {
        for(int i=1;i<=b;i++)
            cout<<1;
        for(int i=1;i<=a;i++)
            cout<<0;
        cout<<endl;
        for(int i=1;i<=b;i++)
            cout<<1;
        for(int i=1;i<=a;i++)
            cout<<0;
        cout<<endl;
        return 0;
    }
    
    
    int n=a+b,cnt;
    int s1=b-2;
    int s0=a-1;
    
    x[1]=1;
    y[1]=1;
    x[2]=1;
    y[2]=0;
    cnt=2;
    for(int i=1;i<=k-1;i++)
    {
        cnt++;
        if(s1)
        {
            s1--;
            x[cnt]=y[cnt]=1;
        }
        else
        {
            s0--;
            x[cnt]=y[cnt]=0;
        }
    }
    
    cnt++;
    x[cnt]=0;
    y[cnt]=1;
    
    while(s1)
    {
        s1--;
        cnt++;
        x[cnt]=y[cnt]=1;
    }
    while(s0)
    {
        s0--;
        cnt++;
        x[cnt]=y[cnt]=0;
    }
    
    for(int i=1;i<=n;i++)
        cout<<x[i];
    cout<<endl;
    for(int i=1;i<=n;i++)
        cout<<y[i];
    cout<<endl;
    
    return 0;
}