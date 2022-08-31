#include <iostream>
using namespace std;

int n;
int a[20];

int main()
{
    a[1] = 1; // +
    a[2] = 0; // +
    a[3] = 0; // +
    a[4] = 1; // +
    a[5] = 0; // +
    a[6] = 1; // +
    a[7] = 0; // +
    a[8] = 1; // +
    a[9] = 1; // +
    a[10] = 1; // +
    a[11] = 0; // +
    a[12] = 0; //
    a[13] = 1; // +
    a[14] = 0; //
    a[15] = 1; // +
    a[16] = 0; // +
    scanf("%d", &n);
    if (n > 16 || n < 1)
        throw;
    printf("%d\n", a[n]);

    return 0;
}