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


int read()
{
    int n; scanf("%d",&n);
    rep(i,1,n) {ll x; scanf("%I64d",&x);}
    return n;
}

int main()
{
    while(1)
    {
        puts("next 0 1"); fflush(stdout);
        read();
        puts("next 1"); fflush(stdout);
        if(read()==2) break;
    }
    while(1)
    {
        puts("next 0 1 2 3 4 5 6 7 8 9"); fflush(stdout);
        if(read()==1) break;
    }
    puts("done"); fflush(stdout);
    return 0;
}