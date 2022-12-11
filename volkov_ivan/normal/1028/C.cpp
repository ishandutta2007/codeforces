#include <iostream>
#include <map>

using namespace std;

struct rect{
    int x1, y1, x2, y2;
    rect() {}
    void init() {
        cin >> x1 >> y1 >> x2 >> y2;
    }
};

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    rect arr[n];
    map <int, int> x2, y2;
    map <int, int, greater<int>> x1, y1;
    for (int i = 0; i < n; i++) {
        arr[i].init();
        x1[arr[i].x1]++;
        x2[arr[i].x2]++;
        y1[arr[i].y1]++;
        y2[arr[i].y2]++;
    }
    for (int i = 0; i < n; i++) {
        if (--x1[arr[i].x1] == 0) x1.erase(arr[i].x1);
        if (--x2[arr[i].x2] == 0) x2.erase(arr[i].x2);
        if (--y1[arr[i].y1] == 0) y1.erase(arr[i].y1);
        if (--y2[arr[i].y2] == 0) y2.erase(arr[i].y2);
        if (((*(x1.begin())).first <= (*(x2.begin())).first) && (*(y1.begin())).first <= (*(y2.begin())).first) {
            cout << (*(x1.begin())).first << ' ' << (*(y1.begin())).first << endl;
            return 0;
        }
        x1[arr[i].x1]++;
        x2[arr[i].x2]++;
        y1[arr[i].y1]++;
        y2[arr[i].y2]++;
    }
    return -1;
}