#include <stdio.h>

const int MN = 200000 + 5;

int N, K;
char A[MN];
int num[MN];
int pos[MN];
int tot;

int main() {
    scanf("%d%d",&N,&K);
    scanf("%s",A);

    int c = 0;
    for(int i=0;i<N;i++){
        if(A[i] == '(') {
            num[i] = tot++;
            pos[c++] = i;
        }
        else {
            c--;
            num[i] = num[pos[c]];
        }
    }
    for(int i=0;i<N;i++){
        if(num[i] < K/2) {
            printf("%c", A[i]);
        }
    }
    return 0;
}