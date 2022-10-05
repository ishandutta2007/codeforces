#include <iostream>
using namespace std;
int n,m,x;
int main(){
    cin>>n>>m>>x;
    n-=(x*2);m-=(x*2);
    n+=2;m+=2;
    if(n<1||m<1)	cout<<"0";
	else if(n==1&&m==1) cout<<1;
	else cout<<(n+m-2);
    return 0;
}