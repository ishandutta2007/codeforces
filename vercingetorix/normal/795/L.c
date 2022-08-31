#include <stdio.h>

int main() {
   int n,k;
    char s[210000];
   scanf("%d %d\n",&n, &k);
   scanf("%s", s);
//   printf("%s\n", s);
   int l = -1;
   int r = n-1;
   
   while(r-l > 1) {
       int left = k-2;
       int m = (r+l+1)/2;
       int nd = 1;
       int last = 0;
       int ate = 0;
       int p = 0;
       while(p < n) {
           while(p < n && p-ate <= m+1) {
               if(s[p]=='0') last = p;
               p++;
           }
           if(last == ate) {
               if(last == n-1) break;
               nd = k+1;
               break;
           }
           else {
               ate = last;
               nd++;
           }
       }
       if(nd <= k) r=m;
       else l=m;
   }
    printf("%d", r);
}