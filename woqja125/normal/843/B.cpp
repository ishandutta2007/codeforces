#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<time.h>
using namespace std;
int a[50001];
int main(){
        int n, x, start;
        scanf("%d%d%d", &n, &start, &x);
        for(int i=1; i<=n; i++) a[i] = i;
        srand(time(NULL));
        random_shuffle(a+1, a+n+1);
        int max = -1, nn = start;
        for(int i=1; i<=n && i<=1000; i++){
                printf("? %d\n", a[i]);
                fflush(stdout);
                int v, next;
                scanf("%d%d", &v, &next);
                if(v == x){
                        printf("! %d\n", v);
                        return 0;
                }
                if(v > x) continue;
                if(max < v){
                        max = v;
                        nn = next;
                }
        }
        while(max < x && nn!=-1){
                printf("? %d\n", nn);
                fflush(stdout);
                scanf("%d%d", &max, &nn);
        }
        if(max >= x) printf("! %d\n", max);
        else printf("! -1\n");
        return 0;
}