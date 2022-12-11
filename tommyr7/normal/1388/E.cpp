#include <bits/stdc++.h>
#define double long double
using namespace std;
#define Maxn 2007
int n;
int x1[Maxn],x2[Maxn],y[Maxn];
set<pair<pair<double,double>,int> >s1,s2;
set<pair<double,double> >s;
pair<double,int> que[2*Maxn*Maxn];
int cnt=0;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d%d%d",&x1[i],&x2[i],&y[i]);
    bool check=true;
    for (int i=1;i<=n;i++)
        if (y[i]!=y[1]) check=false;
    if (check)
    {
        double lx=1e15,rx=-1e15;
        for (int i=1;i<=n;i++)
        {
            lx=min(lx,(double)1.0*x1[i]);
            rx=max(rx,(double)1.0*x2[i]);
        }
        cout.precision(9);
        cout << rx-lx << endl;
        return 0;
    }
    for (int i=1;i<=n;i++)
    {
        double lx=-1e15,rx=1e15;
        for (int j=1;j<=n;j++)
        {
            if (y[i]==y[j])
            {
                if (x1[i]<x1[j])
                {
                    lx=1e15;
                    rx=-1e15;
                }
                continue;
            }
            double tmp=(1.0*x2[j]-1.0*x1[i])/(1.0*y[i]-1.0*y[j]);
            if (y[i]>y[j]) lx=max(lx,tmp); else rx=min(rx,tmp);
        }
        if (lx<=rx) s1.insert(make_pair(make_pair(lx,rx),i));
    }
    for (int i=1;i<=n;i++)
    {
        double lx=-1e15,rx=1e15;
        for (int j=1;j<=n;j++)
        {
            if (y[i]==y[j])
            {
                if (x1[i]>x1[j])
                {
                    lx=1e15;
                    rx=-1e15;
                }
                continue;
            }
            double tmp=(1.0*x1[j]-1.0*x2[i])/(1.0*y[i]-1.0*y[j]);
            if (y[i]>y[j]) rx=min(rx,tmp); else lx=max(lx,tmp);
        }
        if (lx<=rx) s2.insert(make_pair(make_pair(lx,rx),i));
    }
    que[++cnt]=make_pair(-1e15,0);
    que[++cnt]=make_pair(1e15,0);
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
        {
            if (y[i]==y[j]) continue;
            double tmp1=(1.0*x2[j]-1.0*x1[i])/(1.0*y[i]-1.0*y[j]);
            double tmp2=(1.0*x1[j]-1.0*x2[i])/(1.0*y[i]-1.0*y[j]);
            if (tmp1>tmp2) swap(tmp1,tmp2);
            que[++cnt]=make_pair(tmp1,1);
            que[++cnt]=make_pair(tmp2,-1);
        }
    sort(que+1,que+cnt+1);
    for (int i=2;i<=cnt;i++)
        que[i].second+=que[i-1].second;
    for (int i=1;i<cnt;i++)
        if (que[i].second==0) s.insert(make_pair(que[i].first,que[i+1].first));
    double ans=2e15;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            if (y[i]==y[j]) continue;
            double tmp=(1.0*x2[j]-1.0*x1[i])/(1.0*y[i]-1.0*y[j]);
            set<pair<double,double> >::iterator it=s.upper_bound(make_pair(tmp,1e15+1));
            if (it==s.begin()) continue;
            --it;
            if ((*it).second<tmp) continue;
            double lx,rx;
            int id;
            set<pair<pair<double,double>,int> >::iterator itt;
            itt=s1.upper_bound(make_pair(make_pair(tmp,1e15+1),n+1));
            --itt;
            id=(*itt).second;
            rx=1.0*x2[id]+1.0*y[id]*tmp;
            itt=s2.upper_bound(make_pair(make_pair(tmp,1e15+1),n+1));
            --itt;
            id=(*itt).second;
            lx=1.0*x1[id]+1.0*y[id]*tmp;
            ans=min(ans,rx-lx);
        }
    cout.precision(9);
    cout << ans << endl;
    return 0;
}