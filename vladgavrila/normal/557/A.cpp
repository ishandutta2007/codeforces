#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int m1, m2, m3, n1, n2, n3;
int sol1, sol2, sol3;

int main()
{
   // freopen("a.in", "r", stdin);
  //  freopen("a.out", "w", stdout);

    scanf("%d", &n);
    scanf("%d%d%d%d%d%d", &m1, &n1, &m2, &n2, &m3, &n3);

    sol1=min(n-m2-m3, n1);
    n-=sol1;
    sol2=min(n-m3, n2);
    n-=sol2;
    sol3=n;

    printf("%d %d %d\n", sol1, sol2, sol3);



    return 0;
}