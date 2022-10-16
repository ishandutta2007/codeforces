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

int a[maxn+5];

int main()
{
    int cas; scanf("%d",&cas);
    while(cas--)
    {
        int n; scanf("%d",&n);
        int sum=0;
        rep(i,1,n) scanf("%d",&a[i]),sum+=a[i];
        bool f=0;
        rep(i,1,n) if(2*a[i]>sum) f=1;
        if(f) puts("T");
        else
        {
            if(sum%2==0) puts("HL");
            else puts("T");
        }
    }
    return 0;
}