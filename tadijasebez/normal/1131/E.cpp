#include <bits/stdc++.h>
using namespace std;
const int N=100050;
struct str
{
	int pre[26],suf[26],mx[26],len;
	str(){}
	void Build(char s[], int n)
	{
		len=n;
		for(int i=0;i<26;i++) pre[i]=suf[i]=mx[i]=0;
		int len=0;
		for(int i=1;i<=n;i++)
		{
			if(i!=1 && s[i]==s[i-1]) len++;
			else len=1;
			mx[s[i]-'a']=max(mx[s[i]-'a'],len);
			//printf("%i %i\n",s[i]-'a',len);
		}
		for(int i=0;i<26;i++)
		{
			while(pre[i]<n && s[pre[i]+1]=='a'+i) pre[i]++;
			while(suf[i]<n && s[n-suf[i]]=='a'+i) suf[i]++;
		}
	}
} STR[N];
str operator * (str x, str y)
{
	str ans;
	ans.len=y.len*(x.len+1)+x.len;
	for(int i=0;i<26;i++)
	{
        if(y.pre[i]==y.len)
		{
			if(x.pre[i]==x.len) ans.pre[i]=ans.len;
			else ans.pre[i]=y.len*(x.pre[i]+1)+x.pre[i];
			if(x.suf[i]==x.len) ans.suf[i]=ans.len;
			else ans.suf[i]=y.len*(x.suf[i]+1)+x.suf[i];
			ans.mx[i]=y.len*(x.mx[i]+1)+x.mx[i];
		}
		else
		{
			ans.pre[i]=y.pre[i];
			ans.suf[i]=y.suf[i];
			if(x.mx[i]>0) ans.mx[i]=y.pre[i]+y.suf[i]+1;
			else ans.mx[i]=y.mx[i];
			ans.mx[i]=max(ans.mx[i],y.mx[i]);
		}
	}
	return ans;
}
char s[N];
int main()
{
    int n,len,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		len=strlen(s+1);
		STR[i].Build(s,len);
		//printf("%i %i %i\n",STR[i].mx[0],STR[i].pre[0],STR[i].suf[0]);
	}
	for(i=2;i<=n;i++)
	{
		STR[1]=STR[1]*STR[i];
		//printf("%i %i %i\n",STR[1].mx[0],STR[1].pre[0],STR[1].suf[0]);
	}
	int ans=0;
	for(i=0;i<26;i++) ans=max(ans,STR[1].mx[i]);
	printf("%i\n",ans);
	return 0;
}