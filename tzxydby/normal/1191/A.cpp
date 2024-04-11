#include<bits/stdc++.h>
using namespace std;
int s(int x)
{
	if(x%4==0)
		return 3;
	if(x%4==1)
		return 0;
	if(x%4==2)
		return 2;
	if(x%4==3)
		return 1;
}
int main()
{
	int n;
	cin>>n;
	int ans=n;
	if(s(n+1)<s(n))
		ans=n+1;
	if(s(n+2)<s(ans))
		ans=n+2;
	cout<<ans-n<<' '<<(char)('A'+s(ans)); 
	return 0;
}