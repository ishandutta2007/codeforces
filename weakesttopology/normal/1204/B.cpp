#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
    int n, l, r;
    cin >> n >> l >> r;
    int minimum = int(pow(2.0, l) + 0.5) - 1 + n - l;
    int maximum = int(pow(2.0, r) + 0.5) - 1 + int(pow(2.0, r-1) + 0.5) * (n - r);
    cout << minimum << " " << maximum << endl;
    return 0;
}