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

int n;
ldb a = 1.000000011;

ldb solve(int t){
    ldb res = n;
    while(t > 0){
        if(t % 2 == 1){
            res *= a; t--;
        }
        else{
            a *= a;
            t /= 2;
        }
    }
    return res;
}


int main(){
    int t;
    cin >> n >> t;
    cout.precision(21);
    cout << (double)solve(t);
	return 0;
}