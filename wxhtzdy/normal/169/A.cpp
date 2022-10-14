#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 500;

int n, a, b, A[N];

int main(){
    scanf("%d%d%d", &n, &a, &b);
    for(int i = 1;i <= n;i++){
        scanf("%d", A + i);
    }
    int gasercina = -1;
    for(int i = 1;i <= n;i++){
        int x = 0, y = 0;
        for(int j = 1;j <= n;j++){
            if(A[j] > A[i]) x++;
            else y++;
        }
        if(x == a && y == b){
            gasercina = A[i];
        }
    }
    if(gasercina == -1) return 0 * printf("0");
    int vocni_jogurt = 0;
    sort(A + 1, A + n + 1);
    for(int i = 1;i + 1 <= n;i++){
        if(A[i] == gasercina){
            vocni_jogurt = A[i + 1] - A[i];
        }
    }
    printf("%d", vocni_jogurt);
}