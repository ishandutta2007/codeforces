#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <queue>

using namespace std;

int main(){
    int n;
    cin >> n;
    if (n % 2 == 0 && n >= 4)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}