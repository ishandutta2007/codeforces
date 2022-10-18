#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int d = 0, dis;
    string s;
    for (int t = 0; t < n; t++){
        cin >> dis >> s;
        if (d == 0 && s != "South"){
            cout << "NO";
            return 0;
        }
        if (d == 20000 && s != "North"){
            cout << "NO";
            return 0;
        }
        if ((dis > d && s == "North") || (dis > (20000 - d) && s == "South")){
            cout << "NO";
            return 0;
        }
        if (s == "North"){
            d -= dis;
        }
        if (s == "South"){
            d += dis;
        }
    }
    if (d != 0){
        cout << "NO";
        return 0;
    }
    cout << "YES";
}