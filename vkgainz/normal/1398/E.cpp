#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n; cin >> n;
    set<ll> fire;
    set<ll> lightning;
    set<ll> largest;
    set<ll, greater<ll>> smallest;
    ll sum = 0;
    ll sumLargest = 0;
    while(n--){
        int tp;
        ll d; 
        cin >> tp >> d;
        if(tp){ // lightning
            if(d>0){ //learns
                sum+=d;
                lightning.insert(d);
                auto x = smallest.begin();
                if(smallest.size()==0){
                    largest.insert(d);
                    sumLargest+=d;
                }
                else if(d<(*x)){
                    sumLargest+=(*x);
                    largest.insert(*x);
                    smallest.erase(x);
                    smallest.insert(d);
                }
                else{
                    largest.insert(d);
                    sumLargest+=d;
                }
            }
            else{
                d = -d;
                sum-=d;
                lightning.erase(d);
                
                if(largest.find(d)!=largest.end()){
                    
                    largest.erase(d);
                    sumLargest-=d;
                }
                else{
                    smallest.erase(d);
                    auto x = largest.begin();
                    largest.erase(x);
                    smallest.insert(*x);
                    sumLargest-=(*x);
                }
            }
        }
        else{ //fire
            if(d>0){ //learn
                sum+=d;
                fire.insert(d);
                auto x = largest.begin();
                if(largest.size()==0){
                    smallest.insert(d);
                }
                else if(d>(*x)){
                    sumLargest+=(d-(*x));
                    largest.insert(d);
                    largest.erase(*x);
                    smallest.insert(*x);
                }
                else{
                    smallest.insert(d);
                }
            }
            else{
                d = -d;
                sum-=d;
                fire.erase(d);
                if(largest.find(d)!=largest.end()){
                    //smallest.size() necessarily greater than 0?
                    largest.erase(d);
                    sumLargest-=d;
                    if(smallest.size()>0){
                        auto x = smallest.begin();
                        smallest.erase(x);
                        largest.insert(*x);
                        sumLargest+=(*x);
                    }
                }
                else{
                    smallest.erase(d);
                }
            }
        }
        ll ans = sum+sumLargest;
        if(fire.size()>0 && lightning.size()>0){
            auto x = lightning.begin();
            auto y = fire.rbegin();
            if(*x>*y){
                ans-=*x;
                ans+=(*y);
            }
        }
        else if(fire.size()==0 && lightning.size()>0){
            auto x = lightning.begin();
            ans-=(*x);
            
        }
        cout << ans << endl;
        //check for case
        //query

    }
}