#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    
    int x[50000], a[50000], b[50000];
    bool isabigger;
    while (t--) {
        isabigger = false;
        
        int n;
        cin >> n;
        
        char ch;
        for (int i = n - 1; i >= 0; --i) {
            cin >> ch;
            if (ch == '0') x[i] = 0;
            else if (ch == '1') x[i] = 1;
            else x[i] = 2;
        }
        
        for (int i = n - 1; i >= 0; --i) {
            if (x[i] == 0) a[i] = b[i] = 0;
            else if (x[i] == 1) {
                if (isabigger) {
                    b[i] = 1;
                    a[i] = 0;
                }
                else {
                    a[i] = 1;
                    b[i] = 0;
                    isabigger = true;
                }
            }
            else {
                if (isabigger) {
                    a[i] = 0;
                    b[i] = 2;
                }
                else {
                    a[i] = 1;
                    b[i] = 1;
                }
            }
        }
        
        for (int i = n - 1; i >= 0; --i) cout << a[i];
        cout << '\n';
        for (int i = n - 1; i >= 0; --i) cout << b[i];
        cout << '\n';
    }
    
    return 0;
}