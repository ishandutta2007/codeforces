#include <bits/stdc++.h>
using namespace std;

int minim(int a,int b){
	if (a<b)
	{
		return a;
	}
	return b;
}

int main(){
	int n,m;
	cin>>n>>m;
	int min[n]={0},max[n]={0};
	char x;

	for (int i = n-1; i >=0; --i)
	{
		cin>>x;
		for (int j = 1; j <= m; ++j)
		{
			cin>>x;
			if (min[i]==0&&x=='1')
			{
				min[i]=j;
			}
			if (max[i]<j&&x=='1')
			{
				max[i]=j;
			}
		}
		cin>>x;

	}

	int ansl[n],ansr[n],c=n-1;
	while(min[c]==0){
		ansl[c]=0;
		ansr[c]=0;
		c--;
		if (c==-1)
		{
			break;
		}
	}
	if (c>=0)
	{
	
		ansl[c]=max[c];
		ansr[c]=m+1-min[c];
	}
	if (c>=1)
	{
		
	for (int i = c-1; i >=0; --i)
	{
		if (min[i]==0)
		{
			ansl[i]=ansl[i+1];
			ansr[i]=ansr[i+1];
		}
		else{
			ansl[i]=minim(m+1+ansr[i+1],2*max[i]+ansl[i+1]);
			ansr[i]=minim(m+1+ansl[i+1],2*(m+1-min[i])+ansr[i+1]);
		}
	}
}
if (c==-1)
{
	c++;
}
	cout<<ansl[0]+c<<endl;
	return 0;
}