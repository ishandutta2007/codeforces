#include<iostream>
#include<set>
using namespace std;
int main()
{
set <int>s;
for(int i=0,a;i<4;i++)
{
cin>>a;
s.insert(a);
}
cout<<4-s.size()<<endl;
}