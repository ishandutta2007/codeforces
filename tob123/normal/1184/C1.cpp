#include <bits/stdc++.h>
using namespace std;

#define Debug(x) x
typedef int regular_int;
// #define int ll
typedef long long ll;

int x[500], y[500];

        int minx = 100, miny = 100, maxx =  - 1, maxy =  - 1;

bool magic(int i){
    if (x[i] < minx || y[i] < miny || x[i] > maxx || y[i] > maxy){
        return false;
    }
    if (x[i] > minx && y[i] > miny && x[i] < maxx && y[i] < maxy){
        return false;
    }
    return true;
}

regular_int main() {
	ios_base::sync_with_stdio(false);
	cout << setprecision(12) << fixed;

	int n;
	cin >> n;
	int N = 4 * n + 1;
	for (int i = 0; i < N; ++i) {
        cin >> x[i] >> y[i];
	}

	for (int i = 0; i < N; ++i) {
        minx = 100, miny = 100, maxx =  - 1, maxy =  - 1;
        for (int j = 0; j < N; ++j) {
            if (i == j)continue;
            minx = min(minx, x[j]);
            miny = min(miny, y[j]);
            maxx = max(maxx, x[j]);
            maxy = max(maxy, y[j]);
        }
        if (maxx - minx != maxy - miny)
            continue;
        bool valid = !magic(i);
        for (int j = 0; j < N; ++j) {
            if (i == j)
                continue;
            valid = valid && magic(j);
        }
        if (valid){
            cout << x[i] << " " << y[i] << endl;
            return 0;
        }
	}
	return 0;
}