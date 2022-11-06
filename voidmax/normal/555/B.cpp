#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#define For(i, a, b)  for(int i = a; i < b; ++i)
#define mp make_pair
#define x first
#define y second
#define point pair <int, int>
#define read(s1, s2); freopen(s1, "r", stdin); freopen(s2, "w", stdout);
#define int long long

using namespace std;

int n, m;
vector <pair <int, int> > road;
vector <pair <int, pair <int, int> > > ans;
set <pair <int, int> > arr;
int Reprint[200001];
int R[200001];

point a, b;

main() {
    cin >> n >> m;
    cin >> a.x >> a.y;
    For(i, 1, n) {
        cin >> b.x >> b.y;
        ans.push_back(mp(b.x - a.y, mp(-1, i - 1)));
        //cout << b.x - a.y << endl;
        ans.push_back(mp(b.y - a.x, mp(1, i - 1)));
        //cout << b.y - a.x << endl;
        R[i - 1] = b.y - a.x;
        swap(a, b);
    }
    sort(ans.begin(), ans.end());
    For(i, 0, m) {
        int a;
        cin >> a;
        road.push_back(mp(a, i + 1));
    }
    sort(road.begin(), road.end());
    int L = 0;
    road.push_back(mp(-1, -1));
    For(i, 0, ans.size()) {
        if (Reprint[ans[i].y.y] == 0) {
            while ((road[L].x == ans[i].x && ans[i].y.x == 1) || (road[L].x < ans[i].x)) {
                if (L == (int)road.size() - 1) {
                    For(j, 0, n - 1) {
                        if (Reprint[j] == 0) {
                            cout << "No" << endl;
                            return 0;
                        }
                    }
                    cout << "Yes" << endl;
                    For(j, 0, n - 1) {
                        cout << Reprint[j] << ' ';
                    }
                    cout << endl;
                    return 0;
                }
                if (!arr.empty()) {
                    point Next = *arr.begin();
                    if (Next.x >= road[L].x) {
                        //cout << Next.y << endl;
                        Reprint[Next.y] = road[L].y;
                        arr.erase(Next);
                    }
                    else {
                        cout << "No" << endl;
                        return 0;
                    }
                }
                ++L;
            }
        }
        if (Reprint[ans[i].y.y] == 0) {
            if (ans[i].y.x == 1) {
                cout << "No" << endl;
                return 0;
            }
            else {
                arr.insert(mp(R[ans[i].y.y], ans[i].y.y));
            }
        }
    }
    cout << "Yes" << endl;
    For(i, 0, n - 1) {
        cout << Reprint[i] << ' ';
    }
    cout << endl;
}