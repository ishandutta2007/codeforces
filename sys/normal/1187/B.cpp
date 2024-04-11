#include <bits/stdc++.h>
using namespace std;
const int Maxn=200005;
int n,cnt[Maxn][28],tmp[28],m;
string str;
bool check(int x)
{
	for(int i=1;i<=26;i++)
		if(cnt[x-1][i]<tmp[i]) return false;
	return true;
}
int binary(void)
{
	int l=1,r=n;
	while(l+1<=r)
	{
		int mid=(l+r)/2;
		if(!check(mid)) l=mid+1;
		else r=mid;
	}
	return l;
}
int main()
{
	scanf("%d",&n);
	cin>>str;
	cnt[0][str[0]-'a'+1]++;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=26;j++)
			cnt[i][j]=cnt[i-1][j];
		cnt[i][str[i]-'a'+1]++;
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		memset(tmp,0,sizeof(tmp));
		cin>>str;
		int siz=str.size();
		for(int i=0;i<siz;i++)
			tmp[str[i]-'a'+1]++;
		printf("%d\n",binary());
	}
	return 0;
}