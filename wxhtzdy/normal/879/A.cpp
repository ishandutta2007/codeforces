#include<bits/stdc++.h> 
using namespace std; 
int main() { 
  int n;
  scanf("%i",&n);
  int nxt=0;
  for(int i=0;i<n;i++){
    int s,d;
    scanf("%i%i",&s,&d);
    if(nxt<s)nxt=s;
    else nxt=nxt+d-((nxt-s)%d);
  }
  printf("%i",nxt);
}