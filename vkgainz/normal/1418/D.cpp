#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n,q;
    cin >> n >> q;
    int p[n];
    for(int i=0;i<n;i++) cin >> p[i];
    sort(p,p+n);
    set<int> pos;
    multiset<int,greater<int>> gaps;
    for(int i=0;i<n;i++){
        pos.insert(p[i]);
    }
    for(int i=0;i<n-1;i++){
        gaps.insert(p[i+1]-p[i]);
    }
    auto it = gaps.begin();
    cout << p[n-1]-p[0]-(*it) << endl;
    for(int i=0;i<q;i++){
        int a,x; cin >> a >> x;
        if(a==0){
            if(pos.size()==1){
                pos.erase(x);
            }
            else{
                pos.erase(x);
                auto less = pos.upper_bound(x);
                if(less==pos.begin()){
                    auto more = pos.upper_bound(x);
                    if(more!=pos.end()){
                        gaps.erase(gaps.lower_bound((*more)-x));
                    }
                }
                else{
                    --less;
                    auto more = pos.upper_bound(x);
                    if(more==pos.end()){
                        gaps.erase(gaps.lower_bound(x-(*less)));
                    }
                    else{
                        gaps.erase(gaps.lower_bound(x-(*less)));
                        gaps.erase(gaps.lower_bound((*more)-x));
                        gaps.insert((*more)-(*less));
                    }
                }
            }
        }
        else{
            if(pos.empty()){
                pos.insert(x);
            }
            else{
                auto less = pos.upper_bound(x);
                if(less==pos.begin()){
                    auto more = pos.upper_bound(x);
                    if(more!=pos.end()){
                        gaps.insert((*more)-x);
                    }
                }
                else{
                    --less;
                    auto more = pos.upper_bound(x);
                    if(more==pos.end()){
                        gaps.insert(x-(*less));
                    }
                    else{
                        gaps.insert(x-(*less));
                        gaps.insert((*more)-x);
                        gaps.erase(gaps.lower_bound((*more)-(*less)));
                    }
                }
                pos.insert(x);
            }
        }
        auto less = pos.begin();
        auto more = pos.rbegin();
        auto largest = gaps.begin();
        if(pos.empty()) cout << 0 << endl;
        else
        cout << (*more)-(*less)-(*largest) << endl;
    }
}