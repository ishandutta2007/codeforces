#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%i",&n);
    for(int i=1;i<=n;i++){
        if(i*(i+1)/2==n)return 0*printf("YES");
    }
    printf("NO");
    return 0;
}