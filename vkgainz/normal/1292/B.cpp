#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<ll,ll>> points;
ll x_0,y_0,ax,ay,bx,by,xs,ys,t;
int get(int idx, ll left){
    if(left<0) return -1;
    ll temp = left;
    int ret = 0;
    int x = 0;
    int n = idx;
    for(int i=idx-1;i>=0;i--){
        if(points[n].first-points[i].first+points[n].second-points[i].second <=temp){
            temp-=(points[n].first-points[i].first+points[n].second-points[i].second);
            ++x;
            n = i;
        }
    }
    for(int i=idx+1;i<points.size();i++){
        if(points[i].first-points[n].first+points[i].second-points[n].second <=temp){
            temp-=(points[i].first-points[n].first+points[i].second-points[n].second);
            ++x;
            n = i;
        }
    }
    ret=  max(ret,x);
    temp = left;
    x = 0;
    n = idx;
    for(int i=idx+1;i<points.size();i++){
        if(points[i].first-points[n].first+points[i].second-points[n].second <=temp){
            temp-=(points[i].first-points[n].first+points[i].second-points[n].second);
            ++x;
            n = i;
        }
    }
    for(int i=idx-1;i>=0;i--){

    }
    ret = max(ret,x);
    return ret;
}
int main(){
   cin >> x_0 >> y_0 >> ax >> ay >> bx >> by >> xs >> ys >> t;
   points.push_back({x_0,y_0});
   ll currX = x_0, currY= y_0;
   while(currX<=(1e18-bx)*1.0*1LL/ax && currY<=(1e18-by)*1.0*1LL/ay){
       currX = ax*1LL*currX+bx;
       currY = ay*1LL*currY+by;
       points.push_back({currX,currY});
   }
   int ans = 0;
   for(int i=0;i<points.size();i++){
        ans = max(ans,get(i,t-(abs(xs-points[i].first)+abs(ys-points[i].second)))+1);
   }
   cout << ans << endl;
}