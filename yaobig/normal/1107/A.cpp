#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 300
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

char s[maxn+5];

int main()
{
    int CAS; scanf("%d",&CAS);
    rep(cas,1,CAS)
    {
        int n; scanf("%d",&n);
        scanf("%s",s+1);
        if(n==2 && s[1]>=s[2]) puts("NO");
        else
        {
            puts("YES");
            puts("2");
            printf("%c %s\n",s[1],s+2);
        }
    }
    return 0;
}