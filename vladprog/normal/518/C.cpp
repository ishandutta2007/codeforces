#include<bits/stdc++.h>

using namespace std;

int main()
{
  int n,m,k;
  cin>>n>>m>>k;
  int a[n+1],b[n+1];
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];
    b[a[i]]=i;
  }
  long long ans=0;
  for(int i=1;i<=m;i++)
  {
    /*cout<<"a: ";
    for(int j=1;j<=n;j++)
      cout<<a[j]<<' ';
    cout<<endl<<"b: ";
    for(int j=1;j<=n;j++)
      cout<<b[j]<<' ';
    cout<<endl<<endl;*/
    int t;
    cin>>t;
    ans+=(b[t]+k-1)/k;
    if(b[t]==1)
      continue;
    //cout<<"swap(a["<<b[t]-1<<"]="<<a[b[t]-1]<<",a["<<b[t]<<"]="<<a[b[t]]<<"]"<<endl<<endl;
    int v=a[b[t]];
    a[b[t]]=a[b[t]-1];
    a[b[t]-1]=v;
    b[a[b[t]]]++;
    b[t]--;
  }
  /*cout<<"a: ";
  for(int j=1;j<=n;j++)
    cout<<a[j]<<' ';
  cout<<endl<<"b: ";
  for(int j=1;j<=n;j++)
    cout<<b[j]<<' ';
  cout<<endl<<endl;*/
  cout<<ans;
}