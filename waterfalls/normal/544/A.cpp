#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int k;
string q;
int has[26];
int diff[1000];

int main() {
    cin >> k >> q;
    int dis = 0;
    for (int i=0;i<q.size();i++) {
        if (!has[q[i]-'a']) dis+=1, diff[i] = 1;
        has[q[i]-'a'] = 1;
    }
    if (dis>=k) {
        cout << "YES" << endl;
        int cnt = 0;
        for (int i=0;i<q.size();i++) {
            if (diff[i] && cnt<k) {
                cout << " ";
                cnt+=1;
            }
            cout << q[i];
        }
    } else cout << "NO" << endl;

    return 0;
}