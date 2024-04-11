#include <bits/stdc++.h>
using namespace std;

const int MN = 1e6+100000;
int N, M, T, i, j, col[MN], psa[MN], psa2[MN];
string s;

int main() {
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&M);
        cin >> s;
        for(i=0;i<N*M;i++) psa[i] = col[i] = 0;
        for(j=0;j<M;j++){
            for(i=0;i<N*M;i+=M){
                if(s[i+j] == '1'){
                    col[i+j] ++;
                    break;
                }
            }
        }
        for(i=0;i<N*M;i++) col[i+1] += col[i];
        for(i=0;i<N*M;i++){
            psa[i] = s[i]-'0';
            if(i) psa[i] += psa[i-1];
        }
        for(i=0;i<N*M;i++){
            if(i<M){
                if(psa[i] > 0) psa2[i] = 1;
                else psa2[i] = 0;
            }
            else{
                if(psa[i] - psa[i-M] > 0) psa2[i] = 1;
                else psa2[i] = 0;
            }
        }
        for(j=0;j<M;j++){
            for(i=0;i<N*M;i+=M){
                psa2[i+j+M] += psa2[i+j];
            }
        }
        for(i=0;i<N*M;i++){
            printf("%d%c",psa2[i]+col[i], (i+1==N*M)?'\n':' ');
        }
    }
    return 0;
}