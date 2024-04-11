#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
set<int,greater<int>> divisors;
set<int> covered;
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        vector<pair<int,int>> factors;
        divisors.clear();
        divisors.insert(1);
        divisors.insert(n);
        covered.clear();
        int temp = n;
        for(int i=2;i<=sqrt(temp);i++){
            if(temp%i==0){
                int f = 0;
                while(temp%i==0){
                    temp/=i;
                    ++f;
                }
                factors.push_back({i,f});
            }
        }
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                divisors.insert(i);
                divisors.insert(n/i);
            }
        }
        if(temp>1) factors.push_back({temp,1});
        if(factors.size()==1){
            
            for(int i=1;i<=factors[0].second;i++){
                int x = pow(factors[0].first,i);
                cout << x << " ";
            }
            cout << endl;
            cout << 0 << endl;
        }
        else if(factors.size()==2){
            if(factors[0].second==1 && factors[1].second==1){
                cout << n << " " << factors[0].first << " " << factors[1].first << endl;
                cout << 1 << endl;
            }
            else{
                cout << n << " ";
                for(int i=1;i<=factors[0].second;i++){
                    cout << pow(factors[0].first,i) << " ";
                }
                for(int i=1;i<=factors[0].second;i++){
                    for(int j=1;j<=factors[1].second;j++){
                        int x = pow(factors[0].first,i);
                        int y = pow(factors[1].first,j);
                        if(x*y!=n)
                            cout << x*y << " ";
                    }
                }
                for(int j=1;j<=factors[1].second;j++){
                    int y = pow(factors[1].first,j);
                    cout << y << " ";
                }
                cout << endl;
                cout << 0 << endl;
            }
        }
        else{
            for(int i=0;i<factors.size();i++){
                covered.insert(factors[i].first*factors[(i+1)%factors.size()].first);
            }
            for(int i=0;i<factors.size();i++){
                cout << factors[i].first*factors[(i+1)%factors.size()].first << " ";
                for(int j : divisors){
                    if(j%factors[(i+1)%factors.size()].first==0 && !covered.count(j)){
                        cout << j << " ";
                        covered.insert(j);
                    }
                }
            }
            cout << endl;
            cout << 0 << endl;
        }
    }
}