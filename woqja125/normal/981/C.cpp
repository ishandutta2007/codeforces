#include<cstdio>

int d[100001];
int main(){
    int n, a, b, cnt=0;
    scanf("%d", &n);
    for(int i=1; i<n; i++){
        scanf("%d%d", &a, &b);
        d[a]++; d[b]++;
    }
    int r = -1;
    for(int i=1; i<=n; i++){
        if(d[i] > 2){
            if(r!=-1){
                printf("No\n");
                return 0;
            }
            r = i;
        }
        if(d[i] == 1){
            cnt++;
        }
    }
    printf("Yes\n");
    if(r == -1){
        printf("1\n");
        for(int i=1; i<=n; i++) if(d[i] == 1) printf("%d ", i);
    }
    else{
        printf("%d\n", cnt);
        for(int i=1; i<=n; i++) if(d[i] == 1) printf("%d %d\n", r, i);
    }
    return 0;
}