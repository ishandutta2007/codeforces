#include <cstdio>

using namespace std;

#define mod 1000000007

int n, m, k;

int lgput(int nr, int exp)
{
    long long sol=1;
    for(int i=1; i<=exp; ++i)
        sol=(sol*nr)%mod;
    return sol;
}

int main()
{
 //   freopen("data.in", "r", stdin);
 //   freopen("data.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);
    if(k==1 || k>n)
    {
        printf("%d\n", lgput(m, n));
        return 0;
    }
    if(k==n)
    {
        printf("%d\n", lgput(m, k/2+k%2));
        return 0;
    }
    if(k%2==1)
    {
        printf("%d\n", lgput(m, 2));
        return 0;
    }
    printf("%d\n", m);

    return 0;
}