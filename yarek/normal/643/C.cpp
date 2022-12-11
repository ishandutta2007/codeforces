#include <bits/stdc++.h>
using namespace std;

int n, k;

double wcz;

long double sum[200007];
long double rev[200007];
long double pre[200007];

long double inf;

long double dpn[200007];

long double x[200007];
long double y[200007];
int seg[200007];

int l;
vector <int> sta;

inline long double vec(int s, int a, int b)
{
    return (x[a]-x[s])*(y[b]-y[s])-(x[b]-x[s])*(y[a]-y[s]);
}

int main()
{
    inf=1000000000.0;
    inf*=inf;
    scanf("%d%d", &n, &k);
    for (int i=1; i<=n; i++)
    {
        scanf("%lf", &wcz);
        sum[i]=wcz;
        pre[i]=pre[i-1]+sum[i-1]/sum[i]+1.0;
        rev[i]=1.0/sum[i]+rev[i-1];
        sum[i]+=sum[i-1];
    }
    double a = 0, b = pre[n] + 1, lambda;
    long double ans = pre[n];
    for(int i = 0; i < 100; i++)
    {
        lambda = (a + b) / 2;
        sta.clear();
        l=0;
        for (int i=1; i<=n; i++)
        {
            while(sta.size()>1 && vec(sta[sta.size()-2], sta[sta.size()-1], i-1)>=0)
            sta.pop_back();
            l=min(l, (int)sta.size()-1);
            l=max(l, 0);
            sta.push_back(i-1);
            while(l+1<sta.size() && 1*x[sta[l+1]]-rev[i]*y[sta[l+1]]<=1*x[sta[l]]-rev[i]*y[sta[l]])
            l++;
            double k = 1*x[sta[l]]-rev[i]*y[sta[l]];
            if(k < 0)
            {
                dpn[i]=pre[i] + k + lambda;
                seg[i]=seg[sta[l]]+1;
            }
            else
            {
                dpn[i]=pre[i] + lambda;
                seg[i]=1;
            }
            x[i]=dpn[i]+rev[i]*sum[i]-pre[i];
            y[i]=sum[i];
        }
        if(seg[n] <= k)
        {
            ans = min(ans, dpn[n] - seg[n] * lambda);
            b = lambda;
        }
        else a = lambda;
    }
    printf("%.10lf\n", (double)ans);
    return 0;
}