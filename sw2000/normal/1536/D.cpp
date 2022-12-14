#include<bits/stdc++.h>
using namespace std;
const int N=1000+10;

bool solve(){
    int n;cin>>n;
    vector<int>arr(n);
    for(auto &i:arr)cin>>i;
    set<int>s;
    int lst;
    for(auto i:arr){
        if(!s.empty()){
            if(i>lst&&s.upper_bound(lst)!=s.end()&&*s.upper_bound(lst)<i)return 0;
            if(i<lst&&s.find(lst)!=s.begin()&&*(--s.find(lst))>i)return 0;
        }
        s.insert(i);
        lst=i;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("A.in","r",stdin);
    int _;cin>>_;
    while(_--){
        cout<<(solve()?"YES":"NO")<<'\n';
    }
}