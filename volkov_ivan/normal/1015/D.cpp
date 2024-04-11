#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    long long n, k, s;
    cin >> n >> k >> s;
    if (k > s) {
        cout << "NO" << endl;
        return 0;
    }
    long long now = 1, did = 0;
    vector <int> ans;
    while (k > 0) {
        if ((k - 1) <= (s - (n - 1))) {
            if (now == 1) {
                ans.push_back(n);
                now = n;
            } else {
                ans.push_back(1);
                now = 1;
            }
            s -= n - 1;
            k--;
        } else {
            // k - 1 = s - x
            int x = s - k + 1;
            s -= x;
            k--;
            if (now == 1) {
                now = x + 1;
                ans.push_back(now);
            } else {
                now = n - x;
                ans.push_back(now);
            }
            break;
        }
    }
    while (k > 0) {
        if (now == 1) {
            now++;
            ans.push_back(now);
        } else {
            now--;
            ans.push_back(now);
        }
        k--;
        s--;
    }
    if (s != 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int elem : ans) cout << elem << ' ';
    }
    return 0;
}