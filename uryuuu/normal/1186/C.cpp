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
#define ch(a) (int(a-'0'))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=1000010;
const ll Mod=1000000007;
//const ll Mod=998244353;
using namespace std;


string s1,s2;

int a[maxn],b[maxn];
int n,m;

int c[maxn];

int main()
{
    sync;
    cin>>s1>>s2;
    int m=s2.length();
    for(int i=0;i<m;i++)
    {
        b[i+1]=b[i];
        if(s2[i]=='1')
            b[i+1]++;
    }
    int n=s1.length();
    for(int i=0;i<n;i++)
    {
        a[i+1]=a[i];
        if(s1[i]=='1')
            a[i+1]++;
    }
    int sum=0;
    int R=b[m]%2;
    for(int i=m;i<=n;i++)
    {
        if((a[i]-a[i-m])%2==R)
            sum++;
    }
    
    cout<<sum<<endl;
    
    return 0;
}