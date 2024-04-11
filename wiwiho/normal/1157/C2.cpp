#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <algorithm>
#include <utility>
#include <functional>

//#define TEST

void find(int* a, int start, int end, std::string& result, int last){
    while(start <= end){
        if(a[start] < a[end] && a[start] > last){
            result += "L";
            last = a[start];
            start++;
        }
        else if(a[end] < a[start] && a[end] > last){
            result += "R";
            last = a[end];
            end--;
        }
        else if(a[start] != a[end] && a[start] > last){
            result += "L";
            last = a[start];
            start++;
        }
        else if(a[start] != a[end] && a[end] > last){
            result += "R";
            last = a[end];
            end--;
        }
        else if(start == end && a[start] > last){
            result += "L";
            return;
        }
        else if(a[start] == a[end] && a[start] > last){
            std::string noL;
            find(a, start + 1, end, noL, a[start]);
            std::string noR;
            find(a, start, end - 1, noR, a[end]);
            if(noL.size() > noR.size()){
                result += "L";
                result += noL;
            }
            else{
                result += "R";
                result += noR;
            }
            return;
        }
        else{
            return;
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    std::string result;
    find(a, 0, n - 1, result, 0);

    std::cout << result.size() << "\n";
    std::cout << result << "\n";

    return 0;
}