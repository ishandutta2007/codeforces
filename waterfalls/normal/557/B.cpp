#include <cstdio>
#include <algorithm>

using namespace std;

int a[200013];

int main() {
    int n,w;
    scanf("%d%d",&n,&w);
    for (int i=0;i<2*n;i++) scanf("%d",&a[i]); 
    sort(a,a+2*n);
    int one = a[0];
    int two = a[n];
    int ans = min(2*one,two);
    printf("%1.9f\n",min(1.*n*3/2*ans,(double) w));
}