#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define maxn 1010

int n, k, a, b, cc, lstool;
double price;
int isStool[maxn], p[maxn];
pair<int, pair<int, int> > v[maxn];
vector<int> sol[maxn];

int main()
{
   // freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);
    
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d%d", &a, &b);
        v[i]=make_pair(a, make_pair(b, i));
        isStool[i]=2-b;
        price+=(double)2*a;
        p[i]=a;
    }
    sort(v+1, v+n+1);
    cc=k;
    for(int i=n; i; --i)
    {
        sol[cc].push_back(v[i].second.second);
        if(v[i].second.first==1)
        {
            lstool=v[i].first;
            if(cc>1 || cc==i)
                --cc;
        }
        else
        {
            if(cc==i)
                --cc;
        }
    }
    
    for(int i=1; i<=k; ++i)
    {
        int amStool=0;
        for(int j=0; j<sol[i].size(); ++j)
            if(isStool[sol[i][j]])
                amStool=1;
        if(amStool)
            price-=p[sol[i][sol[i].size()-1]];
        
    }
    
    printf("%.1lf\n", price/2);
    
    for(int i=1; i<=k; ++i)
    {
        printf("%d ", sol[i].size());
        for(int j=0; j<sol[i].size(); ++j)
            printf("%d ", sol[i][j]);
        printf("\n");
    }
    
    return 0;
}