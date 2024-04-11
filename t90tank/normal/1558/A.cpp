#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std; 

set<int> S; 

int main() {
    int t; 
    cin>>t; 
    while (t--) {
        int a, b; 
        cin>>a>>b;
        int l = (a+b)/2;
        int r = (a+b+1)/2; 
        S.clear();    
        for (int i = 0; i <= a; ++i) {
            if (i <= l) {
                if (a-i <= r)
                    S.insert(i + r-(a-i)); 
            }
            if (i <= r) {
                if (a-i <= l)
                    S.insert(i + l-(a-i)); 
            }
        }
        cout<<S.size()<<endl; 
        for (auto i : S)
            cout<<i<<' ';
        cout<<endl; 
    }
}