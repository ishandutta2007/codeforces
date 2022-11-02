#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

int main() {
    cin >> n;
    int len = 0;
    int tmp = n;
    int cur = 0;
    while (tmp) {
        if (tmp%10==7) cur+=1<<len;
        len+=1;
        tmp/=10;
    }
    cout << (1<<len)-1+cur;

    return 0;
}