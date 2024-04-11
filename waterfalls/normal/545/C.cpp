#include <iostream>
#include <algorithm>

using namespace std;

int x[100013];
int h[100013];

int main() {
    int n;
    cin >> n;
    for (int i=0;i<n;i++) cin >> x[i] >> h[i];
    int ans = 0;
    int l = -2147483647;
    x[n] = 2147483647;
    for (int i=0;i<n;i++) {
        if (l<x[i]-h[i]) ans+=1, l = x[i];
        else if (x[i+1]>x[i]+h[i]) ans+=1, l = x[i]+h[i];
        else l = x[i];
    }
    cout << ans;

    return 0;
}