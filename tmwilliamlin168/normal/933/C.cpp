#include<bits/stdc++.h>
using namespace std;

typedef long double db;
const db eps=1e-12;

struct Point
{
    db x,y;
    Point(){}
    Point(db _x,db _y):x(_x),y(_y){}
    Point operator + (const Point &t)const
    {
        return Point(x+t.x,y+t.y);
    }
    Point operator - (const Point &t)const
    {
        return Point(x-t.x,y-t.y);
    }
    Point operator * (const db &t)const
    {
        return Point(x*t,y*t);
    }
    Point operator / (const db &t)const
    {
        return Point(x/t,y/t);
    }
    bool operator < (const Point &t)const
    {
        return fabs(x-t.x)<eps ? y<t.y : x<t.x;
    }
    bool operator == (const Point &t)const
    {
        return fabs(x-t.x)<eps && fabs(y-t.y)<eps;
    }
    db len()const
    {
        return sqrt(x*x+y*y);
    }
    Point rot90()const
    {
        return Point(-y,x);
    }
};

struct Circle
{
    Point o;
    db r;
    Circle(){}
    Circle(Point _o,db _r):o(_o),r(_r){}
    friend vector<Point> operator & (const Circle &c1,const Circle &c2)
    {
        db d=(c1.o-c2.o).len();
        if(d>c1.r+c2.r+eps || d<fabs(c1.r-c2.r)-eps)
            return vector<Point>();
        db dt=(c1.r*c1.r-c2.r*c2.r)/d,d1=(d+dt)/2;
        Point dir=(c2.o-c1.o)/d,pcrs=c1.o+dir*d1;
        dt=sqrt(max(0.0L,c1.r*c1.r-d1*d1)),dir=dir.rot90();
        return vector<Point>{pcrs+dir*dt,pcrs-dir*dt};
    }
}p[5];

struct DSU
{
    int fa[5];
    void init(int n)
    {
        for(int i=1;i<=n;i++)
            fa[i]=i;
    }
    int find(int x)
    {
        return fa[x]==x ? x : fa[x]=find(fa[x]);
    }
    void merge(int x,int y)
    {
        x=find(x),y=find(y);
        if(x!=y)fa[x]=y;
    }
}dsu;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        cin>>p[i].o.x>>p[i].o.y>>p[i].r;
    vector<Point> all;
    dsu.init(n);
    int e=0;
    for(int i=1;i<=n;i++)
    {
        vector<Point> pat;
        for(int j=1;j<=n;j++)if(i!=j)
        {
            vector<Point> tmp=p[i]&p[j];
            if(!tmp.empty())dsu.merge(i,j);
            for(int k=0;k<(int)tmp.size();k++)
                all.push_back(tmp[k]),pat.push_back(tmp[k]);
        }
        sort(pat.begin(),pat.end());
        e+=unique(pat.begin(),pat.end())-pat.begin();
    }
    sort(all.begin(),all.end());
    int v=unique(all.begin(),all.end())-all.begin(),c=0;
    for(int i=1;i<=n;i++)
        c+=(dsu.find(i)==i);
    cout<<e-v+c+1<<endl;
    return 0;
}