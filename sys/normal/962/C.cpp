#include <bits/stdc++.h>
using namespace std;
string n;
long long num;
bool win,cho[15];
bool is_squa(long long num)
{
	for(int i=1;i<=n.size();i++)
		if(cho[i]==true)
		{
			if(n[i-1]=='0') 
				return false;
			else break;
		}
	if((long long)num==(long long)sqrt((double)num)*(long long)sqrt((double)num)) return true;
	else return false;
}
long long turn(void)
{
	long long ans=0;
	int cnt=0;
	for(int i=n.size()-1;i>=0;i--)
	{
		ans+=pow(10.0,cnt)*(n[i]-'0')*cho[i+1];
		if(cho[i+1]==true) cnt++;
	}
	return ans;
}
void dfs(int done,int del,int now)
{
	if(del==done&&is_squa(turn())&&!win)
	{
	printf("%d\n",del);win=true;return ;}
	else if(del!=done)
	{
		for(int i=now+1;i<=n.size();i++)
		{
			cho[i]=false;
			dfs(done+1,del,i);
			cho[i]=true;
		}
	}
}
int main()
{
	cin>>n;
	if(n[0]=='0'){printf("-1\n");return 0;}
	for(int i=1;i<=14;i++) cho[i]=true;
	if(is_squa(turn())){printf("0\n");return 0;}
	for(int i=1;i<n.size();i++)
		if(!win)
		{
			for(int j=1;j<=14;j++) cho[j]=true;
			dfs(0,i,0);
		}
	if(!win) printf("-1\n");
	return 0;
}