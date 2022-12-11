#include <bits/stdc++.h>
#define Maxn 300007
using namespace std;
int n,m;
int a[Maxn],b[Maxn];
int cnt,p[Maxn],q[Maxn];
bool check(int x)
{
    cnt=0;
    for (int i=1;i<=m;i++)
        if (a[i]!=x&&b[i]!=x)
        {
            ++cnt;
            p[cnt]=a[i];
            q[cnt]=b[i];
        }
    if (cnt==0) return true;
    bool check=true;
    for (int i=2;i<=cnt;i++)
        if (p[i]!=p[1]&&q[i]!=p[1]) check=false;
    if (check) return true;
    check=true;
    for (int i=2;i<=cnt;i++)
        if (p[i]!=q[1]&&q[i]!=q[1]) check=false;
    if (check) return true;
    return false;
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
        scanf("%d%d",&a[i],&b[i]);
    if (check(a[1])) printf("YES\n");
    else if (check(b[1])) printf("YES\n");
    else printf("NO\n");
    return 0;
}