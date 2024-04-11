#include<bits/stdc++.h>
using namespace std;
int main(){
 int n,k;
 cin>>n>>k;
 if(n<k*(k+1LL)/2)
  cout<<"NO",exit(0);
 n-=k*(k+1LL)/2;
 vector<int>a={n/k+1};
 n%=k;
 for(int i=1;i<k;++i)
  if(k-i<=n&&a[i-1]>1)
   a.push_back(a[i-1]+2),n-=k-i;
  else
   a.push_back(a[i-1]+1);
 if(n>0)
  cout<<"NO";
 else{
  cout<<"YES\n";
  for(int i:a)
   cout<<i<<" ";
 }
}