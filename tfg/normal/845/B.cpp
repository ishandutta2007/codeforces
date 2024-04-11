#include <iostream>
#include <string>

std::string str;

int getCost(int x)
{
    int a = 0;
    int on = 5;
    int ans = 0;
    for(int i = 0; i < 3; i++)
    {
        if(x % 10 != str[on--] - '0')
            ans++;
        a += x % 10;
        x /= 10;
    }
    for(int i = 0; i < 3; i++)
    {
        if(x % 10 != str[on--] - '0')
            ans++;
        a -= x % 10;
        x /= 10;
    }
    if(a != 0)
        return 2109874;
    else
        return ans;
}

int main()
{
    int ans = 3;
    std::cin >> str;
    for(int i = 0; i <= 999999; i++)
        ans = std::min(ans, getCost(i));
    std::cout << ans << "\n";
}