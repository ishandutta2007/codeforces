#include <bits/stdc++.h>
using namespace std;
int t;

int main(){
    cin >> t;
    while(t--){
    int n;
    cin >> n;
    bool win[n];
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    win[n-1] = true;
    for(int i=n-2;i>=0;i--){
        if(a[i]==1){
            win[i] = !win[i+1];
        }
        else{
            win[i] = true;
        }
    }
    if(win[0]){
        cout << "First" << endl;
    }
    else{
        cout << "Second" << endl;
    }
    }
}