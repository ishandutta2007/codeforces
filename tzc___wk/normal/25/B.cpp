#include <bits/stdc++.h>
using namespace std;
string tele;
int n2=0,n3=0;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>tele[i];
	}
	for(int i=0;i<3;i++)
	{
		if((n-(2*i))%3==0)
		{
			n2=i;
		}
	}
	if(n==2)	
	{
		cout<<tele[0]<<tele[1];
		return 0;
	}
	else if(n==3)
	{
		cout<<tele[0]<<tele[1]<<tele[2];
		return 0;
	}
	else if(n==4)
	{
		cout<<tele[0]<<tele[1]<<"-"<<tele[2]<<tele[3];
		return 0;
	}
	n3=(n-2*n2)/3;
	//cout<<n2<<" "<<n3<<endl;
	int cur=0;
	for(int i=0;i<n2;i++)
	{
		cout<<tele[cur]<<tele[cur+1]<<"-";
		cur=cur+2; 
	}
	//cout<<cur<<endl;
	for(int i=0;i<n3-1;i++)
	{
		cout<<tele[cur]<<tele[cur+1]<<tele[cur+2]<<"-";
		cur=cur+3;
	}
	cout<<tele[cur]<<tele[cur+1]<<tele[cur+2];
	return 0;
}