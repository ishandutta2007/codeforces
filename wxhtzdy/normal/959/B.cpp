#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,m;
    cin>>n>>k>>m;
    map<string,int> r;
    string s[n];
    int cost[n];
    for(int i=0;i<n;i++)cin>>s[i];
    for(int i=0;i<n;i++)cin>>cost[i];
    int mc[k];
    for(int i=0;i<k;i++)mc[i]=1000000000;
    for(int i=0;i<k;i++){
        int x;
        cin>>x;
        for(int j=0;j<x;j++){
            int t;
            cin>>t;
            t--;
            r[s[t]]=i;
            mc[i]=min(mc[i],cost[t]);
        }
    }
    long long ans=0;
    for(int i=0;i<m;i++){
        string g;
        cin>>g;
        ans+=mc[r[g]];
    }
    cout<<ans;
}