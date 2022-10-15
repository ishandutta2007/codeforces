#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int n; cin >> n;

    int odds = 0;

    for (int i = 0; i < n; ++i)
    {
        int temp; cin >> temp;
        odds += temp % 2;
    }
    cout << min(odds, n - odds) << endl;
    return 0;
}