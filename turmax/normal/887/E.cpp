#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<double,double> ptd;
double dst(double x1,double y1,double x2,double y2)
{
    //cout<<x1<<" x1 "<<y1<<" y1 "<<x2<<" x2 "<<y2<<" y2 "<<endl;
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+0.0);
}
double dist(int x,int y,int x1,int y1,int x2,int y2)
{
    int sq2=(x*y1+x1*y2+x2*y-x*y2-x1*y-x2*y1);
    double f=dst(x1,y1,x2,y2);
    return (sq2+0.0)/f;
}
double get(int x1,int y1,int x2,int y2,int x,int y,double h,int val)
{
    double mx=(x1+x2+0.0)/2.0;double my=(y1+y2+0.0)/2.0;
    double l=dst(x1,y1,x2,y2);
    double ox=(mx+(h*(y2-y1))/l);double oy=(my+(h*(x1-x2))/l);
    //cout<<x1<<" x1 "<<y1<<" y1 "<<x2<<" x2 "<<y2<<" y2 "<<h<<" h "<<ox<<" ox "<<oy<<" oy "<<x<<" x "<<y<<" y "<<endl;
    double z1=dst(ox,oy,x1,y1);double z2=dst(ox,oy,x2,y2);double z3=dst(ox,oy,x,y);
    //cout<<z1<<" z1 "<<z2<<" z2 "<<endl;
    assert(abs(z1/z2-1)<1e-6);
    //cout<<(z1-z3)<<" z1-z3 "<<endl;
    //cout<<val<<" val "<<endl;
    return (z1-z3)>=val;
}
double f1(int x1,int y1,int x2,int y2,array <int,3> s)
{
    double hlow=(-1e12-1e9);double hup=1e12+1e9;
    bool oklow=get(x1,y1,x2,y2,s[0],s[1],hlow,s[2]);
    bool okup=get(x1,y1,x2,y2,s[0],s[1],hup,s[2]);
    assert(oklow!=okup);
    while(hup-hlow>1e-4)
    {
        double hmid=(hlow+hup)/2;
        bool ok=get(x1,y1,x2,y2,s[0],s[1],hmid,s[2]);
        if(ok==oklow) hlow=hmid;
        else hup=hmid;
    }
    return hlow;
}
double f2(int x1,int y1,int x2,int y2,array <int,3> s)
{
    double hlow=(-1e12-1e9);double hup=1e12+1e9;
    bool oklow=get(x1,y1,x2,y2,s[0],s[1],hlow,-s[2]);
    bool okup=get(x1,y1,x2,y2,s[0],s[1],hup,-s[2]);
    assert(oklow!=okup);
    while(hup-hlow>1e-4)
    {
        double hmid=(hlow+hup)/2;
        bool ok=get(x1,y1,x2,y2,s[0],s[1],hmid,-s[2]);
        if(ok==oklow) hlow=hmid;
        else hup=hmid;
    }
    return hlow;
}
ptd go(int x1,int y1,int x2,int y2,array <int,3> s)
{
    //cout<<s[2]<<" s[2] "<<endl;
   double u1=f1(x1,y1,x2,y2,s);double u2=f2(x1,y1,x2,y2,s);
   if(u1>u2) swap(u1,u2);
   return {u1,u2};
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
    int n;cin>>n;array <int,3> a[n];
    for(int i=0;i<n;++i) for(int j=0;j<3;++j) cin>>a[i][j];
    vector <ptd> v;
    for(int i=0;i<n;++i) {ptd ban=go(x1,y1,x2,y2,a[i]);v.push_back(ban);}
    sort(v.begin(),v.end());
    int cur=0;
    double ma=(-1e18);
    vector <double> o;
    for(auto h:v)
    {
        if(h.first>ma) {o.push_back(ma);o.push_back(h.first);}
        if(h.first>=0 && ma<=0) o.push_back(0);
        ma=max(ma,h.second);
    }
    o.push_back(ma);
    double ans1=1e18;
    for(auto z:o) ans1=min(ans1,abs(z));
    double f=dst(x1,y1,x2,y2)/2;
    cout<<setprecision(15)<<sqrt(ans1*ans1+f*f);
    return 0;
}