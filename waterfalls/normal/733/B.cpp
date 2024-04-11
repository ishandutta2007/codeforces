#include <iostream>
#include <algorithm>
using namespace std;

int n;
int l[100013], r[100013];

int main() {
    cin >> n;
    for (int i=0;i<n;i++) cin >> l[i] >> r[i];
    int tl = accumulate(l,l+n,0);
    int tr = accumulate(r,r+n,0);
    int best = abs(tl-tr);
    int which = 0;
    for (int i=0;i<n;i++) {
        int cur = abs((tl-l[i]+r[i])-(tr-r[i]+l[i]));
        if (cur>best) {
            best = cur;
            which = i+1;
        }
    }
    cout << which << endl;
    
    return 0;
}