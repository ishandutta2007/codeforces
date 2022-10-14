#include <bits/stdc++.h>

using namespace std;

int main(){
        int T;scanf("%i",&T);
        while(T--){
                int n;scanf("%i",&n);
                printf("%i\n",(((int)sqrt(2*n)+1)/2-1));
        }
        return 0;
}