#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#define rep(i,a,n) for (int i = a; i <= n; ++i)
#define dep(i,a,n) for (int i = a; i >= n; --i)
#define pb push_back
#define mp make_pair
#define X first
#define Y second
using namespace std;
typedef long long llu;
int m,l,t,tot,a[1111],ans;
llu n,k;
int main()
{
    int i,j;
    scanf("%I64d",&n);
    //while(n){a[++tot]=n%3;n/=3;}
    //rep(i,1,tot){if(a[i]!=0){j=i;break;}}
    //rep(i,j+1,tot) ans+=a[i];++ans;
    //printf("%d\n",ans);
    k=1;while(n%k==0)k*=3;printf("%I64d\n", (n-1)/k+1);
    return 0;
}