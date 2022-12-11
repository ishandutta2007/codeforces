#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
   int n;
   ll l,r;
   scanf("%d",&n);
   while (n--){
      scanf("%I64d%I64d",&l,&r);
      for(int i=62,j=0;i;i--) if (r&(1LL<<i)){
          if (l&(1LL<<i)) j++;
          else{
//                cout<<i<<'\n';
            if (__builtin_popcountll(r)<=j+i) r=(r^(1LL<<i))|((1LL<<i)-1);
            break;
          }
      }
      printf("%I64d\n",r);
   }
}