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
int main()
{
    int i,j,k;
    scanf("%d",&n);
    rep(i,1,n)
    {
        rep(j,1,n-1) printf("%d ",j*n-n+(i+j-2)%n+1);printf("%d\n", n*n-n+(i-2+n)%n+1);
    }
    return 0;
}