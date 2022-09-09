#include <stdio.h>
#include <algorithm>
using namespace std;
int n,Max,Min,x,sol,d;
int main(){
scanf("%i%i",&n,&d);
while(n--){
scanf("%i",&x);
if(x){
Max+=x;Min+=x;
if(Min>d) return printf("-1"),0;
Max=min(Max,d);
}
else{
Min=max(Min,0);
if(Max<0) Max=d,Min=0,sol++;
}
}
printf("%i",sol);
return 0;
}