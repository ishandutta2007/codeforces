#include<string>
#include<vector>
#include<unordered_map>
#include<utility>
#include<set>
#include<iostream>
#include<cstdio>
#include<list>
#include<cmath>
#include<algorithm>
#include<cstdlib>

using namespace std;

typedef long long int lint;
typedef long double ldb;

ldb ans = 0;

const ldb PI = 3.1415926535897932384;

int main(){
    int l1, l2, l3;
    cin >> l1 >> l2 >> l3;
    ldb t1 = tan(PI/3);
    ldb t2 = tan((360/8.0)/180.0 * PI);
    ldb t3 = tan(36/180.0 * PI);
    ldb r1 = l1/(2.0 * tan(PI/3));
    ldb r2 = l2/(2.0 * tan((360/8.0)/180.0 * PI));
    ldb r3 = l3/(2.0 * tan(36/180.0 * PI));
    ldb br1 = l1/(2.0 * sin(PI/3));
    ldb br2 = l2/(2.0 * sin((360/8.0)/180.0 * PI));
    ldb br3 = l3/(2.0 * sin(36/180.0 * PI));
    ans = (r1 * 3 * l1 / 2.0) * sqrt(l1 * l1 - br1 * br1) + (r2 * 4 * l2 / 2.0) * sqrt(l2 * l2 - br2 * br2) + (r3 * 5 * l3 / 2.0) * sqrt(l3 * l3 - br3 * br3);
    ans /= 3;
    cout.precision(24);
    cout << (double)ans;
    return 0;
}