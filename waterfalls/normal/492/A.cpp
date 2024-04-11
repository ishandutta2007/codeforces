#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int h = 1;
    int sum = 1;
    while (true) {
        if (n<sum) {
            printf("%d\n",h-1);
            break;
        }
        h+=1;
        sum+=h*(h+1)/2;
    }

    return 0;
}