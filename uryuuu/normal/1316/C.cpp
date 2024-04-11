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
//const double pi=acos(-1);
const int maxn=2000005;
const ll Mod=1000000007;


inline ll rd() {
    ll num=0, w=0;
    char ch=0;
    while (!isdigit(ch)) {
        w|=ch=='-';
        ch = getchar();
    }
    while (isdigit(ch)) {
        num = (num<<3) + (num<<1) + (ch^48);
        ch = getchar();
    }
    return w? -num: num;
}

string s,s1,ss;

ll a[maxn],b[maxn],c[maxn];

int main()
{
    sync;
    ll n,m,p;
    n=rd();
    m=rd();
    p=rd();
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        a[i]=rd();
        a[i]%=p;
        if(a[i])
            c[cnt++]=i;
    }
    
    for(int i=0;i<m;i++)
    {
        b[i]=rd();
        b[i]%=p;
    }
    for(int i=0;i<m;i++)
    {
        if(b[i])
        {
            cout<<i+c[0]<<endl;
            return 0;
        }
    }
    
    return 0;
}