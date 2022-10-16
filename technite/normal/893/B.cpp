#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,i,s=1;
	cin>>n;
	for(i=1;i<=n;i++){
    x=(pow(2,i)-1)*(pow(2,i-1));
    if(x<=n && n%x==0)s=x;
    }
	cout<<s<<endl;
    return 0;
}