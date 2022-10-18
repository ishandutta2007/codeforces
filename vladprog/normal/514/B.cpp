#include<bits/stdc++.h>

using namespace std;

int main()
{
  int n,x0,y0;
  cin>>n>>x0>>y0;
  long double x[n],y[n];
  for(int i=0;i<n;i++)
  {
    cin>>x[i]>>y[i];
    x[i]-=x0;
    y[i]-=y0;
  }
  bool b[n];
  int k=n;
  memset(b,0,sizeof(b));
  for(int i=0;i<n;i++)
    if(!b[i])
      for(int j=i+1;j<n;j++)
        if(((y[i]==0)&&(y[j]==0))||((x[i]/y[i])==(x[j]/y[j])))
        {
          k--;
          b[j]=true;
        }
  cout<<k;
}