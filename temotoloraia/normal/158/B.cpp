#include<iostream>
using namespace std;
 int a,k;
 int b[5];
 int c;
int main()
{
   
    cin>>a;
    
    for(int i=0;i<a;i++){
    cin>>k;
    b[k]++;
}
c=b[4]+b[3]+b[2]/2;
b[1]=b[1]-b[3];
if (b[2]%2>0){
               b[1]=b[1]-2;
               c=c+1;
               }
if (b[1]>0) c=c+(b[1]+3)/4;
cout<<c<<endl;
  // system("pause");
    return 0;
}