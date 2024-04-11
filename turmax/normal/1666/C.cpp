#include <bits/stdc++.h>

using namespace std;
#define int long long
#define x first
#define y second
vector<vector<int> > ans;
void pl(int a,int b,int c,int d) {ans.push_back({a,b,c,d});}
void get() {cout<<ans.size()<<'\n';for(auto h:ans) {for(auto h1:h) cout<<h1<<' '; cout<<'\n';} exit(0);}
void f(pair<int,int> u,pair<int,int> v)
{
    pair<int,int> d={u.x,v.y};
    pl(v.x,v.y,d.x,d.y);pl(d.x,d.y,u.x,u.y);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n=3;pair<int,int> a[n];for(int i=0;i<n;++i) {cin>>a[i].first>>a[i].second;}
    sort(a,a+n);
    if(a[1].y>=a[0].y && a[1].y<=a[2].y) {f(a[0],a[1]);f(a[1],a[2]);get();}
    if(a[1].y>=a[0].y && a[1].y>=a[2].y) {if(a[0].y>=a[2].y) {f(a[1],a[0]);f({a[1].x,a[0].y},a[2]);get();} else {f({a[1].x,a[2].y},a[0]);f(a[1],a[2]);get();}}
    if(a[1].y<=a[0].y && a[1].y<=a[2].y) {if(a[0].y<=a[2].y) {f(a[1],a[0]);f({a[1].x,a[0].y},a[2]);get();} else {f({a[1].x,a[2].y},a[0]);f(a[1],a[2]);get();}}
    else {f(a[0],a[1]);f(a[1],a[2]);get();}
    return 0;
}