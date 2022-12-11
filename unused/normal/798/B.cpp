#include <bits/stdc++.h>
using namespace std;

string dat[55];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin>>dat[i];

    int ans = 1e9;

    for (int i = 0; i < dat[0].size(); i++)
    {
        bool wrong = false;
        int sum = i;
        for (int j = 1; j < n; j++)
        {
            int minima = 1e9;
            for (int k = 0; k < dat[j].size(); k++)
            {
                bool wrong3 = false;
                for (int l = 0; l < dat[j].size(); l++)
                {
                    if (dat[j][(k + l) % dat[j].size()] != dat[0][(i + l) % dat[0].size()])
                    {
                        wrong3 = true;
                        break;
                    }
                }

                if (wrong3 == false) minima = min(minima, k);
            }

            if (minima == (int)1e9)
            {
                wrong = true;
                break;
            }
            else sum += minima;
        }

        if (wrong == false) ans = min(ans, sum);
    }

    if (ans == (int)1e9) printf("-1\n");
    else printf("%d\n", ans);
}