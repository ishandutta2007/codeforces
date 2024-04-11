#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
//#include<queue>
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
#define lb(x) (x&(-x));
#define add(a,b) ((a+=(b))%=Mod)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=100005;
const ll Mod=1000000007;

int n,m;

int d[5];
int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>d[0]>>d[1]>>d[2];
        sort(d,d+3);
        a=d[0];
        b=d[1];
        c=d[2];
        int sum=0;
        if(a)
        {
            sum++;
            a--;
        }
        if(b)
        {
            sum++;
            b--;
        }
        if(c)
        {
            sum++;
            c--;
        }
        if(b&&c)
        {
            sum++;
            b--;
            c--;
        }
        if(a&&c)
        {
            sum++;
            a--;
            c--;
        }
        if(a&&b)
        {
            sum++;
            b--;
            a--;
        }
        if(a&&b&&c)
            sum++;
        cout<<sum<<endl;
    }
    return 0;
}