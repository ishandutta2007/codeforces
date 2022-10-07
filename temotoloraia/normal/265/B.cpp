#include<iostream>
#include <cmath>
using namespace std;
int n=0;
int main()
{
    int a; // xeebis raodenoba
    cin>>a;
    int b[100000];
    for (int i=0;i<a;i++)
    {
        cin>>b[i];
        //if (b[i]>b[i+1]) n=n+b[i]-b[i+1];
        //if (b[i+1]>b[i]) n=n+b[i+1]-b[i];
}
for (int i=1;i<a;i++)
    {
        //cin>>b[i];
        n=n+abs(b[i]-b[i-1]);
}
n=n+a;
n=n+a-1;
n=n+b[0];
cout<<n<<endl;
//system("pause");
return 0;
}