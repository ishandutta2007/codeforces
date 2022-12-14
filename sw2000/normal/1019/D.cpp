#include <bits/stdc++.h>
using namespace std;
const int N=5000+10;
typedef long long ll;
struct Point
{
    ll x, y;
    Point() {}
    Point(ll _x, ll _y): x(_x), y(_y) {}
    void in(){cin>>x>>y;}
    void o(){cout<<x<<' '<<y<<endl;}
    bool operator<(Point b)const{return x < b.x || ( x == b.x && y < b.y );}
    Point operator-(Point b) {return Point(x - b.x, y - b.y);}
    ll operator^(Point b) {return x * b.y - y * b.x;}
} p[N];
struct Line
{
    int x, y;
    double k;
    bool operator<(Line b)const{return k < b.k;}
};

int n,rk[N],id[N];
ll S;
vector<Line>L;
int main()
{
    cin>>n>>S;
    S*=2;
    for( int i = 1 ; i <= n ; i++ )p[i].in();
    sort( p + 1, p + n + 1 );
    for( int i = 1 ; i <= n ; i++ ) id[ i ] = rk[ i ] = i;
    for( int i = 1 ; i < n ; i++ )//k[-pi/2,pi/2)
        for( int j = i + 1 ; j <= n ; j++ )
            L.push_back({i,j,atan2(p[j].y-p[i].y,p[j].x-p[i].x)});
    sort(L.begin(),L.end());
    for(auto i:L)
    {
        int a=i.x,b=i.y;
        if( id[ a ] > id[ b ] ) swap( a, b );

        int l=1,r=id[a];
        while(l<r-1)
        {
            int mid=l+r>>1;
            if(abs( (p[b]-p[a])^(p[b]-p[rk[mid]]) )>=S)
            {
                l=mid;
            }
            else
            {
                r=mid;
            }
        }
        if(abs( (p[b]-p[a])^(p[b]-p[rk[l]]) )==S)
        {
            cout<<"Yes"<<endl;
            p[b].o();
            p[a].o();
            p[rk[l]].o();
            return 0;
        }
        swap(id[a],id[b]);
        swap(rk[ id[a] ],rk[ id[b] ]);
    }
    cout<<"No"<<endl;
    return 0;
}