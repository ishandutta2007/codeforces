#include <cstdio>
using namespace std;
int main(){
    int n;
    scanf("%d",& n);
    while(n>1){
        if(n&1){
            puts("NO");
            return 0;
        }
        n>>=1;
    }
    puts("YES");
    return 0;
}