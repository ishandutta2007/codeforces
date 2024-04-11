#include<bits/stdc++.h>
using namespace std;

int main(){
    string a, b, drc;
    int x1, y1, x2, y2;
    cin >> a >> b;
    drc = a;
    x1 = a[0] - 'a';
    y1 = a[1] - '0';
    x2 = b[0] - 'a';
    y2 = b[1] - '0';
    int dx = abs(x1 - x2), dy = abs(y1 - y2), dxy = min(dx, dy);
    cout << max(dx, dy) << endl;
    if (x1 < x2){
        drc[0] = 'R';
    }
    else{
        drc[0] = 'L';
    }
    if (y1 < y2){
        drc[1] = 'U';
    }
    else{
        drc[1] = 'D';
    }
    for (int i = 0; i < dxy; i++){
        cout << drc << endl;
    }
    dx -= dxy;
    dy -= dxy;
    for (int i = 0; i < dx; i++){
        if (x1 < x2){
            cout << 'R';
        }
        else{
            cout << 'L';
        }
        cout << endl;
    }
    for (int i = 0; i < dy; i++){
        if (y1 < y2){
            cout << 'U';
        }
        else{
            cout << 'D';
        }
        cout << endl;
    }
}