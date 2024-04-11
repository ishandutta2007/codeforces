#include <bits/stdc++.h>

using namespace std;

const int nax=10007;

int tab[nax];

int cnt[nax];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &tab[i]);
        cnt[tab[i]]++;
    }
    int ans=0;
    for(int i=0; i<n;)
    {
        for(int j=1; j<nax; j++)
        {
            if(cnt[j]>0)
            {
                ans++, i++, cnt[j]--;
            }
        }
        ans--;
    }
    printf("%d", ans);
    return 0;
}