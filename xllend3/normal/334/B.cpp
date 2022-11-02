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
struct AC{int a,b;}a[10];
int m,n,l,t;
bool cmp(const AC &a, const AC &b){return a.a<b.a||a.a==b.a&&a.b<b.b;}
int main()
{
    int i,j,k;
    rep(i,1,8) scanf("%d%d",&a[i].a,&a[i].b);sort(a+1,a+9,cmp);
    if (a[1].a==a[2].a&&a[2].a==a[3].a&&a[4].a==a[5].a&&a[6].a==a[7].a&&a[7].a==a[8].a
        &&a[1].b==a[4].b&&a[4].b==a[6].b&&a[2].b==a[7].b&&a[3].b==a[5].b&&a[5].b==a[8].b
            &&a[1].a!=a[4].a&&a[4].a!=a[7].a&&a[1].b!=a[2].b&&a[2].b!=a[3].b)
    puts("respectable");else puts("ugly");
    return 0;
}