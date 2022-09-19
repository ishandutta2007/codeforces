//Note:The template file will be copied to a new file. When you change the code of the template file you can create new file with this base code. 
#include <iostream> 
using namespace std;
int main()
{
    #define int long long
    int n,p,x,s;
    cin>>n;
    p=998244353;
    x=1;
    s=0;
    for(int i=n;i>1;i--)
    {
    x*=i;
    x%=p;
    s-=x;
    s%=p;
    }
s+=(x*n);
s%=p;
cout<<s;
return 0;
}