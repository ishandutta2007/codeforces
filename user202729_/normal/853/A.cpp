#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::vector<int> c (n), departuretime (n);
    for (int& x : c) std::cin >> x;
    std::priority_queue<int> empty_pos;
    for (int i = n+1; i <= n+k; ++i) empty_pos.push(i);
    std::priority_queue<std::pair<int,int>> flights;
    for (int i = 0; i < n; ++i) {
        flights.emplace(-c[i], i);
        departuretime[i] = i+1;
    }
    ll cost = 0, totaldelayleft = n * (ll)k;
    while (totaldelayleft) {
//        if (empty_pos.empty()) {
//            std::cerr << "No empty pos?\n";
//            break;
//        }
        int p = empty_pos.top(); // largest
//        std::cerr << "Get position " << p << '\n';
//        if (flights.empty()) {
//            std::cerr << "Empty flight list\n";
//            break;
//        }
        int flightid = flights.top().second;
        flights.pop();
        if (departuretime[flightid] <= p) {
//            if (departuretime[flightid] == p) {
//                std::cerr << "Unreachable\n";
//                return 999;
//            }
            totaldelayleft -= p - departuretime[flightid];
            empty_pos.pop(); // p
            empty_pos.push(departuretime[flightid]);
            cost += (p - departuretime[flightid]) * (ll)c[flightid];
            departuretime[flightid] = p;
        }
    }
    std::cout << cost << '\n';
    for (int x : departuretime) std::cout << x << ' ';
}