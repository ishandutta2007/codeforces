#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%i",&t);
    while(t--){
        int n;scanf("%i",&n);
        int a[n];
        map<int,int> cnt;
        for(int i=0;i<n;i++){
            scanf("%i",&a[i]);
            cnt[a[i]]++;
        }
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            if(cnt[a[i]]==1)v.push_back({a[i],i+1});
        }
        sort(v.begin(),v.end());
        if(v.empty())printf("-1\n");
        else printf("%i\n",v[0].second);
    }
}