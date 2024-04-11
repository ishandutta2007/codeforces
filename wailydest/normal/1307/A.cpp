#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    string l;
    int n, d, first, single;
    bool hasleft;
    while (t--) {
        hasleft = false;
        cin >> n >> d;
        cin >> first;
        for (int i = 1; i < n; ++i) {
            cin >> single;
            if (d < single * i) {
                first += d / i;
                hasleft = true;
                break;
            }
            else {
                d -= single * i;
                first += single;
            }
        }
        if (hasleft) getline(cin, l);
        cout << first << '\n';
    }
    return 0;
}