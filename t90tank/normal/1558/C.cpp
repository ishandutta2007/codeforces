#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector> 
using namespace std; 
const int maxn = 4000006; 

int n; 
int a[maxn]; 
int p[maxn]; 
vector<int> ans; 

bool reverse(int k) {
    //cout<<k<<endl;
    if (k < 0 || k > n || k % 2 != 1) return false; 
    ans.push_back(k); 
    for (int i = 1; i < k+1-i; ++i) {
        swap(a[i], a[k+1-i]);
        swap(p[a[i]], p[a[k+1-i]]);  
    }
    return true; 
}

#define TRY(x) if (!(x)) return false

bool solve() {
    ans.clear(); 
    for (int i = n; i > 1; i -= 2) {
        TRY(reverse(p[i]));
        TRY(reverse(p[i-1]-1)); 
        TRY(reverse(i));
        TRY(reverse(p[i]));
        TRY(reverse(i));   
    } 
    //for (int i = 1; i <= n; ++i) cout<<i<<','; cout<<endl; 
    return true; 
}

int main() {
    int t; 
    cin>>t; 
    while (t--) {
        cin>>n;
        for (int i = 1; i <= n; ++i) {
            cin>>a[i]; 
            p[a[i]] = i; 
        } 
        if (solve()) {
            cout<<ans.size()<<endl; 
            for (auto i : ans) cout<<i<<' '; 
            cout<<endl; 
        }
        else {
            cout<<"-1\n"; 
        }
    }
}