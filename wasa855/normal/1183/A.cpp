#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	int ans=0;
	while(isdigit(ch))
	{
		ans=ans*10+ch-48;
		ch=getchar();
	}
	return ans;
}
bool judge(int x)
{
	int res=0;
	while(x>0)
	{
		res+=x%10;
		x/=10;
	}
	if(res%4==0) return true;
	return false;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int x=read();
	while(judge(x)==false) x++;
	cout<<x<<endl;
	return 0;
}