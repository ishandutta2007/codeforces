#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    int T; cin >> T;

    for (int t = 0; t < T; ++t)
    {
        long long n, a, b; cin >> n >> a >> b;

        vector<bool> road(n);

        for (long long i = 0; i < n; ++i)
        {
            char c; cin >> c;
            road[i] = (c == '1');
        }

        vector<long long> next_one(n, -1);
        long long last = -1;
        for (long long i = n - 1; i >= 0; --i)
        {
            next_one[i] = last;
            if (road[i])
                last = i;
        }

        long long cost = b + b + a;
        bool up = false;

        for (long long i = 0; i < n - 1; ++i)
        {
            if (!up && !road[i+1])
                cost += a + b;

            else if (!up && road[i+1])
            {
                cost += 2 * (a + b);
                up = true;
            }

            else if (up && road[i+1])
            {
                cost += a + 2 * b;
            }

            else // up && !road[i+1]
            {
                if (next_one[i+1] == -1)
                {
                    cost += a + 2 * b + a;
                    up = false;
                }
                else
                {
                    long long up_cost = (next_one[i+1] - i - 1) * (a + 2 * b) - b;
                    long long down_cost = (next_one[i+1] - i - 1) * (a + b) + 2 * a;

                    if (up_cost <= down_cost)
                        cost += a + 2 * b;
                    else
                    {
                        cost += 2 * a + 2 * b;
                        up = false;
                    }
                }
            }
        }
        cout << cost << endl;
    }
    return 0;
}