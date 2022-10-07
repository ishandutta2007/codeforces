#include<iostream>
using namespace std;
char k,w[2][26];
int g,e,m[30],l=0;
main()
{string a; 


cin>>a;
for (int i=0; i<a.size(); i++)
if(m[a[i]-'A']!=0) {k=a[i]; e=m[a[i]-'A']-1;g=i;   
} else m[a[i]-'A']=i+1;
if (g-e==1) {cout<<"Impossible"<<endl; return 0;}

for (int i=(g+e-1)/2; i>=(g+e+1)/2-13; i--)
if (i!=g) cout<<a[(i+54)%27];
cout<<endl;
for (int i=(g+e-1)/2+1; i<=(g+e+1)/2+13; i++)
if (i!=g) cout<<a[i%27];


}