#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 200005;
 
int used [N];
int max_health [N];
int base_health [N];
int regen [N];
 
int n, m, wager, increase, damage;
tuple<int, int, int> health_points [N*2];
map<int, int> cnt;
set<int> updates [N];
 
int main(void) {
    scanf("%d%d%d%d%d", &n, &m, &wager, &increase, &damage);
 
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", max_health+i, base_health+i, regen+i);
        if (max_health[i] <= damage && increase > 0) {
            puts("-1");
            return 0;
        }
        health_points[i] = make_tuple(0, i, base_health[i]);
    }
    for (int i = 0; i < m; i++) {
        int time, enemy, health;
        scanf("%d%d%d", &time, &enemy, &health);
		enemy--;
        health_points[n+i] = make_tuple(time, enemy, health);
        updates[enemy].insert(time); 
    }
 
    sort(health_points, health_points+n+m);
 
    for (int i = 0; i < m+n; i++) {
        int time, enemy, health;
        tie(time, enemy, health) = health_points[i];

        if (health <= damage) {
            if (!used[enemy]) {
                cnt[time]++;
                used[enemy] = true;
            }
            if (used[enemy]) {
                if (regen[enemy] > 0) {
                    ll at = time + (damage - health) / regen[enemy] + 1;
                    if (max_health[enemy] > damage && updates[enemy].upper_bound(time) == updates[enemy].upper_bound(at)) {                        
                        cnt[at]--;
                        cnt[at-1] += 0;
                        used[enemy] = false;
                    }
                } else {
                    if (updates[enemy].upper_bound(time) == updates[enemy].end() && increase > 0) {
                        puts("-1");
                        return 0;
                    }
                }
            }
        } else {
            if (used[enemy]) {
                cnt[time]--;
                cnt[time-1] += 0;
                used[enemy] = false;  
            }
        }
    }

    ll ans = 0;
	int total_cnt = 0;
 
    for (auto p: cnt) {
        ll at, val;
        tie(at, val) = p;

        total_cnt += val;

        ans = max(ans, total_cnt * 1LL * wager + at * 1LL * total_cnt * increase);
    }
 
    printf("%" PRId64 "\n", ans);
    return 0;
}