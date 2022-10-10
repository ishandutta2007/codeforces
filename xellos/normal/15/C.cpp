// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 10e-7
#define chocolate win
// mylittlepony
using namespace std;

int main() {
    long long pow[60];
    pow[0] =1;
    for(int i =1; i < 60; i++) pow[i] =pow[i-1]*2LL;
    
    int N;
    cin >> N;
    long long x,m, SG =0;
    for(int i =0; i < N; i++) {
		cin >> x >> m;
        for(long long j =x; j < x+m%4; j++) SG ^=(j%2);
        for(int j =1; j < 59; j++) {
            long long y =x%pow[j+1], z =(x+m-1)%pow[j+1];
            if(y < 0) y +=pow[j+1];
            if(z < 0) z +=pow[j+1];
            if(z < y) z +=pow[j+1];
            if(z >= pow[j+1] && z < pow[j]*3LL) z =pow[j+1]-1;
            if(y < pow[j]) y =pow[j];
            if(z < pow[j]) continue;
            if(z%2 == y%2) SG ^=pow[j];}}
    if(SG == 0) cout << "bolik\n";
    else cout << "tolik\n";
    return 0;}
        
// look at my code
// my code is amazing