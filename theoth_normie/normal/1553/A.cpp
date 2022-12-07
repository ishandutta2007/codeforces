#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,k,t,t1,u,v,a,b;
int main()
{
cin>>t;
for (t1=0;t1<t;t1++)
{
cin>>n; n++;
while(n%10!=9) n++;
cout<<(n-9)/10<<endl;
}
}