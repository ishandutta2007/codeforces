#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a,b;
    scanf("%lld%lld",&a,&b);
    for(int i=1;i<=1000;i++){
        if(a%b==0){printf("Yes");return 0;}
        a+=a%b;
    }
    printf("No");
}