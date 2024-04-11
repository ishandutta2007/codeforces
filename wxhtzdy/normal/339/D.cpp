#include <bits/stdc++.h>
using namespace std;
const int N=17;
int st[(1<<N)*N],a[1<<N],n,q;
void Set(int ss,int se,int si,int depth){
  if(ss>se)return;
  if(ss==se){st[si]=a[ss];return;}
  int mid=(ss+se)/2;
  Set(ss,mid,si*2+1,depth+1);Set(mid+1,se,si*2+2,depth+1);
  if((n-depth)%2==1)st[si]=st[si*2+1]|st[si*2+2];
  else st[si]=st[si*2+1]^st[si*2+2];
}
void Push(int ss,int se,int sx,int val,int si,int depth){
  if(ss>se||ss>sx||se<sx)return;
  if(ss==se&&ss==sx){st[si]=val;a[ss]=val;return;}
  int mid=(ss+se)/2;
  Push(ss,mid,sx,val,si*2+1,depth+1); Push(mid+1,se,sx,val,si*2+2,depth+1);
  if((n-depth)%2==1)st[si]=st[si*2+1]|st[si*2+2];
  else st[si]=st[si*2+1]^st[si*2+2];
}
int main() {
  scanf("%i%i",&n,&q);
  int res[q];
  for(int i=0;i<(1<<n);i++)scanf("%i",&a[i]);
  Set(0,(1<<n)-1,0,0);
  for(int i=0;i<q;i++){
    int p,b;
    scanf("%i%i",&p,&b);
    Push(0,(1<<n)-1,p-1,b,0,0);
    res[i]=st[0];
  }
  for(int i=0;i<q;i++)printf("%i\n",res[i]);
}