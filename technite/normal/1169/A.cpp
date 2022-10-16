#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,x,b,y;
	cin>>n>>a>>x>>b>>y;
	while(a!=x&&b!=y){
		a=a%n+1;
		b=(b-1)%n;
		if(b==0) b=n;
		if(a==b){
		    cout<<"YES";
		    return 0;
		}
	}
	puts("NO");
}