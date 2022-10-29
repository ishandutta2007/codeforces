#include <iostream>
#include <algorithm>
using namespace std;
int k,i,a[12],tmp;
int main() {
  cin>>k;
  for (i=0;i!=12;++i) cin>>a[i];
  sort(a,a+12);
  for (i=11;i!=-1;--i) {
    if (tmp>=k) break;tmp+=a[i];
  }	
  if (tmp<k) cout<<-1;
    else cout<<12-i-1;
}