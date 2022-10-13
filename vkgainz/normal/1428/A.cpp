#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t; cin >> t;
    while(t--){ 
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int a = abs(x1-x2);
        int b = abs(y1-y2);
        if(a==0 || b==0) {
            cout << max(a,b) << endl;
        }
        else{
            cout << (a+b+2) << endl;
        }
    }
}