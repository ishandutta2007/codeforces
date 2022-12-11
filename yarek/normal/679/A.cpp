#include <bits/stdc++.h>
using namespace std;

vector<int> pr = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 };

char ans[5];

int main()
{
    vector<int> div;
    for(auto x: pr)
    {
        printf("%d\n", x);
        fflush(stdout);
        scanf("%s", ans);
        if(ans[0] == 'y')
            div.push_back(x);
    }
    if(div.size() == 0 || (div.size() == 1 && div[0] > 10))
    {
        puts("prime");
        fflush(stdout);
    }
    else if(div.size() > 1)
    {
        puts("composite");
        fflush(stdout);
    }
    else
    {
        printf("%d\n", div[0] * div[0]);
        fflush(stdout);
        scanf("%s", ans);
        puts(ans[0] == 'y' ? "composite" : "prime");
        fflush(stdout);
    }
}