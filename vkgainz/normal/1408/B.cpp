#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

int main(){
    int t; cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int a[n];
        for(int i=0;i<n;i++) cin >> a[i];
        int numDistinct = 0;
        set<int> s;
        for(int i=0;i<n;i++) s.insert(a[i]);
        if(k==1){
            if(a[n-1]!=a[0]) cout << -1 << endl;
            else cout << 1 << endl;
        }
        else if(s.size()<=k){
            cout << 1 << endl;
        }
        else{
            numDistinct = (s.size()-1+k-2)/(k-1);
            cout << numDistinct << endl;
        }
    }
}