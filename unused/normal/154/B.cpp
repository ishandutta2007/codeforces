#include <bits/stdc++.h>
using namespace std;

bool notprime[100006];
vector<int> divs[100006];
void getprime()
{
    notprime[1] = true;
    for (int i = 2; i <= 100000; i++)
    {
        if (notprime[i]) continue;
        divs[i].push_back(i);
        for (int j = i * 2; j <= 100000; j += i)
        {
            notprime[j] = true;
            divs[j].push_back(i);
        }
    }
}

int yes[100006];
bool on[100006];

int main()
{
    getprime();
    int n, m;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < m; i++)
    {
        char ch;
        int t;
        scanf(" %c%d",&ch,&t);
        if (ch == '+')
        {
            if (on[t])
            {
                printf("Already on\n");
            }
            else
            {
                bool wrong = false;
                for (int x : divs[t])
                {
                    if (yes[x])
                    {
                        printf("Conflict with %d\n", yes[x]);
                        wrong = true;
                        break;
                    }
                }
                if (wrong == false)
                {
                    printf("Success\n");
                    for (int x : divs[t]) yes[x] = t;
                    on[t] = true;
                }
            }
        }
        else
        {
            if (on[t])
            {
                on[t] = false;
                for (int x : divs[t]) yes[x] = 0;
                printf("Success\n");
            }
            else printf("Already off\n");
        }
    }
}