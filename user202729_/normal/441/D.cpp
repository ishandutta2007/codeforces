// http://codeforces.com/contest/441/problem/D

#include <iostream>
#include <queue>

std::queue<int> op;

#define MAX 3500

int p [MAX], p1 [MAX], cycleid[MAX], cyclesize[2*MAX];
int m, n, cnt;

int main() {
    std::cin >> n;
    int i, j, removecycle, addcycle, lastusedcycle = n+1;
    for (i = 0; i < n; i++) {
        std::cin >> p[i];
        --p[i];
    }
    std::cin >> m;

    std::copy(p, p + n, p1);
    cnt = 0;
    i = 0;
    while (i < n) {
        if (i == p1[i]) ++i;
        else {
            std::swap(p1[i], p1[p1[i]]);
            ++cnt;
        }
    }

    std::fill(cyclesize, cyclesize + MAX, 0);
    for (i = 0; i < n; i++) {
        cycleid[i] = i;
        cyclesize[i]++;
    }
    for (i = 0; i < n; i++) {
        // (join) i and p[i] is in the same cycle
        if (cycleid[i] != cycleid[p[i]]) {
            removecycle = cycleid[i]; addcycle = cycleid[p[i]];
            cyclesize[addcycle] += cyclesize[removecycle];
            cyclesize[removecycle] = 0;
            for (j = 0; j < n; j++)
                if (cycleid[j] == removecycle) cycleid[j] = addcycle;
        }
    }

    //std::cout << "cnt=" << cnt << "\n";

    if (cnt > m) { // cnt: number of swap = n - number of cycle
        // loop increase cycles by swap 2 elements in same cycle
        do {
            for (i = 0; i < n; i++) {
                if (cyclesize[cycleid[i]] > 1)
                for (j = i+1; j < n; j++) {
                    if (cycleid[i] == cycleid[j]) {
                        op.push(i); op.push(j);
                        // split p[j] from p[i]
                        std::swap(p[i], p[j]);

                        addcycle = ++lastusedcycle;
                        int k = j;
                        do {
                            cycleid[k] = addcycle;
                            cyclesize[addcycle]++;
                            k = p[k];
                        } while (k != j);

                        cyclesize[cycleid[i]] -= cyclesize[addcycle];

                        goto found1;
                    }
                }
            }
            return 1234;
            found1:
            --cnt; // swap -- -> n.cycle ++
        } while (cnt > m);
    } else if (cnt < m) {
        // loop decrease cycles by swap 2 elements in different cycle
        do {
            for (i = 0; i < n; i++) {
                for (j = i+1; j < n; j++) {
                    if (cycleid[i] != cycleid[j]) {
                        op.push(i); op.push(j);
                        //std::cout << i << " " << j << "\n";
                        // merge
                        std::swap(p[i], p[j]);
                        removecycle = cycleid[i]; addcycle = cycleid[j];
                        cyclesize[addcycle] += cyclesize[removecycle];
                        cyclesize[removecycle] = 0;

                        for (int k = 0; k < n; k++)
                            if (cycleid[k] == removecycle) cycleid[k] = addcycle;
                        goto found2;
                    }
                }
            }
            return 5678;
            found2:
            ++cnt;
        } while (cnt < m);
    } else {
        std::cout << "0\n\n";
        return 0;
    }
    std::cout << op.size()/2 << "\n";
    while (!op.empty()) {
        std::cout << 1+op.front() << " ";
        op.pop();
    }
}