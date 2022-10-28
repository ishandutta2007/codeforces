#include<bits/stdc++.h>
using namespace std;
int main(){
 int n;
 cin>>n;
 vector<int>a(n);
 for(int &i:a)
  cin>>i;
 sort(a.begin(),a.end());
 int u=0,v=0;
 for(int i=0,j=0;i<n;++i){
  for(j=max(i,j);j<n-1&&(((j==i||a[j]==a[j-1])&&a[j+1]==a[j]+1)||a[j+1]==a[j]);++j);
  if(j-i>v-u)
   u=i,v=j;
 }
 cout<<v-u+1<<"\n";
 vector<int>b;
 for(int i=u;i<=v;++i)
  if(i==u||a[i]!=a[i-1])
   cout<<a[i]<<" ";
  else
   b.push_back(a[i]);
 for(int i=b.size()-1;i>=0;--i)
  cout<<b[i]<<" ";
}