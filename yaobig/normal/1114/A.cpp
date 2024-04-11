#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int main()
{
    int x,y,z; scanf("%d%d%d",&x,&y,&z);
    int a,b,c; scanf("%d%d%d",&a,&b,&c);
    bool f=1;
    if(a<x) f=0;
    if(a+b<x+y) f=0;
    if(a+b+c<x+y+z) f=0;
    puts(f?"YES":"NO");
    return 0;
}