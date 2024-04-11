#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Data
{
	int num;
	int last;
	int id;
}a[100005];
char s[2000005],t[2000005];
int n,tot,st[100005];
int st1[100005],st2[100005],num1,num2;
bool cmp(Data a,Data b)
{
	return a.num<b.num||(a.num==b.num&&a.last<b.last);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",t+1);
		int len=(int)strlen(t+1);
		st[i]=tot+1;
		for(int j=1;j<=len+1;j++)
		  s[++tot]=t[j];
		a[i].id=i;
		for(int j=1;j<=len;j++)
		{
			if(t[j]=='a'||t[j]=='e'||t[j]=='i'||t[j]=='o'||t[j]=='u')
			{
				a[i].num++;
				a[i].last=t[j];
			}
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(a[i].last==a[i+1].last&&a[i].num==a[i+1].num)
		{
			st2[++num2]=i;
			st2[++num2]=i+1;
			i++;
		}
		else st1[++num1]=i;
	}
	for(int i=1;i<=num1;i++)
	{
		if(a[st1[i]].num==a[st1[i+1]].num)i++;
		else st1[i]=1000000000;
	}
	sort(st1+1,st1+num1+1);
	while(st1[num1]==1000000000)num1--;
	if(num1>num2)printf("%d\n",num2/2);
	else
	{
		printf("%d\n",(num1+num2)/4);
		while(num1<num2)
		{
			st1[++num1]=st2[num2--];
			st1[++num1]=st2[num2--];
		}
	}
	for(int i=1;i+1<=num2;i+=2)
	{
		printf("%s %s\n",s+st[a[st1[i]].id],s+st[a[st2[i]].id]);
		printf("%s %s\n",s+st[a[st1[i+1]].id],s+st[a[st2[i+1]].id]);
	}
	return 0;
}