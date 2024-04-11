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
#define mkp(a,b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200010;
const ll Mod=1000000007;
//const ll Mod=998244353;
  

string A,B;
int a[maxn],b[maxn];
int g[26][26];

int main()
{
    sync;
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>A>>B;
        int f=0;
        mm(g);
        for(int i=1;i<=n;i++)
        {
            a[i]=ch(A[i-1]);
            b[i]=ch(B[i-1]);
            if(a[i]<b[i])
            {
                g[a[i]][b[i]]++;
            }
            else if(a[i]>b[i])
            {
                f=1;
                break;
            }
        }
        if(f)
        {
            cout<<-1<<endl;
            continue;
        }
        int sum=0;
        for(int i=1;i<=19;i++)
        {
            for(int j=i+1;j<=20;j++)
            {
                if(g[i][j])
                {
                    for(int k=j+1;k<=20;k++)
                    {
                        if(g[i][k])
                        {
                            g[i][k]=0;
                            g[j][k]++;
                        }
                    }
                    break;
                }
            }
        }
        for(int i=1;i<=20;i++)
        {
            for(int j=1;j<=20;j++)
                if(g[i][j])
                    sum++;
        }
        cout<<sum<<endl;
        
    }
    
    
    return 0;
}