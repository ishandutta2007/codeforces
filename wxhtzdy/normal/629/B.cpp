#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<pair<pair<int,int>,char>> v;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        char c;int a,b;
        cin>>c>>a>>b;
        v.pb({{a,b},c});
    }
    int sol=0;
    for(int i=1;i<=366;i++){
        int ca=0,cb=0;
        for(int j=0;j<(int)v.size();j++){
            if(v[j].second=='M'){
                if(v[j].first.first<=i&&v[j].first.second>=i)ca++;
            }else{
                if(v[j].first.first<=i&&v[j].first.second>=i)cb++;
            }
        }
        sol=max(sol,min(ca,cb)*2);
    }
    cout<<sol;
}