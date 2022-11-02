#include <cstdio>

using namespace std;

int main() {
    int pos[10] = {2,7,2,3,3,4,2,5,1,2};
    char num[5];
    scanf("%s",&num);
    printf("%d\n",pos[num[0]-48]*pos[num[1]-48]);

    return 0;
}