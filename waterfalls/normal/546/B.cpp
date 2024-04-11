#include <iostream>
#include <algorithm>

using namespace std;

int a[10000];

int main() {
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        int x;
        cin >> x;
        a[x]+=1;
    }
    int ans = 0;
    for (int i=0;i<9999;i++) {
        if (a[i]<=1) continue;
        int extra = a[i]-1;
        for (int j=i+1;j<=i+extra;j++) ans+=j-i, a[j]+=1;
    }
    cout << ans << endl;

    return 0;
}