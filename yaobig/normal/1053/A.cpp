#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define maxn 3000
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int gcd(int x,int y) {return x==0?y:gcd(y%x,x);}

int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    n*=2;
    int gn=gcd(n,k);
    n/=gn;
    k/=gn;
    if(gn==1) n/=2,m*=2;
    int gm=gcd(m,k);
    m/=gm;
    k/=gm;
    if(k!=1) printf("NO\n");
    else
    {
        printf("YES\n");
        printf("%d %d\n",0,0);
        printf("%d %d\n",n,0);
        printf("%d %d\n",0,m);
    }
    return 0;
}