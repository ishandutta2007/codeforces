// problem d

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>

struct dancer_t {
    double x, y, r;
    int parity = 0;
};

int ndancer;
std::vector<dancer_t> dancers;
double resultdivpi=0;

double sqr(int a) {return double(a)*a;}

int main() {
    std::cout << std::setprecision(17);

    std::cin >> ndancer;
    dancers.resize(ndancer);
    for (auto &dancer : dancers) {
        std::cin >> dancer.x >> dancer.y >> dancer.r;
    }
    std::sort(dancers.begin(), dancers.end(), [](dancer_t x, dancer_t y)->bool {
              return x.r > y.r;
              }); // decreasing radius
    //
    for (int i = 0; i < ndancer; ++i) {
        dancer_t &d = dancers[i];
        int bound;
        for (bound = i-1; bound != -1; --bound) {
            if (sqr(dancers[bound].x-d.x) + sqr(dancers[bound].y-d.y) <= sqr(dancers[bound].r - d.r)) {
                break; // inner for
            }
        }
        if (bound == -1) { // there are no bound
            resultdivpi += sqr(d.r);
            d.parity = 1;
        } else {
            if (dancers[bound].parity == 1) {
                resultdivpi += sqr(d.r);
            } else {
                resultdivpi -= sqr(d.r);
            }
            d.parity = 1-dancers[bound].parity; // alternatively !
        }
    }
    std::cout << resultdivpi * 3.141592653589793238462643383278502884;
}