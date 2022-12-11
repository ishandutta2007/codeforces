#include <iostream>

using namespace std;

const long long MAX_NUM = 100000;

int main() {
    long long g, d, f;
    cin >> g >> d >> f;
    long long gs[g], ds[d], fs[f];
    pair <long long, char> all[g + d + f];
    long long pref_g[MAX_NUM + 1], pref_d[MAX_NUM + 1], pref_f[MAX_NUM + 1];
    for (int i = 0; i <= MAX_NUM; i++) {
        pref_g[i] = pref_d[i] = pref_f[i] = 0;
    }
    for (int i = 0; i < g; i++) {
        cin >> gs[i];
        pref_g[gs[i]]++;
        all[i] = make_pair(gs[i], 'g');
    }
    for (int i = 0; i < d; i++) {
        cin >> ds[i];
        pref_d[ds[i]]++;
        all[g + i] = make_pair(ds[i], 'd');
    }
    for (int i = 0; i < f; i++) {
        cin >> fs[i];
        pref_f[fs[i]]++;
        all[g + d + i] = make_pair(fs[i], 'f');
    }
    for (int i = 1; i <= MAX_NUM; i++) {
        pref_g[i] += pref_g[i - 1];
        pref_d[i] += pref_d[i - 1];
        pref_f[i] += pref_f[i - 1];
    }
    long long ans = 0;
    long long l, r, num_g, num_d, num_f;
    for (int i = 0; i < g + d + f; i++) {
        l = all[i].first;
        r = min(l * 2, MAX_NUM);
        if (all[i].second == 'g') num_g = 1;
        else num_g = pref_g[r] - pref_g[l];
        if (all[i].second == 'd') num_d = pref_d[r] - pref_d[l];
        else num_d = ((pref_d[r] - pref_d[l]) * (pref_d[r] - pref_d[l] - 1)) / 2;
        if (all[i].second == 'f') num_f = ((pref_f[r] - pref_f[l]) * (pref_f[r] - pref_f[l] - 1)) / 2;
        else num_f = ((pref_f[r] - pref_f[l]) * (pref_f[r] - pref_f[l] - 1) * (pref_f[r] - pref_f[l] - 2)) / 6;
        ans += num_g * num_d * num_f;
    }
    cout << ans << endl;
    return 0;
}