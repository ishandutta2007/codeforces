#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

long long x;
int n, d;
int res[100010], a[100010], b[100010];

long long getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}

void initab() {
    for(int i = 0; i < n; i++){
        a[i] = i + 1;
    }
    for(int i = 0; i < n; i++){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(int i = 0; i < n; i++){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(int i = 0; i < n; i++){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}

void sol1() {
    for (int i = 0; i < n; i++)
    if (b[i])
    {
        for (int j = i; j < n; j++)
        if (res[j] < a[j - i])
            res[j] = a[j - i];
    }
}

void sol2(){
    int k = n - 2 * sqrt(n);
    for (int i = 0; i < n; i++)
    if (a[i] >= k){
        int l = n - i;
        for (int j = 0; j < l; j++)
            if (b[j] && res[j + i] < a[i])
            res[j + i] = a[i];
    }
    for (int i = 0; i < n; i++)
    if (!res[i]){
        for (int j = 0; j <= i; j++)
        if (b[i - j] && res[i] < a[j])
            res[i] = a[j];
    }
}

int main()
{
    cin >> n >> d >> x;
    initab();
//    for (int i = 0; i < n; i++)
//    cout << a[i] << ' ' << b[i] << endl;
    int sd = sqrt (n) * 6.8;
    if (d <= sd) sol1();
    else sol2();
    for (int i = 0; i < n; i++)
    printf ("%d\n", res[i]);
}