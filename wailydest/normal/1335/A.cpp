#include <iostream>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    
    int n;
    while (t--) {
        scanf("%d", &n);
        if (n <= 2) printf("0\n");
        else printf("%d\n", (n / 2) - !(n % 2));
    }
}