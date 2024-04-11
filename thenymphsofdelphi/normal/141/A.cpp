#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int main(){
    string a, b, ab, c;
    int la, lb, lc;
    cin >> a;
    cin >> b;
    cin >> c;
    la = a.length();
    lb = b.length();
    lc = c.length();
    if (la + lb != lc){
        cout << "NO";
        return 0;
    }
    ab = a + b;
    sort(ab.begin(), ab.end());
    sort(c.begin(), c.end());
    if (ab == c){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}