#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair


int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n;
    double h;
    scanf("%d%lf", &n, &h);
    for (int i = 1; i < n; i++)
        printf("%.12lf ", h * sqrt((double)i / n));
    printf("\n");

    return 0;
}