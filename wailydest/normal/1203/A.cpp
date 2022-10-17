#include <iostream>
using namespace std;

bool inc(int *arr, int n);
bool dec(int *arr, int n);

int main()
{
    int q, n, students[200];
    cin >> q;
    while (q--) {
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> students[i];
        
        if (inc(students, n) || dec(students, n)) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}

bool inc(int *arr, int n)
{
    int j = (arr[0] == n ? 1 : arr[0] + 1);
    for (int i = 1; i < n; ++i, ++j) {
        if (arr[i] != j) return false;
        if (arr[i] == n) j = 0;
    }
    return true;
}

bool dec(int *arr, int n)
{
    int j = (arr[0] == 1 ? n : arr[0] - 1);
    for (int i = 1; i < n; ++i, --j) {
        if (arr[i] != j) return false;
        if (arr[i] == 1) j = n + 1;
    }
    return true;
}