#include <bits/stdc++.h>

using namespace std;


int ask(int x, int y) {
    cout << x << " " << y << endl;
    string color;
    cin >> color;
    return color == "black";
}
int main() {
    int n;
    cin >> n;
    int pivot = ask(0, 0);
    if (n == 1) {
        cout << "1 0 1 1" << endl; 
        return 0;
    }
    int pivot2 = ask(1 << 29, 0);

    int L = 0, R = 1 << 29;
    for(int i = 3; i <= n; i++){
        int mid = (L + R) / 2;
        int cur = (pivot != pivot2) ? ask(mid, 0) : ask(0, mid);
        if (cur != pivot) R = mid;
        else L = mid;
    }
    if (pivot != pivot2) 
        cout << L + 1 << " 0 " << L + 1 << " 1" << endl;
    else cout << "0 " << L + 1 << " 1 " << L + 1 << endl;
}