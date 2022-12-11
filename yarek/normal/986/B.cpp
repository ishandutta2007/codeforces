#include <bits/stdc++.h>
using namespace std;

const int N = 1000001;
int per[N];

int main()
{
    int n;
    scanf("%d", &n);
    int one = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", per + i);
        if(per[i] == i) one++;
    }
    int thresh = n <= 10000 ? 2 : 10;
    if(n == 5) thresh = -1;
    puts(one <= thresh ? "Um_nik" : "Petr");
}