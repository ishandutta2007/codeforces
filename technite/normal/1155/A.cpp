#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    string a;
  cin>>N;
  cin>>a;
  for(int i=0; i<N-1; ++i)
  {
    if(a[i]>a[i+1])
    {
     cout<<"YES"<<endl;
     cout<<i+1<<' '<<i+2;
      return 0;
    }
  }
  cout<<"NO";
}