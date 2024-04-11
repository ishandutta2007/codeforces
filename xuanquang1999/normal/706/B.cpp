#include <cstdio>
#include <algorithm>

using namespace std;

int a[100005], n, q;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
    //Sp xp mng a
    sort(a, a+n);

    scanf("%d", &q);
    for(int i = 0; i < q; ++i) {
        int x;
        scanf("%d", &x);
        //S phn t <= x chnh l v tr ca phn t u tin > x trong a
        //(Lu : ch s mng a bt u t 0)
        //Do hm upper_bound tr v a ch nn phi tr i a  ly c v tr
        printf("%d\n", upper_bound(a, a+n, x)-a);
    }
}