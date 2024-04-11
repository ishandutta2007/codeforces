#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define REP(i,n)	for((i)=0;(i)<(int)(n);(i)++)
char buf[110]; 
vector <string> files;
bool aunique[10010];
bool folder[10010];
bool sub(int a,int b)
{
	int i;
	if(files[a].size()>files[b].size())	return false;
	REP(i,files[a].size())	if(files[a][i]!=files[b][i])	return false;
	return true;	
}
int main(void)
{
	int i,j;
	while(scanf("%s",buf)!=EOF)
	{
		string s=buf;
		for(i=4;i<s.size();i++)
		{
			if(s[i]=='\\')
				files.push_back(s.substr(0,i+1));	
		}
		files.push_back(s);	
	}
	sort(files.begin(),files.end());
	int n=files.size();
	REP(i,n)	aunique[i]=folder[i]=true;
	REP(i,n-1)	if(files[i]==files[i+1])	aunique[i+1]=false;
	REP(i,n)	REP(j,files[i].size())	if(files[i][j]=='.')	folder[i]=false;
	int ans1=0,ans2=0;
	REP(i,n)
	{
		int low=i,high=n,mid;
		while(high-low>1)
		{
			mid=(high+low)/2;
			if(sub(i,mid))	low=mid;else high=mid;
		}
		int cnt1=0,cnt2=0;
		for(j=i+1;j<=low;j++)
		{
			if(aunique[j]&&folder[j])cnt1++;		if(aunique[j]&&!folder[j])cnt2++;
		}
		ans1=max(ans1,cnt1);ans2=max(ans2,cnt2);
	}
	cout<<ans1<<" "<<ans2<<endl;
	return 0;
}