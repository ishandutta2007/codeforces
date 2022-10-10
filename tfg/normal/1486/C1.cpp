#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int qry(int l, int r) {
    std::cout << "? " << l+1 << ' ' << r+1 << std::endl;
    int x;
    std::cin >> x;
    return x-1;
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n;
    std::cin >> n;
    int pivot = qry(0, n-1);
    if(pivot && qry(0, pivot) == pivot) {
        int l = 0, r = pivot-1;
        while(l != r) {
            int mid = (l + r + 1) / 2;
            if(qry(mid, pivot) == pivot) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        pivot = l;
    } else {
        int l = pivot+1, r = n-1;
        while(l != r) {
            int mid = (l + r) / 2;
            if(qry(pivot, mid) == pivot) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        pivot = l;
    }
    std::cout << "! " << pivot+1 << std::endl;
}