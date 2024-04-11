#include<bits/stdc++.h>
using namespace std;
const int N=3e3+10;
int n,b[N];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&b[i]);
    for(int i=0;i<n;i++){
        for(int o=0;o<n;o++){
            printf("%d ",(i*(o-i)%n+n+b[i])%n);
        }
        puts("");
    }
    return 0;
}