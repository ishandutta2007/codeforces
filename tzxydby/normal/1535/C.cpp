#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N],t[2][2];
char s[N];
long long ans;
void sol()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='?')
			a[i]=2;
		else
			a[i]=s[i]-'0';
	}
	ans=t[0][0]=t[0][1]=t[1][0]=t[1][1]=0;
	if(a[1]<=1)
		t[a[1]][1]++;
	for(int l=1,r=1;l<=n;l++)
	{
		while(r<n)
		{
			r++;
			if(r<=n&&a[r]<=1)
				t[a[r]][r&1]++;
			if((t[0][0]&&t[1][0])||(t[0][1]&&t[1][1])||(t[0][0]&&t[0][1])||(t[1][0]&&t[1][1]))
			{
				if(r<=n&&a[r]<=1)
					t[a[r]][r&1]--;
				r--;
				break;
			}
		}
		ans+=r-l+1;
		if(a[l]<=1)
			t[a[l]][l&1]--;
	}
	printf("%lld\n",ans);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();	
	return 0;
}