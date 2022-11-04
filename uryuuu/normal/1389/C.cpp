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
const double pi=acos(-1);
const int maxn=200010;
const ll Mod=1000000007;
//const ll Mod=998244353;
  
ll a[maxn];
int g[maxn][20];
string s;
int cnt[20];

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        int n=s.length();
        for(int i=0;i<=9;i++)
        {
            g[n+1][i]=n+1;
            cnt[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            a[i]=int(s[i-1]-'0');
            cnt[a[i]]++;
        }
        for(int i=n;i>=1;i--)
        {
            for(int j=0;j<=9;j++)
            {
                g[i][j]=g[i+1][j];
            }
            g[i][a[i]]=i;
        }
//        for(int i=0;i<=9;i++)
//        {
//            cout<<g[5][i]<<' ';
//        }
        int pos;
        int sum,mx=0;
        for(int l=0;l<=9;l++)
        {
            for(int r=0;r<=9;r++)
            {
                if(l==r)
                    continue;
                pos=1;
                sum=0;
                while(1)
                {
//                    cout<<l<<' '<<r<<' '<<pos<<endl;
                    if(pos>n)
                        break;
                    pos=g[pos][l];
                    if(pos>n)
                        break;
                    pos=g[pos+1][r];
                    if(pos>n)
                        break;
                    sum+=2;
                    pos++;
                }
                mx=max(sum,mx);
            }
        }
        for(int i=0;i<=9;i++)
        {
            mx=max(cnt[i],mx);
        }
        cout<<n-mx<<endl;
    }
    return 0;
}