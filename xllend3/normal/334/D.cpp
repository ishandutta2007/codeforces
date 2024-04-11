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
int m,n,l,t;
int b[1111],c[1111],ans;
int main()
{
    int i,j,k;
    scanf("%d%d",&n,&m);rep(i,1,n) b[i]=c[i]=1;
    rep(i,1,m) scanf("%d%d",&l,&t),b[l]=0,c[t]=0;
    //rep(i,1,n) printf("%d %d\n", b[i], c[i]);
    if(n>3)rep(i,2,n/2)ans+=b[i]+b[n-i+1]+c[i]+c[n-i+1];
    if((n&1)&&(c[n/2+1]||b[n/2+1]))ans++;
    printf("%d\n",ans);
    return 0;
}