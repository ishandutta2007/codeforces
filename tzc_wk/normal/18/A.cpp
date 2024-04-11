#include <bits/stdc++.h>
using namespace std;
int moves[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool is3(int x1,int y1,int x2,int y2,int x3,int y3)
{
	int a,b,c;
	a=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	b=(x1-x3)*(x1-x3)+(y1-y3)*(y1-y3);
	c=(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2);
	if(a==0||b==0||c==0)
	return 0;
	if(a+b==c||a+c==b||b+c==a)
	return 1;
	else 
	return 0;
}
int main()
{
	int x1[4],y1[4];
	for(int i=0;i<3;i++)
	{
		cin>>x1[i]>>y1[i];
	}
	if(is3(x1[0],y1[0],x1[1],y1[1],x1[2],y1[2]))
	{
		cout<<"RIGHT"<<endl;
		return 0;
	}
	int tx,ty;
	for(int i=0;i<=3;i++)
	{
		for(int j=0;j<=3;j++)
		{
			tx=x1[i]+moves[j][0];
			ty=y1[i]+moves[j][1];
			if(i==0&&is3(tx,ty,x1[1],y1[1],x1[2],y1[2]))
			{
				cout<<"ALMOST"<<endl;
				return 0;
			}
			if(i==1&&is3(x1[0],y1[0],tx,ty,x1[2],y1[2]))
			{
				cout<<"ALMOST"<<endl;
				return 0;
			}
			if(i==2&&is3(x1[0],y1[0],x1[1],y1[1],tx,ty))
			{
				cout<<"ALMOST"<<endl;
				return 0;
			}		
    	}
    	if(i==3)
    	{
    		cout<<"NEITHER"<<endl;
    		break;
    	}
	}
	return 0;
}