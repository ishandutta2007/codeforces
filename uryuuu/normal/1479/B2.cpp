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
#define ch(a) (int(a-'A')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;

int a[maxn],b[maxn];
int L[maxn],R[maxn];
queue<int>q[maxn];

int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    int cnt=0;
    a[++cnt]=b[1];
    for(int i=2;i<=n;i++)
    {
        if(b[i]!=b[i-1])
            a[++cnt]=b[i];
    }
    n=cnt;
    for(int i=1;i<=n;i++)
    {
        q[a[i]].push(i);
    }
    int lcnt=0,rcnt=0;
    L[0]=maxn-2;;
    R[0]=maxn-2;
    for(int i=1;i<=n;i++)
    {
        q[a[i]].pop();
        if(L[lcnt]==a[i]||R[rcnt]==a[i])
        {
            continue;
        }
        if(q[L[lcnt]].size()==0)
        {
            L[++lcnt]=a[i];
            continue;
        }
        if(q[R[rcnt]].size()==0)
        {
            R[++rcnt]=a[i];
            continue;
        }
        if(q[L[lcnt]].front()<q[R[rcnt]].front())
        {
            R[++rcnt]=a[i];
            continue;
        }
        else
        {
            L[++lcnt]=a[i];
            continue;
        }
    }
    cout<<lcnt+rcnt<<endl;
    
    return 0;
}