#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n;
bool not_prime[10000001];
vector<int> prime;
pair<int, int> ans[500001];
void sieve()
{
    not_prime[0] = not_prime[1] = 1;
    for (int i = 2; i * i <= 10000000; i++)
    {
        if (!not_prime[i])
        {
            prime.push_back(i);
            for (int j = i * i; j <= 10000000; j += i)
            {
                not_prime[j] = 1;
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    sieve();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        if (!not_prime[x])
        {
            ans[i].first = ans[i].second = -1;
        }
        else
        {
            for (int j = 0; j < (int)prime.size(); j++)
            {
                if (!(x % prime[j]))
                {
                    int tmp = x, sum = 1;
                    while (!(tmp % prime[j]))
                    {
                        tmp /= prime[j];
                        sum *= prime[j];
                    }
                    if (tmp == 1)
                    {
                        ans[i].first = ans[i].second = -1;
                    }
                    else
                    {
                        ans[i].first = tmp;
                        ans[i].second = sum;
                    }
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", ans[i].first);
    }
    printf("\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", ans[i].second);
    }
    return 0;
}