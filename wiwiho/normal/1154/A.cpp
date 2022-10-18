#include <iostream>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <functional>
#include <string>
#include <math.h>
#include <string.h>
#include <iomanip>

//#define TEST

bool cacl(int ab, int bc, int ac, int abc){
    if((ab + bc - abc) <= 0 || (ac + ab - abc) <= 0 || (bc + ac - abc) <= 0){
        return false;
    }

    std::cout << (ab + bc - abc) << " " << (ac + ab - abc) << " " << (bc + ac - abc) << "\n";
    return true;

}

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::vector<int> x(4);
    std::cin >> x[0] >> x[1] >> x[2] >> x[3];
    std::sort(x.begin(), x.end(), std::greater<int>());
    cacl(x[1], x[2], x[3], x[0]);

    return 0;
}