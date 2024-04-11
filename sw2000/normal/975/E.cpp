#include<bits/stdc++.h>
using namespace std;
#define K(x...){cerr<<"BEGIN    "<<#x<<"->";Err(x);cerr<<"   END"<<endl;}
void Err(){}
template<class T,class... A>void Err(T a,A... x){cerr<<a<<',';Err(x...);}
template<class X,class Y,class...A>void Err(pair<X,Y> a,A... x){cerr<<'('<<a.first<<','<<a.second<<"),";Err(x...);}
template<template<class...> class T,class t,class...A>void Err(T<t>a,A...x){cerr<<a.size()<<":{";for(auto v:a)Err(v);cerr<<"},";Err(x...);}
typedef long long ll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll l,ll r){return uniform_int_distribution<ll>(l,r)(rng);}
template<class T>void Min(T &a,const T b){if(a>b)a=b;}
template<class T>void Max(T &a,const T b){if(a<b)a=b;}
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define endl '\n'
#ifdef ONLINE_JUDGE
#define freopen(a,b,c)
#define K(a...)
#endif
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int>vi;
typedef vector<ll>vl;
typedef long double ld;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;
const int N=1e3+10,M=500;
const ll mod=1e9+7;
const double PI=acos(-1);
const double eps=1e-8;
int sgn(double x){return x<-eps?-1:(x<eps?0:1);}
struct Point{
    double x,y;
    void in(){scanf("%lf%lf",&x,&y);}
    void out(){printf("%.8lf %.8lf\n",x,y);}
    Point operator+(Point b){return {x+b.x,y+b.y};}
    Point operator-(Point b){return {x-b.x,y-b.y};}
    Point operator*(double k){return {x*k,y*k};}
    Point operator/(double k){return {x/k,y/k};}
    double operator^(Point b){return x*b.y-y*b.x;}
    double operator*(Point b){return x*b.x+y*b.y;}
    Point rot(double angle){
        double c=cos(angle),s=sin(angle);
        return {x*c-y*s,x*s+y*c};
    }
    double cross(Point b,Point c){return (b-*this)^(c-*this);}
    double dot(Point b,Point c){return (b-*this)*(c-*this);}
    double rad(Point a,Point b){return atan2(cross(a,b),dot(a,b));}
};
struct Pol{
    vector<Point>p;
    Point getbarycentre(){
        Point ret{0,0};
        double area=0;
        for(int i=1;i<p.size()-1;i++){
            double tmp=p[0].cross(p[i],p[i+1]);
            if(!sgn(tmp))continue;
            area+=tmp;
            ret.x+=(p[0].x+p[i].x+p[i+1].x)/3*tmp;
            ret.y+=(p[0].y+p[i].y+p[i+1].y)/3*tmp;
        }
        if(sgn(area))ret=ret/area;
        return ret;
    }
};
int main(){
//    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    int n,m;cin>>n>>m;
    Pol sw;
    sw.p.resize(n);
    for(auto &i:sw.p)i.in();
    Point o=sw.getbarycentre();
    int id[2]{0,1};
    Point p[2]{sw.p[0],sw.p[1]};
    auto update=[&](int i){
        if(i==id[0])return p[0];
        Point t=sw.p[id[0]];
        double angle=t.rad(o,{t.x,t.y-1});
        Point d=(sw.p[i]-t).rot(angle);
        return p[0]+d;
    };
    bool rev=0;
    for(int i=0;i<m;i++){
        int op;cin>>op;
        if(op==1){
            int t,f;cin>>t>>f;t--,f--;
            if(id[0]==t){
                swap(id[0],id[1]);
                swap(p[0],p[1]);
            }
            id[1]=f;
            p[1]=update(f);
            rev=1;
        }
        else{
            int v;cin>>v;v--;
            if(!rev)sw.p[v].out();
            else{
                update(v).out();
            }
        }
    }
}