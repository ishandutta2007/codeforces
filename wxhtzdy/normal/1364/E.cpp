#include <bits/stdc++.h>
using namespace std;
const int N=2050;
int n,idx[12],p[N];

int Ask(int i,int j){
printf("? %i %i\n",i,j);
fflush(stdout);
int x;
scanf("%i",&x);
return x;
}

int FindVal(int i){
int val=0;
for(int j=0;j<12;j++){
if(idx[j]!=0&&idx[j]!=i){
int qv=Ask(i,idx[j]);
if(qv>>j&1)val+=(1<<j);
}
}
return val;
}

int main(){
scanf("%i",&n);
mt19937 rng(time(0));
for(int i=0;i<30;i++){
int x=(rng()%n)+1;
int y=(rng()%n)+1;
while(x==y)y=(rng()%n)+1;
int v=Ask(x,y);
for(int j=0;j<12;j++)if(!(v>>j&1))idx[j]=x;
}
int val=FindVal(1),id=1;
for(int i=2;i<=n;i++){
if(Ask(i,id)==val){
id=i;
val=FindVal(i);
}
}
for(int i=1;i<=n;i++){
if(i==id)p[i]=val;
else p[i]=Ask(id,i);
}
printf("! ");
for(int i=1;i<=n;i++)printf("%i ",p[i]);
fflush(stdout);
}