#include<cstdio>
#include<cstring>
int main(){
    char in[101];
    int n, ans = 0;
    scanf("%s", in);
    n = strlen(in);
    for(int i=0; i<n; i++) for(int j=i; j<n; j++){
        for(int k=0; k<=j-i; k++){
            if(in[i+k] != in[j-k]) goto succ;
        }
        continue;
        succ:
        if(ans < j-i+1) ans = j-i+1;
    }
    printf("%d\n", ans);
    return 0;
}