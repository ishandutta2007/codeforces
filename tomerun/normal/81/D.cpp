#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <numeric>
#include <utility>
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

int n,m;
vector<int> a;
vector<int> result;

bool solveEven(){
    int pos = 0;
    int curm = 0;
    while(true) {
        int rm = a[curm] % (1 << 8);
        while(result[(pos+n-1)%n] == rm || result[(pos+1)%n] == rm){
            ++curm;
            if(curm == m) {
                return false;
            }
            rm = a[curm] % (1 << 8);
        }
        result[pos] = rm;
        a[curm] -= 1<<8;
        if(a[curm] < (1<<8)) {
            curm++;
        }
        pos += 2;
        if(pos == n){
            pos = 1;
        }else if(pos == n+1) {
            return true;
        }
        if(curm == m) {
            return false;
        }
    }
}

bool solveOdd(){
    int pos = 0;
    int curm = 0;
    while(true) {
        int rm = a[curm] % (1 << 8);
        while(result[(pos+n-1)%n] == rm || result[(pos+1)%n] == rm){
            ++curm;
            if(curm == m) {
                return false;
            }
            rm = a[curm] % (1 << 8);
        }
        result[pos] = rm;
        a[curm] -= 1<<8;
        if(a[curm] < (1<<8)) {
            curm++;
        }
        pos += 2;
        if(pos == n+1){
            pos = 1;
        }else if(pos == n) {
            return true;
        }
        if(curm == m) {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int ai;
        cin >> ai;
        a.push_back((ai << 8) + i);
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    result.assign(n, -1);
    bool success;
    if(n % 2 == 0) {
        success = solveEven();
    }else{
        success = solveOdd();
    }
    if(success) {
        for(int i = 0; i < n-1; ++i) {
            cout << (result[i]+1) << " ";
        }
        cout << (result.back()+1) << endl;
    }else {
        cout << -1 << endl;
    }
    return 0;
}