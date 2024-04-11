#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    bool almostLucky = false;
    for(int i = 1; i <= n; ++i) {
        int x = i;
        bool isLucky = true;
        while (x > 0) {
            if (x%10 != 4 && x%10 != 7)
                isLucky = false;
            x /= 10;
        }

        if (isLucky && n%i == 0)
            almostLucky = true;
    }

    if (almostLucky)
        cout << "YES";
    else
        cout << "NO";
}