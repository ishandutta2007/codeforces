#include <bits/stdc++.h>
using namespace std;
int main(){
int tt;
scanf("%i",&tt);
while(tt--){
int b[7];
for(int i=0;i<7;i++)
scanf("%i",&b[i]);
printf("%i %i ",b[0],b[1]);
if(b[2]==b[0]+b[1])
printf("%i\n",b[3]);
else
printf("%i\n",b[2]);
}
}