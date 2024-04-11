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
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
#define lb(x) (x&(-x));
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;

string s;
ll a[1005][1005];

int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    cout<<(ll)sqrt(1ll*a[1][2]*a[1][3]/a[2][3])<<' ';
    cout<<(ll)sqrt(1ll*a[1][2]*a[2][3]/a[1][3])<<' ';
    for(int i=3;i<=n;i++)
    {
        cout<<(ll)sqrt(1ll*a[1][i]*a[i][2]/a[1][2])<<' ';
    }
    cout<<endl;
    return 0;
}