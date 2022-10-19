#include <bits/stdc++.h>
using namespace std;
int maxx(int a,int b,int c)
{
	return max(max(a,b),c);
}
int minn(int a,int b,int c)
{
	return min(min(a,b),c);
}
int midd(int a,int b,int c)
{
	if(c==maxx(a,b,c))	return max(a,b);
	else	return max(min(a,b),c);
}
int ok(int a,int b,int c)
{
	int x=minn(a,b,c);
	int y=midd(a,b,c);
	int z=maxx(a,b,c);
	if(x+y>z)	return 2;
	else if(x+y==z)	return 1;
	return 0;
}
int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(ok(a,b,c)==2||ok(a,b,d)==2||ok(a,c,d)==2||ok(b,c,d)==2)
	{
		cout<<"TRIANGLE"<<endl;
		return 0; 
	}
	else if(!ok(a,b,c)&&!ok(a,b,d)&&!ok(a,c,d)&&!ok(b,c,d))
	{
		cout<<"IMPOSSIBLE"<<endl;
		return 0;
	}
	cout<<"SEGMENT"<<endl;
	return 0;
}