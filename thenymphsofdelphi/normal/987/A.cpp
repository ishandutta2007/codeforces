#include<bits/stdc++.h>
using namespace std;

int main(){
    bool a[6];
    int n;
    string s;
    memset(a, 0, sizeof(a));
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> s;
        if (s == "purple"){
            a[0] = 1;
        }
        if (s == "green"){
            a[1] = 1;
        }
        if (s == "blue"){
            a[2] = 1;
        }
        if (s == "orange"){
            a[3] = 1;
        }
        if (s == "red"){
            a[4] = 1;
        }
        if (s == "yellow"){
            a[5] = 1;
        }
    }
    cout << 6 - n << endl;
    for (int i = 0; i < 6; i++){
        if (!a[i]){
            switch (i){
                case 0: cout << "Power" << endl; break;
                case 1: cout << "Time" << endl; break;
                case 2: cout << "Space" << endl; break;
                case 3: cout << "Soul" << endl; break;
                case 4: cout << "Reality" << endl; break;
                case 5: cout << "Mind" << endl; break;
            }
        }
    }
}