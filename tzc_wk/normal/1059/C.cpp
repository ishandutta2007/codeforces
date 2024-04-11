#include <bits/stdc++.h>
using namespace std;
int n;
void print(int s,int tp) {
    if(s==3) {printf("%d %d %d",tp,tp,tp*3);return;}
    if(s==2) {printf("%d %d",tp,tp*2);return;}
    if(s==1) {printf("%d",tp);return;}
    for(int i=1;i<=s-(s>>1);i++) printf("%d ",tp);
    print((s>>1),tp<<1);
}
int main() {
    scanf("%d",&n);
    print(n,1);
}