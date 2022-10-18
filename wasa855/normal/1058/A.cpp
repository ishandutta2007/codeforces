#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int n;
	cin>>n;
	int data;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&data);
		if(data==1)
		{
			cout<<"HARD\n";
			return 0;
		}
	}
	cout<<"EASY\n";
	
	return 0;
}