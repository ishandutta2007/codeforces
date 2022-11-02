#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int r,x,y,x2,y2;

int main() {
    scanf("%d%d%d%d%d",&r,&x,&y,&x2,&y2);
    printf("%d\n",(int) (ceil(sqrt((long long) (x-x2)*(x-x2)+(long long) (y-y2)*(y-y2))/(2*r))+1e-9));

    return 0;
}