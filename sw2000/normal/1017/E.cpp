#include<bits/stdc++.h>
using namespace std;
const int N=4e5+10;
const double PI = acos(0) * 2;
const double eps = 1e-8;
int sgn(double x) {return x <= -eps ? -1 : (x < eps ? 0 : 1);}
inline double sqr(double x) {return x * x;}
/******************************************************************/
struct Point
{
    double x, y;
    void in(){scanf("%lf%lf",&x,&y);}
    void o(){cout<<x<<' '<<y<<endl;}
    Point() {}
    Point(double _x, double _y): x(_x), y(_y) {}
    bool operator==(Point b) {return !sgn(x - b.x) && !sgn(y - b.y);}
    Point operator+(Point b) {return Point(x + b.x, y + b.y);}
    Point operator-(Point b) {return Point(x - b.x, y - b.y);}
    Point operator*(double k) {return Point(x * k, y * k);}
    Point operator/(double k) {return Point(x / k, y / k);}
    bool operator < (Point b)const {return sgn(x - b.x) == 0 ? sgn(y - b.y) < 0 : x < b.x;}
    double operator^(Point b) {return x * b.y - y * b.x;}
    double operator*(Point b) {return x * b.x + y * b.y;}
    double len2() {return x * x + y * y;}
    double len() {return sqrt(len2());}
    double dis(Point p) {return (*this - p).len();}
    double rad(Point a, Point b)
    {
        Point p = *this;
        return fabs(atan2(fabs((a - p) ^ (b - p)), (a - p) * (b - p) ));
    }
    Point trunc(double r)
    {
        double l = len();
        if(!sgn(l))
            return *this;
        r /= l;
        return Point(x * r, y * r);
    }
    Point rotleft() {return Point(-y, x);}
    Point rotright() {return Point(y, -x);}
    Point rotate(Point p, double angle)
    {
        Point v = (*this) - p;
        double c = cos(angle), s = sin(angle);
        return Point(p.x + v.x * c - v.y * s, p.y + v.x * s + v.y * c);
    }
};
struct Line
{
    Point s, e;
    Line() {}
    Line(Point _s, Point _e): s(_s), e(_e) {}
    Line(Point p, double angle)
    {
        s = p;
        if(sgn(angle - PI / 2) == 0)
        {
            e = (s + Point(0, 1));
        }
        else
        {
            e = (s + Point(1, tan(angle)));
        }
    }
    //ax+by+c=0
    Line(double a, double b, double c)
    {
        if(sgn(a) == 0)
        {
            s = Point(0, -c / b);
            e = Point(1, -c / b);
        }
        else if(sgn(b) == 0)
        {
            s = Point(-c / a, 0);
            e = Point(-c / a, 1);
        }
        else
        {
            s = Point(0, -c / b);
            e = Point(1, (-c - a) / b);
        }
    }
    double len() {return s.dis(e);}
};
struct Pol
{
    int n;
    Point p[N];
    Line l[N];
    double cross(int a, int b, int c) {return (p[b] - p[a]) ^ (p[c] - p[a]);}
    double dot(int a, int b, int c) {return (p[b] - p[a]) * (p[c] - p[a]);}
    void add(Point q) {p[n++] = q;}
    void getline()
    {
        for(int i = 0; i < n; i++)
        {
            l[i] = Line(p[i], p[(i + 1) % n]);
        }
    }
    struct cmp
    {
        Point p;
        cmp(Point p0): p(p0) {}
        bool operator()(Point a, Point b)
        {
            int d = sgn((a - p) ^ (b - p));
            return d ? d > 0 : sgn(a.dis(p) - b.dis(p)) < 0;
        }
    };
    void norm()
    {
        Point mi = p[0];
        for(int i = 1; i < n; i++)
            mi = min(mi, p[i]);
        sort(p, p + n, cmp(mi));
    }
    void getconvex(Pol &convex)
    {
        sort(p, p + n);
        convex.n = n;
        for(int i = 0; i < min(n, 2); i++)
        {
            convex.p[i] = p[i];
        }
        if(convex.n == 2 && (convex.p[0] == convex.p[1]))
            convex.n--;
        if(n <= 2)
            return;
        int &top = convex.n;
        top = 1;
        for(int i = 2; i < n; i++)
        {
            while(top && sgn((convex.p[top] - p[i]) ^ (convex.p[top - 1] - p[i])) <= 0)
                top--;
            convex.p[++top] = p[i];
        }
        int temp = top;
        convex.p[++top] = p[n - 2];
        for(int i = n - 3; i >= 0; i--)
        {
            while(top != temp && sgn((convex.p[top] - p[i]) ^ (convex.p[top - 1] - p[i])) <= 0)
                top--;
            convex.p[++top] = p[i];
        }
        if(convex.n == 2 && (convex.p[0] == convex.p[1]))
            convex.n--;
        convex.norm();
    }
}a,b,aa,bb;

double arr[N],brr[N];
int nxt[N];
int main()
{
////    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    cin>>a.n>>b.n;
    for(int i=0;i<a.n;i++)
        a.p[i].in();
    for(int i=0;i<b.n;i++)
        b.p[i].in();
    a.getconvex(aa);
    b.getconvex(bb);
    aa.getline();
    bb.getline();
    int n=aa.n;
//    cout<<aa.n<<' '<<bb.n<<endl;
//    for(int i=0;i<aa.n;i++)
//        cout<<aa.l[i].len()<<' ';
//    cout<<endl;
//    for(int i=0;i<bb.n;i++)
//    {
//        cout<<bb.l[i].len()<<' ';
//    }
//    cout<<endl;
    if(n!=bb.n)
    {
        cout<<"NO";
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        arr[i*2+1]=aa.l[i].len();
        arr[i*2+2]=aa.p[i].rad(aa.p[(i-1+n)%n],aa.p[(i+1)%n]);
    }
    for(int i=2*n+1;i<=n*4;i++)
        arr[i]=arr[i-2*n];
    for(int i=0;i<n;i++)
    {
        brr[i*2+1]=bb.l[i].len();
        brr[i*2+2]=bb.p[i].rad(bb.p[(i-1+n)%n],bb.p[(i+1)%n]);
    }
    int la=n*4,lb=n*2;
//    for(int i=1;i<=la;i++)cout<<arr[i]<<' ';
//    cout<<endl;
//    for(int i=1;i<=lb;i++)cout<<brr[i]<<' ';
//    cout<<endl;
    for(int i=2,j=0;i<=lb;i++)
    {
        while(j&&sgn(brr[i]-brr[j+1]))j=nxt[j];
        if(sgn(brr[i]-brr[j+1])==0)j++;
        nxt[i]=j;
    }
    for(int i=1,j=0;i<=la;i++)
    {
        while(j&&sgn(arr[i]-brr[j+1]))j=nxt[j];
        if(sgn(arr[i]-brr[j+1])==0)j++;
//        cout<<i<<' '<<j<<endl;
        if(j==lb)
        {
//            cout<<j<<endl;
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}