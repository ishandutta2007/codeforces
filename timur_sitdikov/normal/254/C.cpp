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

string s[2];
int num[2][200];

int main()
{   
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int l, i, j, ans, f;
    cin >> s[0] >> s[1];
    l = s[0].length();
    for(j = 0; j < 2; j++){
        for(i = 0; i < l; i++){
            num[j][s[j][i]]++;
        }
    }
    ans = 0;
    for(i = 'A'; i <= 'Z'; i++){
        if (num[0][i] > num[1][i])
            ans += num[0][i] - num[1][i];
    }
    for(i = 0; i < l; i++){
        if (num[0][s[0][i]] <= num[1][s[0][i]]){
            num[0][s[0][i]]--;
            num[1][s[0][i]]--;
            continue;
        }
        f = 0;
        for(j = 'A'; j < s[0][i]; j++){
            if (num[0][j] < num[1][j]){     
                num[0][j]++;
                num[0][s[0][i]]--;
                s[0][i] = j;
                f = 1;
                break;
            }
        }
        if (f){
            num[0][s[0][i]]--;
            num[1][s[0][i]]--;
            continue;
        }
        if (!num[1][s[0][i]]){
            for(j = s[0][i] + 1; j <= 'Z'; j++){
                if (num[0][j] < num[1][j]){             
                    num[0][j]++;
                    num[0][s[0][i]]--;
                    s[0][i] = j;
                    break;
                }
            }
        }
        num[0][s[0][i]]--;
        num[1][s[0][i]]--;
    }
    cout << ans << endl << s[0];
}