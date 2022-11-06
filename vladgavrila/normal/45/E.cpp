#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define maxn 1220

int n, i, j, k, nr, sol, p1, p2, f1[maxn], f2[maxn], a[maxn], b[maxn], ind[maxn], per[maxn];
string sn[maxn], nm[maxn];
char s[maxn];
vector< string > pn[maxn], nf[maxn];
pair<string, string> afis[maxn];

void afiseaza(string a)
{
    for(int i=0; i<a.size(); ++i)
        printf("%c", a[i]);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d\n", &n);
    for(int i=1; i<=n; ++i)
    {
        memset(s, 0, sizeof(s));
        scanf("%s", s);
        for(int j=0; s[j]>=10; ++j)
            nm[i]+=s[j];
    }
    sort(nm+1, nm+n+1);
    for(int i=1; i<=n; ++i)
    {
        memset(s, 0, sizeof(s));
        scanf("%s", s);
        for(int j=0; s[j]>=10; ++j)
            sn[i]+=s[j];
    }
    sort(sn+1, sn+n+1);
    for(int i=1; i<=n; ++i)
    {
        pn[nm[i][0]-'A'].push_back(nm[i]);
        nf[sn[i][0]-'A'].push_back(sn[i]);
    }
    for(int i=0; i<26; ++i)
    {
        per[i]=min(pn[i].size(), nf[i].size());
        ind[i]=0;
    }
    for(int i=0; i<26; ++i)
    {
        for(int j=0; j<pn[i].size(); ++j)
        {
            if(pn[i].size()-j==per[i])
            {
                afis[++sol]=make_pair(pn[i][j], nf[i][ind[i]]);
                ind[i]++;
                per[i]--;
            }
            else
            {
                for(int k=0; k<26; ++k)
                {
                    if(nf[k].size()-ind[k]>per[k] || (k==i && ind[k]<nf[k].size()))
                    {
                        afis[++sol]=make_pair(pn[i][j], nf[k][ind[k]]);
                        ++ind[k];
                        if(k==i)
                            per[i]--;
                        break;
                    }
                }
            }
        }
    }

    for(int i=1; i<n; ++i)
    {
        afiseaza(afis[i].first);
        printf(" ");
        afiseaza(afis[i].second);
        printf(", ");
    }
    afiseaza(afis[n].first);
    printf(" ");
    afiseaza(afis[n].second);
    printf("\n");
    return 0;
}