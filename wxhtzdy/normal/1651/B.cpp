#include <bits/stdc++.h>
using namespace std;
int main(){
int tt;
scanf("%i",&tt);
while(tt--){
int n;
scanf("%i",&n);
if(n<=19){
printf("YES\n");
for(int i=1,x=1;i<=n;i++)printf("%i ",x),x*=3;
printf("\n");
}
else printf("NO\n");
}
}