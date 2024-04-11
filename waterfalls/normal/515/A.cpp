#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int a,b,s;

int main() {
    scanf("%d%d%d",&a,&b,&s);
    printf("%s\n",s>=abs(a)+abs(b) && (s-abs(a)-abs(b))%2==0 ? "Yes" : "No");

    return 0;
}