#include <cstdio>

using namespace std;

#define maxn 5000010

int p, q;
int f[maxn];
int pi[maxn], r[maxn];
int d[20];

int checkP(int nr)
{
    int nd=0;

    while(nr>0)
    {
        d[++nd]=nr%10;
        nr=nr/10;
    }

    for(int i=1; i<=nd; ++i)
    {
        if(d[i]!=d[nd-i+1])
            return 0;
    }
    return 1;
}


int main()
{
    scanf("%d%d", &p, &q);

    for(int i=2; i<maxn; ++i)
    {
        pi[i]=pi[i-1];
        if(f[i])
            continue;
        ++pi[i];

        if(1LL*i*i>=1LL*maxn)
            continue;

        for(int j=i*i; j<maxn; j+=i)
            f[j]=1;
    }

    for(int i=1; i<maxn; ++i)
        r[i]=r[i-1]+checkP(i);

    int sol=-1;

    for(int i=1; i<maxn; ++i)
    {
        if(1LL*pi[i]*q<=1LL*p*r[i])
            sol=i;
    }

    if(sol==-1)
        printf("Palindromic tree is better than splay tree\n");
    else
        printf("%d\n", sol);

    return 0;
}