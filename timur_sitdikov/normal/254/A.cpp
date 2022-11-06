#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx first
#define yy second

vector<int> vc[5005];

int main()
{   
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, i, j, a;
    cin >> n;
    for(i = 1; i <= 2 * n; i++){
        scanf("%d", &a);
        vc[a].pb(i);
    }
    for(i = 1; i <= 5000; i++){
        if (vc[i].size()&1){
            printf("-1");
            return 0;
        }
    }
    for(i = 1; i <= 5000; i++){
        for(j = 0; j < (int)vc[i].size(); j+=2){
            printf("%d %d\n", vc[i][j], vc[i][j+1]);
        }
    }
}