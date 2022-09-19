#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n1,n2,n3,n4;
    cin>>n1>>n2>>n3>>n4;
    int m1,m2,m3;
    pair<int,int> a1[n1+1];pair<int,int> a2[n2+1];pair<int,int> a3[n3+1];pair<int,int> a4[n4+1];
    for(int i=0;i<n1;++i) {cin>>a1[i].first;a1[i].second=i;}
    for(int i=0;i<n2;++i) {cin>>a2[i].first;a2[i].second=i;}
    for(int i=0;i<n3;++i) {cin>>a3[i].first;a3[i].second=i;}
    for(int i=0;i<n4;++i) {cin>>a4[i].first;a4[i].second=i;}
    a1[n1]={1e18,1e18};a2[n2]={1e18,1e18};a3[n3]={1e18,1e18};a4[n4]={1e18,1e18};
    sort(a1,a1+n1);sort(a2,a2+n2);sort(a3,a3+n3);sort(a4,a4+n4);
    set <pair<int,int> > u1,u2,u3;
    cin>>m1;
    for(int i=0;i<m1;++i) {int x,y;cin>>x>>y;x--;y--;u1.insert({x,y});}
    cin>>m2;
    for(int i=0;i<m2;++i) {int x,y;cin>>x>>y;x--;y--;u2.insert({x,y});}
    cin>>m3;
    for(int i=0;i<m3;++i) {int x,y;cin>>x>>y;x--;y--;u3.insert({x,y});}
    set <pair<int,vector <int> > > z1;
    z1.insert({a1[0].first+a2[0].first+a3[0].first+a4[0].first,{0,0,0,0}});
    while(!z1.empty())
    {
        pair<int,vector <int> > o=(*z1.begin());
        //cout<<o.first<<" o.first "<<endl;
        z1.erase(z1.begin());
        int ans1=o.first;
        vector <int> z=o.second;
        if(z[0]>=n1 || z[1]>=n2 || z[2]>=n3 || z[3]>=n4) continue;
        if(!u1.count({a1[z[0]].second,a2[z[1]].second}) && !u2.count({a2[z[1]].second,a3[z[2]].second}) && !u3.count({a3[z[2]].second,a4[z[3]].second}))
        {
            cout<<ans1;
            return 0;
        }
        else if(u1.count({a1[z[0]].second,a2[z[1]].second}))
        {
            z1.insert({a1[z[0]+1].first+a2[z[1]].first+a3[z[2]].first+a4[z[3]].first,{z[0]+1,z[1],z[2],z[3]}});
            z1.insert({a1[z[0]].first+a2[z[1]+1].first+a3[z[2]].first+a4[z[3]].first,{z[0],z[1]+1,z[2],z[3]}});
        }
        else if(u2.count({a2[z[1]].second,a3[z[2]].second}))
        {
        z1.insert({a1[z[0]].first+a2[z[1]+1].first+a3[z[2]].first+a4[z[3]].first,{z[0],z[1]+1,z[2],z[3]}});
        z1.insert({a1[z[0]].first+a2[z[1]].first+a3[z[2]+1].first+a4[z[3]].first,{z[0],z[1],z[2]+1,z[3]}});
        }
        else if(u3.count({a3[z[2]].second,a4[z[3]].second}))
        {
            z1.insert({a1[z[0]].first+a2[z[1]].first+a3[z[2]+1].first+a4[z[3]].first,{z[0],z[1],z[2]+1,z[3]}});
            z1.insert({a1[z[0]].first+a2[z[1]].first+a3[z[2]].first+a4[z[3]+1].first,{z[0],z[1],z[2],z[3]+1}});
        }
    }
    cout<<(-1);
    return 0;
}