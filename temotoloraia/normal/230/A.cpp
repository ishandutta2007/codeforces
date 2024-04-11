#include <iostream>
#include <algorithm>
using namespace std;
pair<int,int> a[1005];
int n,m,i;
main () {
cin>>n>>m;
for (i=0; i<m; i++)
 cin>>a[i].first>>a[i].second;
 sort(a,a+m);
 for(i=0; i<m; i++) {
 if(n>a[i].first) n=n+a[i].second; else {cout<<"NO"; return 0;} }
 cout<<"YES";
}