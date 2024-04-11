#include <bits/stdc++.h>

using namespace std;
#define int long long
struct pt
{
    double x;
    double y;
};
struct line
{
    double a;
    double b;
    double c;
};
line to(pt a,pt b)
{
    line l;
    l.a=(a.y-b.y);l.b=(b.x-a.x);
    l.c=(-a.x*l.a-a.y*l.b);
    return l;
}
pt perec(line l1,line l2)
{
    pt o;
    o.y=(l2.c*l1.a-l1.c*l2.a)/(l2.a*l1.b-l1.a*l2.b);
    o.x=(l2.c*l1.b-l1.c*l2.b)/(l2.b*l1.a-l1.b*l2.a);
    return o;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    pair <int,int> a[n];
    pair <int,int> b[n];
    pt a1[n];pt b1[n];
    line l[n];
    int sum=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i].first>>a[i].second>>b[i].first>>b[i].second;
        a[i].first+=(1e6+1);a[i].second+=(1e6+1);b[i].first+=(1e6+1);b[i].second+=(1e6+1);
        pt ai;ai.x=a[i].first;ai.y=a[i].second;
        a1[i]=ai;
        pt bi;bi.x=b[i].first;bi.y=b[i].second;
        b1[i]=bi;
        l[i]=to(ai,bi);
        sum+=abs(__gcd(b[i].first-a[i].first,b[i].second-a[i].second))+1;
    }
    map <pair<int,int>,int> u;
    vector <pair<int,int> > keys;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<i;++j)
        {
            pt curr=perec(l[i],l[j]);
            if(abs(curr.x-(int) (curr.x+0.5))<=1e-7 && abs(curr.y-(int) (curr.y+0.5))<=1e-7)
            {
                int x1=(int) (curr.x+0.5);int y1=(int) (curr.y+0.5);
                if((x1-a[i].first)*(x1-b[i].first)<=0 && (y1-a[i].second)*(y1-b[i].second)<=0 && (x1-a[j].first)*(x1-b[j].first)<=0 && (y1-a[j].second)*(y1-b[j].second)<=0)
                {
                    if(!u.count({x1,y1}))
                    {
                        u[{x1,y1}]=1;
                        keys.push_back({x1,y1});
                    }
                    else
                    {
                        u[{x1,y1}]++;
                    }
                }
            }
        }
    }
    map <int,int> o;
    for(int i=0;i<5000;++i)
    {
        o[(i*(i-1))/2]=i;
    }
    for(int i=0;i<keys.size();++i)
    {
        sum-=(o[u[keys[i]]]-1);
    }
    cout<<sum;
    return 0;
}