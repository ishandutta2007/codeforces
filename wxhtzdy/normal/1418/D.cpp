#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,q;scanf("%i%i",&n,&q);
    multiset<int> x,diff;
    auto Add=[&](int i){
        auto it=x.lower_bound(i);
        if(it!=x.begin()&&it!=x.end())diff.erase(diff.find(*it-*prev(it)));
        if(it!=x.begin())diff.insert(i-*prev(it));
        if(it!=x.end())diff.insert(*it-i);
        x.insert(i);
    };
    auto Del=[&](int i){
        auto it=x.find(i);
        if(it!=x.begin())diff.erase(diff.find(i-*prev(it)));
        if(it!=prev(x.end()))diff.erase(diff.find(*next(it)-i));
        if(it!=x.begin()&&it!=prev(x.end()))diff.insert(*next(it)-*prev(it));
        x.erase(x.find(i));
    };
    auto Solve=[&](){
        if((int)x.size()<=1||diff.empty())return 0;
        return *prev(x.end())-*x.begin()-*prev(diff.end());
    };
    for(int i=0,x;i<n;i++)scanf("%i",&x),Add(x);
    printf("%i\n",Solve());
    while(q--){
        int t,i;scanf("%i%i",&t,&i);
        if(t==0)Del(i);
        else Add(i);
        printf("%i\n",Solve());
    }
    return 0;
}