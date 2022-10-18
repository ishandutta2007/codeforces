#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();
    int n;
    string s;
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> s;
        if (s == "Tetrahedron"){
            ans += 4;
        }
        else if (s == "Cube"){
            ans += 6;
        }
        else if (s == "Octahedron"){
            ans += 8;
        }
        else if (s == "Dodecahedron"){
            ans += 12;
        }
        else if (s == "Icosahedron"){
            ans += 20;
        }
        else{
            cout << "What the fuck -_-" << endl;
            return 0;
        }
    }
    cout << ans;
}