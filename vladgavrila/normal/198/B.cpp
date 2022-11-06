#include <cstdio>
#include <vector>

using namespace std;

#define maxn 500010

int n, q0, k;
int q[maxn], f[maxn], d[maxn];
char s1[maxn], s2[maxn];
vector<int> v[maxn];

int main()
{
 //   freopen("data.in", "r", stdin);
 //   freopen("data.out", "w", stdout);

    scanf("%d%d\n", &n, &k);
    scanf("%s\n", s1);
    scanf("%s\n", s2);

    for(int i=0; i<n; ++i)
    {
        if(s1[i]=='X')
            f[i]=1;
        if(s2[i]=='X')
            f[i+n]=1;
        if(i>0)
        {
            v[i].push_back(i-1);
            v[i+n].push_back(i+n-1);
        }
        if(i<n-1)
        {
            v[i].push_back(i+1);
            v[i+n].push_back(i+n+1);
        }
        if(i+k<n)
        {
            v[i].push_back(i+n+k);
            v[i+n].push_back(i+k);
        }
        else
        {
            v[i].push_back(2*n);
            v[i+n].push_back(2*n);
        }
    }

    q0=1;
    f[0]=1;

    int nod;
    for(int i=1; i<=q0; ++i)
    {
        nod=q[i];
        if(nod==2*n)
        {
            printf("YES\n");
            return 0;
        }
        if(d[nod]>nod%n)
            continue;
        for(int j=0; j<v[nod].size(); ++j)
        {
            if(f[v[nod][j]]==0)
            {
                d[v[nod][j]]=d[nod]+1;
                q[++q0]=v[nod][j];
                f[v[nod][j]]=1;
            }
        }
    }

    printf("NO\n");

    return 0;
}