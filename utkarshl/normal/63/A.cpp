#include"string"
#include"iostream"
#include"stdio.h"
#include"algorithm"
using namespace std;
struct member
{
  string name;
  int pos,id;
  bool operator<(const member m)const
  {
    if(id!=m.id)return id<m.id;
    return pos<m.pos;
  }
};
int main()
{
  int N;
  cin>>N;
  member m[N];
  for(int x=0;x<N;x++)
  {
    cin>>m[x].name;
    m[x].pos=x;
    string k;
    cin>>k;
    if(k[0]=='r')m[x].id=0;
    else if(k[0]=='w'||k[1]=='h')m[x].id=1;
    else if(k[0]=='m')m[x].id=2;
    else if(k[0]=='c')m[x].id=3;
    //cout<<"got "<<x<<"\n";
  }
  sort(m,m+N);
  for(int x=0;x<N;x++)
    cout<<m[x].name<<"\n";
}