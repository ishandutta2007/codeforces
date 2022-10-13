#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
vector<vector<int>> bucket;
pair<ll,ll> getNum(vector<int> &x,int bit){
    vector<int> temp;
    for(int i=0;i<x.size();i++){
        if(x[i]&(1<<bit)) temp.push_back(1);
        else temp.push_back(0);
    }
    int cnt0 = 0;
    int cnt1 = 0;
    ll ans1 = 0;
    ll ans2 = 0;
    for(int i=0;i<temp.size();i++){
        if(temp[i]==0){
            ans1+=cnt1;
            ++cnt0;
        }
        else{
            ans2+=cnt0;
            ++cnt1;
        }
    }
    return {ans1,ans2};
}
int main(){
    scanf("%d",&n);
    vector<int> a;
    for(int i=0;i<n;i++){
        int x; scanf("%d",&x);
        a.push_back(x);
    }
    vector<int> x;
    for(int i=0;i<n;i++) x.push_back(a[i]);
    bucket.push_back(x);
    ll num = 0;
    int ans = 0;
    for(int j=29;j>=0;j--){
        pair<ll,ll> temp = {0,0};
        for(auto &it : bucket){
            if(!it.empty()){
                pair<ll,ll> x = getNum(it,j);
                temp.first+=x.first;
                temp.second+=x.second;
            }
        }
        if(temp.second<temp.first){
            //switch;
            ans+=(1<<j);
        }
        num+=min(temp.first,temp.second);
        vector<vector<int>> next;
        for(auto &it : bucket){
            vector<int> left;
            vector<int> right;
            for(int x : it){
                if(x&(1<<j)){
                    right.push_back(x);
                }
                else{
                    left.push_back(x);
                }
            }
            
            if(!left.empty()) next.push_back(left);
            if(!right.empty()) next.push_back(right);
        }
        bucket.clear();
        bucket = next;
        //update buckets
    }
    cout << num << " " << ans << endl;
}