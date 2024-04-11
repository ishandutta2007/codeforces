#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[100005];
int ans[1005][1005],cnt;
vector <int> b[1005];
int del[1005];
int main(int argc, char** argv) {
	int n,now=0,CNT=0;
	cin >> n;
	cout << n+1 << endl;
	for(int i=1;i<=n+1;i++)
		b[1].push_back(i);
	cnt=1;
	for(int i=1;i<=n;i++)
	{
		int t;
		cin >> t;
		int x=t,flag=0,C=0;
		if(x>n+1-x) flag=1,x=n+1-x;
		//cout << x << " ";
		for(int j=1;j<=n+1;j++)
		{
			if(x<=0)
				break;
			if(x==1&&cnt!=n+1) break;
			if(del[j])
			{
				--x;
				ans[i][j]=1;
				++C;
			}
		}
		//cout << C << " ";
		for(int j=1;j<=cnt;j++)
		{
			if(x<=0) break;
			if(b[j].size()==1) {del[b[j][0]]=1;continue;}
			++cnt;
			while(b[j].size()>1&&x>0)
			{
				--x;	
				b[cnt].push_back(b[j][b[j].size()-1]);
				ans[i][b[j][b[j].size()-1]]=1;
				++C;
				b[j].pop_back();
			}
			if(b[cnt].size()==1) ++CNT,del[b[cnt][0]]=1;
			if(x<=0) break;
			if(b[j].size()==1)
				del[b[j][0]]=1,++CNT;
		}
		for(int j=1;j<=n+1;j++)
			ans[i][j]^=flag;
		//cout << C << " " << CNT << endl;	
	}
	for(int j=1;j<=n+1;j++)
	{
		for(int i=1;i<=n;i++)
		{
			cout << ans[i][j];
		}
		puts("");
	}
	return 0;
}