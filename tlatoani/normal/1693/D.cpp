#include <iostream>
#include <set>
#include <vector>

using namespace std;

int p[200001];
int q[200001];
int lessLeft[200001];
int lessRight[200001];
vector<int> locations[200001];
int rightEndpoint[200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    rightEndpoint[0] = 0;
    locations[0].clear();
    for (int j = 1; j <= n; j++) {
        cin >> p[j];
        q[p[j]] = j;
        locations[j].clear();
        rightEndpoint[j] = j;
    }

    vector<int> stack;
    stack.push_back(0);
    for (int j = 1; j <= n; j++) {
        while (stack[stack.size() - 1] > p[j]) {
            stack.pop_back();
        }
        lessLeft[j] = stack[stack.size() - 1];
        stack.push_back(p[j]);
    }
    stack.clear();
    stack.push_back(0);
    for (int j = n; j > 0; j--) {
        while (stack[stack.size() - 1] > p[j]) {
            stack.pop_back();
        }
        lessRight[j] = stack[stack.size() - 1];
        stack.push_back(p[j]);
    }

    for (int j = 1; j < n; j++) {
        if (p[j] > p[j + 1]) {
            locations[max(p[j + 1], lessLeft[j])].push_back(j);
        } else {
            locations[max(p[j], lessRight[j + 1])].push_back(j);
        }
        locations[max(p[j], p[j + 1])].push_back(j);
        locations[min(p[j], p[j + 1]) - 1].push_back(j);
    }

    set<int> above;
    set<int> below;
    set<int> upLeft;
    set<int> downRight;
    set<int> downLeft;
    set<int> upRight;
    for (int j = 1; j <= n; j++) {
        above.insert(j);
    }
    for (int j = 1; j < n; j++) {
        if (p[j] < p[j + 1]) {
            upLeft.insert(j);
        } else {
            downRight.insert(j + 1);
        }
    }
    bool print = false;
    for (int x = 0; x <= n; x++) {
        //print = x == 3;
        if (x > 0) {
            //cout << endl;
            int j = q[x];
            if (print) {
                cout << "j = " << j << endl;
            }

            above.erase(j);
            upLeft.erase(j);
            downRight.erase(j);
            auto it = above.upper_bound(j);
            int prev, next;
            if (it == above.end()) {
                next = 0;
            } else {
                next = *it;
            }
            if (it == above.begin()) {
                prev = 0;
            } else {
                it--;
                prev = *it;
            }

            if (print) {
                cout << "prev = " << prev << ", next = " << next << endl;
            }

            if (prev != 0) {
                if (next != 0 && p[prev] < p[next]) {
                    upLeft.insert(prev);
                    //cout << "yeah" << endl;
                } else {
                    upLeft.erase(prev);
                }
            }
            if (next != 0) {
                if (prev != 0 && p[prev] > p[next]) {
                    downRight.insert(next);
                } else {
                    downRight.erase(next);
                }
            }

            it = below.upper_bound(j);
            prev = 0;
            next = 0;
            if (it == below.end()) {
                next = 0;
            } else {
                next = *it;
            }
            if (it == below.begin()) {
                prev = 0;
            } else {
                it--;
                prev = *it;
            }
            if (prev != 0) {
                if (p[prev] < x) {
                    upRight.insert(j);
                    downLeft.erase(prev);
                } else {
                    downLeft.insert(prev);
                }
            }
            if (next != 0) {
                if (x > p[next]) {
                    downLeft.insert(j);
                    upRight.erase(next);
                } else {
                    upRight.insert(next);
                }
            }
            below.insert(j);
        }
        for (int j : locations[x]) {
            int r = n;
            int l = 1;
            auto it = above.upper_bound(j);
            if (it != above.end()) {
                if (print) {
                    cout << "bang2 = " << (*it) << endl;
                }
                auto it2 = downRight.upper_bound(*it);
                if (it2 != downRight.end()) {
                    r = min(r, (*it2) - 1);
                    if (print) {
                        cout << "thang2 = " << (*it2) << endl;
                    }
                }
            }
            it = above.upper_bound(j);
            if (it != above.begin()) {
                it--;
                if (print) {
                    //cout << "bing = " << (*it) << endl;
                }
                auto it2 = upLeft.lower_bound(*it);
                if (it2 != upLeft.begin()) {
                    it2--;
                    if (print) {
                        //cout << "thing = " << (*it2) << endl;
                    }
                    l = max(l, (*it2) + 1);
                }
            }
            it = below.upper_bound(j);
            if (it != below.end()) {
                auto it2 = upRight.upper_bound(*it);
                if (print) {
                    cout << "bang = " << (*it) << endl;
                }
                if (it2 != upRight.end()) {
                    r = min(r, (*it2) - 1);
                    if (print) {
                        cout << "thang = " << (*it2) << endl;
                    }
                }
            }
            it = below.upper_bound(j);
            if (it != below.begin()) {
                it--;
                if (print) {
                    //cout << "bing2 = " << (*it) << endl;
                }
                auto it2 = downLeft.lower_bound(*it);
                if (it2 != downLeft.begin()) {
                    it2--;
                    if (print) {
                        //cout << "thing2 = " << (*it2) << endl;
                    }
                    l = max(l, (*it2) + 1);
                }
            }
            rightEndpoint[l] = max(rightEndpoint[l], r);
            if (print) {
                cout << "x = " << x << ", j = " << j << " :: [" << l << ", " << r << "]" << endl;
            }
        }
    }

    long long answer = 0;
    for (int l = 1; l <= n; l++) {
        rightEndpoint[l] = max(rightEndpoint[l - 1], rightEndpoint[l]);
        answer += rightEndpoint[l] - l + 1;
        //cout << "right endpoint " << l << " = " << rightEndpoint[l] << endl;
    }
    cout << answer << endl;
}