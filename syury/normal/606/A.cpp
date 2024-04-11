#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<cmath>
#include<utility>
#include<map>
#include<cstdlib>
#include<ctime>
#include<random>
#include<string>
#include<iostream>
#include<cstring>

using namespace std;

typedef long long int lint;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<lint> vl;
typedef pair<int, int> pi;
typedef pair<lint, lint> pl;

int n, m, k;
vi a, b;

int main(){
    scanf("%d%d%d", &n, &m, &k);
    int e, d;
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    e = min(0, n - x) + min(0, m - y) + min(0, k - z);
    e = -1 * e;
    d = max(0, n - x) / 2 + max(0, m - y) / 2 + max(0, k - z) / 2;
    if(d >= e){
        printf("Yes");
    }
    else{printf("No");}
    return 0;
}