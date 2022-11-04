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
#include<unordered_map>
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



int a[2005][2005];
char s[10];

int main()
{
    sync;
    s[0]='a';
    s[1]='e';
    s[2]='i';
    s[3]='o';
    s[4]='u';
    int k;
    int n,m;
    cin>>k;
    int f=0;
    for(int i=5;i*i<=k;i++)
    {
        if(k%i==0&&i>=5&&k/i>=5)
        {
            n=i;
            m=k/i;
            f=1;
            break;
        }
    }
    if(f==0)
    {
        cout<<-1<<endl;
        return 0;
    }
    
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
        {
            a[i][j]=(j+i-2)%5;
        }
    }
    for(int i=6;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            a[i][j]=j-1;
        }
    }
    for(int i=6;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            a[j][i]=j%5;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<s[a[i][j]];
//            cout<<a[i][j]<<' ';
        }
//        cout<<endl;
    }
    cout<<endl;
    return 0;
}