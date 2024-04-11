#include<stdio.h>
#include<vector>
#include<deque>

using namespace std;

deque<int>a;
int n;

void push(int x){
  if(x>n){return;}
  if(x%2==0){a.push_front(x);}else{a.push_back(x);}
  push(x+1);
}

int main(){
 scanf("%d",&n);
 if(n==1){printf("1\n1");return 0;}
 if(n==2){printf("1\n1");return 0;}
 if(n==3){printf("2\n1 3");return 0;}
 a.push_front(1);a.push_back(4);a.push_front(3);a.push_back(2);
 push(5);
 printf("%d\n",n);
 while(!a.empty()){
   printf("%d ",a.front());
   a.pop_front();
 }
 return 0;
}