#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> x,pair<int,int> y){
    if(x.first!=y.first)return x.first<y.first;
    else return x.second>y.second;
}
int main(){
    int q;scanf("%i",&q);
    set<pair<int,int>> A;
    set<pair<int,int>,decltype(cmp)*> B(cmp);
    int cnt=1;
    vector<int> ans;
    while(q--){
        int t;scanf("%i",&t);
        if(t==1){
            int x;scanf("%i",&x);
            A.insert({cnt,x});
            B.insert({x,cnt});
            cnt++;
        }else{
            if(t==2){
                auto it=*A.begin();
                ans.push_back(it.first);
                A.erase(A.begin());
                auto nxt=B.lower_bound({it.second,it.first});
                B.erase(nxt);
            }else{
                auto pos=B.end();
                --pos;
                auto it=*pos;
                ans.push_back(it.second);
                B.erase(pos);
                auto nxt=A.lower_bound({it.second,it.first});
                A.erase(nxt);
            }
        }
    }
    for(int c:ans)printf("%i ",c);
    return 0;
}