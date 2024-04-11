#include <iostream>

int n, a[1001], b, i;

int main()
{
    std::cin >> n;
    for(; i < n; ++i)
    {
        std::cin >> a[i] >> b;

        if(a[i] != b)
        {
            std::cout << "rated";
            return 0;
        }
    }

    for(; i != 0; --i)
    {
        if(a[i] > a[i - 1])
        {
            std::cout << "unrated";
            return 0;
        }
    }

    std::cout << "maybe";
}