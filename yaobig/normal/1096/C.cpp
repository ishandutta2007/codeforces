#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 200000
#define mod 998244353
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int gcd(int x,int y) {return x==0?y:gcd(y%x,x);}

int main()
{
    int T; scanf("%d",&T);
    while(T--)
    {
        int x; scanf("%d",&x);
        int g=gcd(180,x);
        int a=x/g;
        int n=180/g;
        if(n-a==1) n*=2;
        printf("%d\n",n);
    }
    return 0;
}