#include <bits/stdc++.h>
using namespace std;
const int N=300050;
char s[N];
int main(){
    int n;
    scanf("%i %s",&n,&s);
    for(int i=0;i<n-1;i++){
        if(s[i]>s[i+1]){
            printf("YES\n%i %i",i+1,i+2);
            return 0;
        }
    }
    printf("NO");
    return 0;
}