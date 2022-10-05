#include <bits/stdc++.h>
using namespace std;
int cnt,n,a,b,num;
string seat;
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	getchar();
	num=2; 
	cin>>seat;
	for(int i=0;i<n;i++)
	{
		if(seat[i]=='*'){num=2;continue;}
		else
		{
			if(num==1){if(a){a--;cnt++;num=0;}else num=2;}
			else if(num==0){if(b){b--;cnt++;num=1;}else num=2;}
			else if(num==2&&(a||b))
			{
				if(a>b){a--;cnt++;num=0;}
				else{b--;cnt++;num=1;}
			}
		}
	}
	printf("%d",cnt);
	return 0;
}