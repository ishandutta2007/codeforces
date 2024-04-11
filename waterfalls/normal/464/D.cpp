#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,k;
double prev[100013];
double next[100013];
const int TYPE = 991;

int main() {
    scanf("%d%d",&n,&k);
    for (int j=TYPE;j>=1;j--) {
        next[0] = 0;
        for (int i=1;i<=n;i++) {
            next[i] = 0;
            next[i]+=1.*(k-1)/k*next[i-1];
            next[i]+=1./k*j/(j+1)*((j+1)/2.+next[i-1]);
            next[i]+=1./k*1./(j+1)*(j+prev[i-1]);
        }
        swap(prev,next);
    }
    printf("%1.12f\n",k*prev[n]);

    return 0;
}