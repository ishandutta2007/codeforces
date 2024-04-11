#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <cstring>

using namespace std;

#define maxn 10010

int n, i, j, k, p, poz, ok, p2, f[maxn];
vector<int> v;
char conf[maxn], cuv[maxn], sol[maxn];

int getr(int left, int right)
{
    int i;
    for(i=0; i<v.size() && v[i]<left; ++i);
    int j;
    for(j=i; j<v.size() && v[j]<=right; ++j);
    if(j-i==0)
        return -1;
    int poz=rand()%(j-i)+i;
    return v[rand()%(j-i)+i];
}


int main()
{
    srand(time(0));
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d%d", &n, &k);
    scanf("%s", cuv+1);
    p=strlen(cuv+1);
    scanf("%s", conf+1);
    for(int i=1; i<=n-p+1; ++i)
    {
        if(conf[i]=='1')
        {
            for(int j=1; j<=p; ++j)
            {
                if(sol[i+j-1]!=0 && sol[i+j-1]!=cuv[j])
                {
                    printf("No solution\n");
                    return 0;
                }
                sol[i+j-1]=cuv[j];
            }
        }
    }
    for(int i=1; i<=n; ++i)
    {
        if(sol[i]==0)
        {
            f[i]=1;
            v.push_back(i);
            sol[i]=rand()%k+'a';
        }
    }
    for(int i=1; i<=5000; ++i)
    {
        ok=1;
        for(int j=1; j<=n-p+1; ++j)
        {
            if(conf[j]=='1')
                continue;
            int x=1;
            for(int k=1; k<=p; ++k)
            {
                if(sol[j+k-1]!=cuv[k])
                {
                    x=0;
                    break;
                }
            }
            if(x==1)
            {
                ok=0;
                poz=j;
                break;
            }
        }
        if(ok)
            break;
        p2=getr(poz, poz+p-1);
        if(p2==-1)
            break;
        sol[p2]=rand()%k+'a';
    }
    if(!ok)
    {
        printf("No solution\n");
        return 0;
    }
    for(int i=1; i<=n; ++i)
        printf("%c", sol[i]);
    printf("\n");
    return 0;
}