#include <iostream>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <functional>
#include <string>
#include <math.h>
#include <string.h>
#include <iomanip>

//#define TEST

void remove(int* left, int* right, int n, int r){
    if(left[r] != -1){
        right[left[r]] = right[r];
    }
    if(right[r] != -1){
        left[right[r]] = left[r];
    }
}

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n,k;
    std::cin >> n >> k;

    std::vector<std::pair<int, int>> a(n);
    int left[n];
    int right[n];
    int team[n];
    for(int i = 0; i < n; i++){
        team[i] = 0;
        std::cin >> a[i].first;
        a[i].second = i;
        left[i] = i - 1;
        right[i] = i + 1 < n ? i + 1 : -1;
    }

    std::sort(a.begin(), a.end(), std::greater<std::pair<int, int>>());

    bool first = true;

    for(int last = 0; last < n; last++){

        int t = first ? 1 : 2;

        while(last < n && team[a[last].second] != 0){
            last++;
        }
        if(last == n){
            break;
        }

        int highest = a[last].second;

        team[highest] = t;

        for(int i = 0; i < k; i++){
            if(left[highest] == -1){
                break;
            }
            team[left[highest]] = t;
            remove(left, right, n, left[highest]);
        }

        for(int i = 0; i < k; i++){
            if(right[highest] == -1){
                break;
            }
            team[right[highest]] = t;
            remove(left, right, n, right[highest]);
        }

        remove(left, right, n, highest);

        first = !first;
    }

    for(int i = 0; i < n; i++){
        std::cout << team[i];
    }
    std::cout << "\n";

    return 0;
}