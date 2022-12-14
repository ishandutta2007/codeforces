#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

//#define myassert(x) if (!(x)) {std::cerr << "ERROR at " << __LINE__ << "\n"; return 999;}

typedef long long ll;
const int nDay = 2000005; // 2 * 10^6

auto inf = std::numeric_limits<ll>::max() / 2;
// so that inf+inf fits in ll range

struct flight {
    int day, city;
    ll cost;
    flight(int d, int c, ll co) : day(d),city(c),cost(co) {};
};

ll add(ll x, ll y) {
//    if (x == inf || y == inf) return inf;
    return x+y;
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);

    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<ll> minCostBefore (nDay), minCostAfter (nDay);

    std::vector<flight> arriveFlights, departFlights;
    for (int i = 0; i < m; ++i) {
        int day, from, to;
        ll cost;
        std::cin >> day >> from >> to >> cost;
        if (from == 0) departFlights.emplace_back(day, to, cost);
        else arriveFlights.emplace_back(day, from, cost);
    }

    std::sort(departFlights.begin(), departFlights.end(), [](flight x, flight y){
        return x.day < y.day;
    }); // largest pop first
    std::sort(arriveFlights.begin(), arriveFlights.end(), [](flight x, flight y){
        return x.day > y.day;
    }); // smallest pop first

    std::vector<ll> minCost (n+1, inf);
    ll sumNonInfMinCost = 0, nInfMinCost = n;
    for (int day = 0; day < nDay; ++day) {
        while ((!arriveFlights.empty()) && arriveFlights.back().day == day) {
            flight x = arriveFlights.back();
//            myassert(x.city != 0);
            if (minCost[x.city] > x.cost) {
                if (minCost[x.city] == inf) {
//                    myassert(nInfMinCost != 0);
                    --nInfMinCost;
                    sumNonInfMinCost += x.cost;
                } else {
                    sumNonInfMinCost -= minCost[x.city];
                    sumNonInfMinCost += x.cost;
                }
                minCost[x.city] = x.cost;
            }
            arriveFlights.pop_back();
        }
        minCostBefore[day] = nInfMinCost ? inf : sumNonInfMinCost;
//        std::cerr << "before " << day << " = " << minCostBefore[day] << '\n';
    }

    std::fill(minCost.begin(), minCost.end(), inf);
    sumNonInfMinCost = 0; nInfMinCost = n;
    for (int day = nDay-1; day != -1; --day) {
        while ((!departFlights.empty()) && departFlights.back().day == day) {
            flight x = departFlights.back();
//            myassert(x.city != 0);
            if (minCost[x.city] > x.cost) {
                if (minCost[x.city] == inf) {
//                    myassert(nInfMinCost != 0);
                    --nInfMinCost;
                    sumNonInfMinCost += x.cost;
                } else {
                    sumNonInfMinCost -= minCost[x.city];
                    sumNonInfMinCost += x.cost;
                }
                minCost[x.city] = x.cost;
            }
            departFlights.pop_back();
        }
        minCostAfter[day] = nInfMinCost ? inf : sumNonInfMinCost;
//        std::cerr << "after " << day << " = " << minCostAfter[day] << '\n';
    }

    ll mincost = inf;
     // day+k < nDay
    for (int day = 1; day < nDay - k; ++day) {
        // arrive before-or-equal day (day-1), discuss in [day..day+k) and depart after-or-equal day (day+k)
        mincost = std::min(mincost, add(minCostBefore[day-1], minCostAfter[day+k]));
    }
    if (mincost == inf) std::cout << "-1\n";
    else std::cout << mincost << '\n';
}

/*
*/