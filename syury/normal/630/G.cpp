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

#define y1 adgsfg

lint dp1[505][6], dp2[505][4];

int n;

int main(){
    cin >> n;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= 5; j++){
            if(i == 0){
                if(j == 0){
                    dp1[i][j] = 1; dp2[i][j] = 1;}
                else
                    {dp1[i][j] = 0; dp2[i][j] = 0;}
                continue;
            }
            dp1[i][j] = 0; dp2[i][j] = 0;
            for(int l = 0; l <= j; l++){
                dp1[i][j] += dp1[i - 1][j - l];
            }
            //cout << dp1[i][j] << endl;
            if(j > 3)
                continue;
            if(i == 0){
                if(j == 0)
                    dp2[i][j] = 1;
                else
                    dp2[i][j] = 0;
                continue;
            }
            dp2[i][j] = 0;
            for(int l = 0; l <= j; l++){
                dp2[i][j] += dp2[i - 1][j - l];
            }
            //cout << dp2[i][j] << endl;
        }
    }
    unsigned long long ans = dp1[n - 1][0] + dp1[n - 1][1] + dp1[n - 1][2] + dp1[n - 1][3] + dp1[n - 1][4] + dp1[n - 1][5];
    unsigned long long p = dp2[n - 1][0] + dp2[n - 1][1] + dp2[n - 1][2] + dp2[n - 1][3];
    cout << p * ans << endl;
    return 0;
}