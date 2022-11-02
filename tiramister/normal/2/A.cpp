#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    map<string, int> point;
    string name[N];
    int score[N];
    for (int i = 0; i < N; ++i) {
        cin >> name[i] >> score[i];
        if (!point.count(name[i])) point[name[i]] = 0;
        point[name[i]] += score[i];
    }

    int ma = -1;
    set<string> winners;
    for (auto p : point) {
        if (p.second < ma) continue;
        if (p.second > ma) {
            winners.clear();
            ma = p.second;
        }
        winners.insert(p.first);
    }

    point.clear();
    for (int i = 0; i < N; ++i) {
        if (!point.count(name[i])) point[name[i]] = 0;
        point[name[i]] += score[i];
        if (point[name[i]] >= ma && winners.count(name[i])) {
            cout << name[i] << endl;
            break;
        }
    }
    return 0;
}