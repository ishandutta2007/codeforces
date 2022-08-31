#include"iostream"
#include"stdio.h"
using namespace std;
int count[200];
int main()
{
  int N,k;
  cin>>N>>k;
  for(int x=0;x<N;x++)
  {
    int y;
    cin>>y;
    count[y]++;
  }
  int c=0;
  while(count[k]!=N)
  {
    for(int x=k-1;x;x--)
      if(count[x])
      {
    count[x]--;
    count[x+1]++;
      }
    c++;
  }
  cout<<c;
}