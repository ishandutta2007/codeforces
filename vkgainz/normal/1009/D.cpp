#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define f first
#define s second

int main(){
    int n,m;
    cin >> n >> m;
    if(m<n-1){
        cout << "Impossible";
        return 0;
    }
    vector<pair<int,int>> ans;
    for(int i=1;i<=n-1;i++) ans.push_back({i,i+1});
    m-=(n-1);
    for(int i=3;i<=n && m>0;i++){
        for(int j=1;j<i-1 && m>0;j++){
            if(__gcd(i,j)==1){
                ans.push_back({i,j});
                --m;
            }
        }
    }
    if(m>0) {
        cout << "Impossible";
        return 0;
    }
    cout << "Possible" << endl;
    for(auto &it : ans) cout << it.first << " " << it.second << endl;
}