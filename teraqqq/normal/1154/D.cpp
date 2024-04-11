#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n, a, b, max_b, x, i;

void use_a() { --a; if(x) b = min(max_b, b+1); } // battery
void use_b() { --b; } // accum

int main() {
    cin >> n >> a >> b; max_b = b;
    while(i++ < n) {
        cin >> x;
        if(!a && !b) break;
        else if(!a) use_b();
        else if(!b) use_a();
        else if(x && b != max_b) use_a();
        else use_b();
    }
    
    cout << i-1 << endl;
    return 0;
}