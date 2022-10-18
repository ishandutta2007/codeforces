#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int n;
	cin>>n;
	int sum=0;
	char x; 
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(x=='8')
		{
			sum++;
		}
	}
	printf("%d\n",min(sum,n/11));
	return 0;
}
//qwnfhasdkjxfarxg