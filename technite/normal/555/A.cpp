#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, m,f=0, result = 0;
	int l=1;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		f=0;
		int x;
		cin>>x;
		for(int j=1;j<=x;j++)
		{
			int y;
			cin>>y;
			if(y==j==1)
			{
			    f=1;
				for(int k=2;k<=x;k++){
					cin>>y;
					if(y==k)
					{
						l++;
					}
				}
				    result+=x-l;
			}


				
			if(f==1){
				break;
		}
	}

		
		if(f==0) {
			result+=x-1;
		}
	}
	
	cout<<result+n-l;
}