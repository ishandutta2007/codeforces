#include <bits/stdc++.h>
using namespace std;
map<int,int> f;
map<int,int> val;
int best = 1000000000;
int k;
multiset<int> dfs(int i){
    multiset<int> ret;
    if(f[i]==0) return ret;
    multiset<int> a = dfs(2*i);
    multiset<int> b = dfs(2*i+1);
    for(auto &it : a){
        ret.insert(it+1);
    }
    for(auto &it : b){
        ret.insert(it+1);
    }
    for(int x=0;x<val[i];x++){
        ret.insert(0);
    }
    int temp = 0;
    if(ret.size()>=k){
        auto it = ret.begin();
        for(int i=0;i<k;i++){
            temp+=(*it);
            it++;
        }
        best = min(best,temp);
    }
    return ret;
}
int main(){
    int n;
    cin >> n >> k;
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        int temp = a[i];
        val[a[i]]++;
        while(temp>0){
            f[temp]++;
            temp/=2;
        }
    }
    dfs(1);
    cout << best << endl;
}