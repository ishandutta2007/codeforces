#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int n,m,k;
int order[100013];
map<int,int> where;

int main() {
    scanf("%d%d%d",&n,&m,&k);
    for (int i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        where[a] = i;
        order[i] = a;
    }
    long long total = 0;
    for (int i=0;i<m;i++) {
        int b;
        scanf("%d",&b);
        total+=1+where[b]/k;
        if (where[b]!=0) {
            swap(order[where[b]],order[where[b]-1]);
            swap(where[b],where[order[where[b]]]);
        }
    }
    printf("%I64d\n",total);

    return 0;
}