#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int x1,y1,z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        int ret = 0;
        int x =0;
        ret+=2*min(z1,y2);
        x = min(z1,y2);
        z1-=x; y2-=x;
        x = min(z1,z2);
        z1-=x; z2-=x;
        x = min(y1,y2);
        y1-=x; y2-=x;
        x = min(y1,x2);
        y1-=x; x2-=x;
        x = min(y1,z2);
        ret-=2*x;
        cout << ret << endl;
    }
}