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
void work()
{
	int a,b,c;
	cin>>a>>b>>c;
	int both=b+c-a;
	int s=b-both,t=c-both;
	cout<<max(s,t)+1<<endl;
}
int main()
{
	int T;
	cin>>T;
	while(T--) work();
	return 0;
}