#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){

    ios_base::sync_with_stdio(false); 
        cin.tie(NULL);
    int n, s;
    cin >> n >> s;
    if(s>=2*n){
        cout << "YES" << endl;
        for(int i=0;i<n-1;i++){
            cout << 2 << "\n";
        }
        cout << s-2*(n-1) << "\n";
        cout << 1 << "\n";
    }
    else{
        cout << "NO" << "\n";
    }
}