#include <cstdio>
#include <cstring>

using namespace std;

#define mod 1000000007
#define maxn 110

int n, m;
long long sol;
char s[maxn];

int inm(long long nr, int exp)
{
    if(exp==0)
        return 1;
    long long sol=1;
    for(int i=1; i<=exp; ++i)
        sol=(sol*nr)%mod;
    return sol;
}

int main()
{
   // freopen("a.in", "r", stdin);
  //  freopen("a.out", "w", stdout);

    scanf("%s", s);

    n=strlen(s);

    sol=0;
    for(int i=0; i<n; ++i)
    {
        if(s[i]=='1')
        {
            sol=(sol+inm(2, 2*n-i-2))%mod;
        }
    }

    printf("%d\n", sol);

    return 0;
}