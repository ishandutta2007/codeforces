#include <bits/stdc++.h>
using namespace std;

string nn[105]; int bef[105], aft[105];

int main()
{
	int n;
	scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        cin >> nn[i] >> bef[i] >> aft[i];
        if (bef[i] >= 2400 && aft[i] > bef[i])
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
}