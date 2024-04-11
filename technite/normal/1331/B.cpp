#include<bits/stdc++.h>
using namespace std;
 
int main() 
{
	int t;
	cin>>t;
	int pr[11]={2,3,5,7,11,13,17,19,23,29,31};
	for(int i=0;i<11;i++)
	{
		if(t%pr[i]==0) 
		{
		    cout<<pr[i]<<t/pr[i];
		    break;
		}
	}
}