#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n1,n2;

int main() {
    scanf("%d%d",&n1,&n2);
    printf("%s\n",(n1>n2) ? "First" : "Second");

    return 0;
}