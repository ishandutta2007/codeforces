#include <iostream>
using namespace std;

int find_max(int *arr, int n);
bool find_fit(int *arr, int n, int x);

int main()
{
    int t;
    cin >> t;
    
    int nums[100000];
    int n, x, max, steps_amount;
    while (t--) {
        cin >> n >> x;
        for (int i = 0; i < n; ++i) cin >> nums[i];
        max = find_max(nums, n);
        steps_amount = x / max;
        if (x == 0) steps_amount = 0;
        else if (steps_amount == 0) {
            if (find_fit(nums, n, x)) steps_amount = 1;
            else steps_amount = 2;
        }
        else if (steps_amount * max != x) ++steps_amount;
        cout << steps_amount << '\n';
    }
    return 0;
}

int find_max(int *arr, int n)
{
    int max = arr[0];
    for (int i = 1; i < n; ++i) if (max < arr[i]) max = arr[i];
    return max;
}
bool find_fit(int *arr, int n, int x)
{
    for (int i = 0; i < n; ++i) if (arr[i] == x) return true;
    return false;
}