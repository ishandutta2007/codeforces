#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int n;
    cin >> n;
    int cnt = 0;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        cnt+=(x%2);
    }
    cout << min(cnt,n-cnt) << endl;
}