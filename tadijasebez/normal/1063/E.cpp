#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=1050;
int a[N];
char ans[N][N];
bool was[N];
void ShiftMax(vector<int> &v)
{
	int mx=0;
	for(int i=1;i<v.size();i++) if(v[mx]<v[i]) mx=i;
	vector<int> tmp;
	for(int i=mx;i<v.size();i++) tmp.pb(v[i]);
	for(int i=0;i<mx;i++) tmp.pb(v[i]);
	v=tmp;
}
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) ans[i][j]='.';
	int r=0;
	for(i=1;i<=n;i++) if(a[i]!=i) r=i;
	if(!r)
	{
		printf("%i\n",n);
		for(i=1;i<=n;i++) printf("%s\n",ans[i]+1);
		return 0;
	}
	int ro=n;
	for(i=1;i<=n;i++) if(a[i]!=i && !was[i])
	{
		vector<int> cyc;
		for(j=i;!was[j];j=a[j]) was[j]=1,cyc.pb(j);
		int pre=ro;
		ShiftMax(cyc);
		if(cyc[0]==r) continue;
		ans[ro][cyc.back()]='/';
		ans[ro][cyc[0]]='/';
		ro--;
		for(j=(int)cyc.size()-2;j>0;j--)
		{
			if(cyc[j]<cyc[j+1])
			{
				ans[ro][cyc[j]]='/';
				ans[ro][cyc[j+1]]='/';
			}
			else
			{
				ans[ro][cyc[j]]='\\';
				ans[ro][cyc[j+1]]='\\';
			}
			ro--;
		}
		if(cyc[0]!=r)
		{
			ans[pre][r]='/';
			ans[ro][r]='\\';
			ans[ro][a[cyc[0]]]='\\';
			ro--;
		}
	}
	for(i=1;i<=n;i++) was[i]=0;
	for(i=1;i<=n;i++) if(a[i]!=i && !was[i])
	{
		vector<int> cyc;
		for(j=i;!was[j];j=a[j]) was[j]=1,cyc.pb(j);
		int pre=ro;
		ShiftMax(cyc);
		if(cyc[0]!=r) continue;
		ans[ro][cyc.back()]='/';
		ans[ro][cyc[0]]='/';
		ro--;
		for(j=(int)cyc.size()-2;j>0;j--)
		{
			if(cyc[j]<cyc[j+1])
			{
				ans[ro][cyc[j]]='/';
				ans[ro][cyc[j+1]]='/';
			}
			else
			{
				ans[ro][cyc[j]]='\\';
				ans[ro][cyc[j+1]]='\\';
			}
			ro--;
		}
	}
	printf("%i\n",n-1);
	for(i=1;i<=n;i++) printf("%s\n",ans[i]+1);
	return 0;
}