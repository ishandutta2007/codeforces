#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
map<pair<int,int>,int>mp;
int fx[N],fy[N];
pair<int,int>ans[N];
set<pair<int,int>>st;
pair<int,int> solve(int x,int y){
    int xu=x,yu=y+1,xd=x,yd=y-1,xl=x-1,yl=y,xr=x+1,yr=y;
    if(mp.find({xu,yu})==mp.end())return {xu,yu};
    if(mp.find({xd,yd})==mp.end())return {xd,yd};
    if(mp.find({xl,yl})==mp.end())return {xl,yl};
    if(mp.find({xr,yr})==mp.end())return {xr,yr};
}
bool check(int x,int y){
    int xu=x,yu=y+1,xd=x,yd=y-1,xl=x-1,yl=y,xr=x+1,yr=y;
    if(mp.find({xu,yu})==mp.end()||mp.find({xd,yd})==mp.end()||mp.find({xl,yl})==mp.end()||mp.find({xr,yr})==mp.end())return 1;
    return 0;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&fx[i],&fy[i]),mp[{fx[i],fy[i]}]=i,ans[i]={-10000000,-10000000};
    vector<pair<int,int>>v;
    for(int i=1;i<=n;i++){
        if(check(fx[i],fy[i]))ans[i]=solve(fx[i],fy[i]),v.push_back({fx[i],fy[i]});
    }
    while(v.size()){
        vector<pair<int,int>>vec;
        vec.clear();
        for(auto [x,y]:v){
            int xu=x,yu=y+1,xd=x,yd=y-1,xl=x-1,yl=y,xr=x+1,yr=y;
            if(mp.find({xu,yu})!=mp.end()&&ans[mp[{xu,yu}]]==make_pair(-10000000,-10000000))ans[mp[{xu,yu}]]=ans[mp[{x,y}]],vec.push_back(make_pair(xu,yu));
            if(mp.find({xd,yd})!=mp.end()&&ans[mp[{xd,yd}]]==make_pair(-10000000,-10000000))ans[mp[{xd,yd}]]=ans[mp[{x,y}]],vec.push_back(make_pair(xd,yd));
            if(mp.find({xl,yl})!=mp.end()&&ans[mp[{xl,yl}]]==make_pair(-10000000,-10000000))ans[mp[{xl,yl}]]=ans[mp[{x,y}]],vec.push_back(make_pair(xl,yl));
            if(mp.find({xr,yr})!=mp.end()&&ans[mp[{xr,yr}]]==make_pair(-10000000,-10000000))ans[mp[{xr,yr}]]=ans[mp[{x,y}]],vec.push_back(make_pair(xr,yr));
        }
        v=vec;
    }
    for(int i=1;i<=n;i++)printf("%d %d\n",ans[i].first,ans[i].second);
    return  0;
}