#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
vector<pair<int, int>> v, vv;
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<=8; i++)
    {
        if(i%2)
        {
            for(int j=1; j<=8; j++)
            {
                vv.push_back({i, j});
            }
        }
        else
        {
            for(int j=8; j>=1; j--)
            {
                vv.push_back({i, j});
            }
        }
    }
    for(int i=1; i<=5; i++)
    {
        if(i%2)
        {
            for(int j=1; j<=8; j++)
            {
                v.push_back({i, j});
            }
        }
        else
        {
            for(int j=8; j>=1; j--)
            {
                v.push_back({i, j});
            }
        }
    }
    v.push_back({6, 8});
    v.push_back({7, 8});
    v.push_back({7, 7});
    v.push_back({6, 7});
    for(int i=6; i>=1; i--)
    {
        v.push_back({6, i});
    }
    for(int i=1; i<=6; i++)
    {
        v.push_back({7, i});
    }
    for(int i=6; i>=1; i--)
    {
        v.push_back({8, i});
    }
    v.push_back({8, 7});
    v.push_back({8, 8});

    if(v[n-1].first!=8)
    {
        if(v[n-2].second==8)
        {
            if(v[n-2].first<7)
            {
                for(int i=0; i<n-1; i++)
                {
                    printf("%c%d ", 'a'+v[i].second-1, v[i].first);
                }
                printf("%c%d h8\n", 'a'+v[n-2].second-1, v[n-2].first+1);
            }
            else
            {
                for(int i=0; i<n-1; i++)
                {
                    printf("%c%d ", 'a'+vv[i].second-1, vv[i].first);
                }
                printf("%c%d h8\n", 'a'+vv[n-2].second-1, 8);
            }
        }
        else
        {
            for(int i=0; i<n-1; i++)
            {
                printf("%c%d ", 'a'+v[i].second-1, v[i].first);
            }
            printf("%c%d h8\n", 'a'+v[n-2].second-1, 8);
        }
    }
    else{
        for(int i=0; i<=n-1; i++)
        {
            printf("%c%d ", 'a'+v[i].second-1, v[i].first);
        }
        printf("h8\n");
    }
}