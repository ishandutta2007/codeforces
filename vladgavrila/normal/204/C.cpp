#include <cstdio>

using namespace std;

#define maxn 200210
#define sigma 26

int n, m;
long long left[maxn][sigma], right[maxn][sigma];
double fav, total;
char s1[maxn], s2[maxn];

int main()
{
  //  freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    scanf("%d\n", &n);
    scanf("%s\n", s1+1);
    scanf("%s\n", s2+1);
    for(int i=1; i<=n; ++i)
    {
        total+=1LL*i*i;
        s1[i]-='A';
        s2[i]-='A';
        left[i][s2[i]]+=i;
        right[i][s2[i]]+=(n-i+1);
    }

    for(int i=1; i<=n; ++i)
        for(int j=0; j<sigma; ++j)
            left[i][j]+=left[i-1][j];
    for(int i=n; i; --i)
        for(int j=0; j<sigma; ++j)
            right[i][j]+=right[i+1][j];

    for(int i=1; i<=n; ++i)
        fav+=left[i][s1[i]]*(n-i+1)+right[i+1][s1[i]]*i;

    printf("%.10lf\n", fav/total);

    return 0;
}