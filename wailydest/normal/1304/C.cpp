#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() 
{
    int q, n, m, l, h, t;
	bool ispos;
    vector<pair<int, int> > temperatures;
    vector<int> visit_time;
	vector<pair<int, int> > diapasones;
    cin >> q;
    while (q--) {
		ispos = true;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> t;
            visit_time.push_back(t);
            cin >> l >> h;
            temperatures.push_back(make_pair(l, h));
        }
        
		diapasones.resize(n);
		diapasones[0] = make_pair(m - visit_time[0], m + visit_time[0]);
		int i = 0;
		if (diapasones[i].first < temperatures[i].first) diapasones[i].first = temperatures[i].first;
		if (diapasones[i].second > temperatures[i].second) diapasones[i].second = temperatures[i].second;
		if (diapasones[i].first > diapasones[i].second) {
			ispos = false;
		}
		for (int i = 1; i < n; ++i) {
			diapasones[i] = make_pair(diapasones[i - 1].first - visit_time[i] + visit_time[i - 1], diapasones[i - 1].second + visit_time[i] - visit_time[i - 1]);
			if (diapasones[i].first < temperatures[i].first) diapasones[i].first = temperatures[i].first;
			if (diapasones[i].second > temperatures[i].second) diapasones[i].second = temperatures[i].second;
			if (diapasones[i].first > diapasones[i].second) {
				ispos = false;
				break;
			}
		}
		if (ispos) cout << "YES\n";
		else cout << "NO\n";
		
		visit_time.clear();
		diapasones.clear();
		temperatures.clear();
    }
    return 0;
}