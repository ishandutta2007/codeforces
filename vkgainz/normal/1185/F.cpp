#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n, m;
    cin >> n >> m;
    int cnt[512];
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++) {
        int f; cin >> f;
        int a = 0;
        for(int j=0;j<f;j++){ 
            int x; cin >> x;
            a+=1<<(x-1);
        }
        ++cnt[a];
    }
    vector<pair<int,int>> get[512];
    for(int i=0;i<m;i++) {
        int c;
        int r;
        cin >> c >> r;
        int a = 0;
        for(int j=0;j<r;j++) {
            int x; cin >> x;
            a+=1<<(x-1);
        }
        get[a].push_back({c,i});
    }
    for(int i=0;i<512;i++) {
        sort(get[i].begin(),get[i].end());
    }
    pair<int,int> ans = {-1,-1};
    int num = -1;
    int cost = 2000000000;
    for(int i=0;i<512;i++) {
        for(int j=0;j<512;j++) {
            int tempNum = 0;
            int tempCost;
            if(i==j) {
                if(get[i].size()>=2) tempCost = get[i][0].first+get[i][1].first;
                else continue;
            }
            else {
                if(get[i].size()>=1 && get[j].size()>=1)
                    tempCost = get[i][0].first+get[j][0].first;
                else continue;
            }
            int x = i|j;
            for(int k=0;k<512;k++) {
                if((x|k)==x) tempNum+=cnt[k];
            }
            if(tempNum>num) {
                num = tempNum, cost = tempCost;
                if(i==j) ans = {get[i][0].second,get[i][1].second};
                else ans = {get[i][0].second,get[j][0].second};
            }
            else if(tempNum==num) {
                if(tempCost<cost) {
                    cost = tempCost;
                    if(i==j) ans = {get[i][0].second, get[i][1].second};
                    else ans = {get[i][0].second,get[j][0].second};
                }
            }
        }
    }
    cout << ans.first+1 << " " << ans.second+1 << endl;
}