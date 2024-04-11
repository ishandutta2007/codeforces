#include <iostream>
#include <algorithm>

int a[200];

int main()
{
    int n;
    std::cin >> n;
    for(int i = 0; i < n + n; i++)
        std::cin >> a[i];
    std::sort(a, a + 2 * n);
    if(a[n - 1] < a[n])
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
}