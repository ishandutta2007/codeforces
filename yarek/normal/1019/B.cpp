#include <bits/stdc++.h>
using namespace std;

int n;

int ask(int k)
{
    printf("? %d\n", k + 1);
    fflush(stdout);
    int r;
    scanf("%d", &r);
    return r;
}

bool compare(int k)
{
    int a = ask(k), b = ask((k + n / 2) % n);
    if(a == b)
    {
        printf("! %d\n", k + 1);
        exit(0);
    }
    return a < b;
}

int main()
{
    scanf("%d", &n);
    if(n % 4)
    {
        puts("! -1");
        fflush(stdout);
        return 0;
    }
    int a = 0, b = n / 2;
    if(!compare(a)) swap(a, b);
    while(true)
    {
        int c = (a + b) / 2;
        if(compare(c)) a = c;
        else b = c;
    }
}