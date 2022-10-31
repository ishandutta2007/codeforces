#include <bits/stdc++.h>
using namespace std;

int f,I,t,ans,i,j,has[10];//kitten

int main() {
scanf("%d%d%d",&f,&I,&t);
for (i=0;i<f;i++) {
for (j=0;j<I;j++) {
char c;
scanf(" %c",&c);
if (c=='Y') has[j]+=1;
}
}
ans = 0;
for (i=0;i<I;i++) ans+=has[i]>=t;
printf("%d\n",ans);
}