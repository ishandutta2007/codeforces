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

int toInt(char c){
    return c - '0';
}

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::string a,b;
    std::cin >> a >> b;
    int h1 = toInt(a[0]) * 10 + toInt(a[1]);
    int m1 = toInt(a[3]) * 10 + toInt(a[4]);

    int h2 = toInt(b[0]) * 10 + toInt(b[1]);
    int m2 = toInt(b[3]) * 10 + toInt(b[4]);

    int t1 = h1 * 60 + m1;
    int t2 = h2 * 60 + m2;

    int t = (t1 + t2) / 2;
    int h = t / 60;
    int m = t % 60;
    std::cout << std::setfill('0') << std::setw(2) << h << ":"  << std::setfill('0') << std::setw(2) << m << "\n";

    return 0;
}