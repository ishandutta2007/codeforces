#include<string>
#include<vector>
#include<unordered_map>
#include<utility>
#include<set>
#include<iostream>
#include<cstdio>
#include<list>
#include<cmath>

using namespace std;

typedef unsigned long long int lint;
typedef long double ldb;

ldb eps = 1e-9;

ldb a, b, c;



int main(){
    int _a, _b, _c;
    scanf("%d%d%d", &_a, &_b, &_c);
    if(_a < 0){
        _a = -_a;
        _b = -_b;
        _c = -_c;
    }
    a = (ldb)_a; b = (ldb)_b; c = (ldb)_c;
    ldb d = b * b - 4 * a * c;
    ldb x1 = (-b + sqrt(d))/(2 * a);
    ldb x2 = (-b - sqrt(d))/(2 * a);
    cout.precision(15);
    cout << (double)x1 << "\n" << (double)x2;
	return 0;
}