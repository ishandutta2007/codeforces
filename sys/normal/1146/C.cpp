#include <bits/stdc++.h>
using namespace std;
int t,n,maxi,ans;
string str;
string change(int x)
{
	string tmp="";
	if(x==100) return "100";
	if(x/10) tmp+=(char)(x/10+'0');
	tmp+=(char)(x%10+'0');
	return tmp;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		str="";
		scanf("%d",&n);
		str+="1 ";
		str+=change(n-1);
		str+=" 1";
		for(int i=2;i<=n;i++)
			str+=' ',str+=change(i);
		cout<<str<<' ';
		fflush(stdout);
		scanf("%d",&maxi);
		int l=2,r=n;
		while(l+1<=r)
		{
			str="";
			int mid=(l+r)/2;
			str+="1 ";
			str+=change(mid-l+1);
			str+=" 1";
			for(int i=l;i<=mid;i++)
				str+=' ',str+=change(i);
			int tmp;
			cout<<str<<' ';
			fflush(stdout);
			scanf("%d",&tmp);
			if(tmp==maxi) r=mid;
			else l=mid+1;
		}
		str="1 ";
		str+=change(n-1);
		str+=' ';
		str+=change(l);
		for(int i=1;i<=n;i++)
			if(i!=l)
				str+=' ',str+=change(i);
		cout<<str<<' ';
		fflush(stdout);
		scanf("%d",&ans);
		printf("-1 %d ",ans);
		fflush(stdout);
	}
	return 0;
}