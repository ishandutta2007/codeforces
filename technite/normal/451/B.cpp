#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cin >> n;
   int a[n];
   for(int i=0;i<n;i++){
    cin >> a[i];
   }
   int i=1,l=1,r=n;
   while(i<n && a[i]>a[i-1]){
       i++;
       l=i;
   }
   while(i<n && a[i]<a[i-1]){
   i++;
   r=i;
}
   reverse(a+l-1,a+r);
 
  if(is_sorted(a,a+n)){
    cout << "yes" << endl;
    cout << l << " " << r << endl;
  }
  else cout << "no" << endl;
}