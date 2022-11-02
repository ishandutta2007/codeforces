#include <iostream>
#include <algorithm>

using namespace std;

int a[100013];

int main() {
    int n;
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    int ans = 0;
    int tot = 0;
    for (int i=0;i<n;i++) if (a[i]>=tot) ans+=1, tot+=a[i];
    cout << ans;

    return 0;
}