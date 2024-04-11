#include <bits/stdc++.h>
using namespace std;
const int N=500;
int i,j,n,an,ansn,x,ind,l,r;
int mas[N+1],a[N+1],end[N+1],ans[N+1];
char ch[N+1];
int main()
	{
	cin>>n;
	for (i=1;i<=n;i++)
		cin>>mas[i];
	cin>>an;
	for (i=1;i<=an;i++)
		cin>>a[i];
	for (i=1;i<=n;i++)
		{
		x+=mas[i];
		if (x==a[ind+1])
			{
			x=0;
			ind++;
			end[ind]=i;
			}
		}
	if (x!=0 || ind!=an)
		{
		cout<<"NO"<<endl;
		return 0;
		}
	for (i=1;i<=an;i++)
		{
		l=end[i-1]+1;
		r=end[i];
		x=0;
		ind=0;
		for (j=l;j<=r;j++)
			if (mas[j]>x && ((j>l && mas[j-1]<mas[j]) || (j<r && mas[j+1]<mas[j])))
				{
				x=mas[j];
				ind=j;
				}
		if (ind==0 && l!=r)
			{
			cout<<"NO"<<endl;
			return 0;
			}
		if (l==r)
			continue;
		if (ind>l && mas[ind-1]<mas[ind])
			{
			for (j=0;j<(ind-l);j++)
				{
				ansn++;
				ans[ansn]=i-j+ind-l;
				ch[ansn]='L';
				}
			for (j=0;j<(r-ind);j++)
				{
				ansn++;
				ans[ansn]=i;
				ch[ansn]='R';
				}
			continue;
			}
		if (ind<r && mas[ind+1]<mas[ind])
			{
			for (j=0;j<(r-ind);j++)
				{
				ansn++;
				ans[ansn]=i+ind-l;
				ch[ansn]='R';
				}
			for (j=0;j<(ind-l);j++)
				{
				ansn++;
				ans[ansn]=i-j+ind-l;
				ch[ansn]='L';
				}
			}
		}
	cout<<"YES"<<endl;
	for (i=1;i<=ansn;i++)
		cout<<ans[i]<<" "<<ch[i]<<endl;
	}