#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

queue<int> one;
queue<int> two;

int main() {
    int n;
    cin >> n;
    int k1,k2;
    cin >> k1;
    for (int i=0;i<k1;i++) {
        int x;
        cin >> x;
        one.push(x);
    }
    cin >> k2;
    for (int i=0;i<k2;i++) {
        int x;
        cin >> x;
        two.push(x);
    }
    for (int r=1;r<=50000000;r++) {
        if (one.front()>two.front()) {
            one.push(two.front()); two.pop();
            one.push(one.front()); one.pop();
        } else {
            two.push(one.front()); one.pop();
            two.push(two.front()); two.pop();
        }
        if (one.size()==0) {
            cout << r << " " << 2;
            break;
        }
        if (two.size()==0) {
            cout << r << " " << 1;
            break;
        }
        if (r==50000000) cout << -1;
    }

    return 0;
}