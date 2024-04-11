#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n;
char s[55],a[55];
void ask(char*a,int l)
{
	printf("? ");
	for(int i=0;i<l;i++)putchar(a[i]);
	putchar('\n');
	fflush(stdout);
	int k;
	scanf("%d",&k);
	while(k--)
	{
		int p;
		scanf("%d",&p);
		for(int i=0;i<l;i++)s[p+i]=a[i];
	}
}
void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)s[i]='?';
	a[0]='C',a[1]='O',ask(a,2);
	a[0]='C',a[1]='H',ask(a,2);
	a[0]='H',a[1]='C',ask(a,2);
	a[0]='H',a[1]='O',ask(a,2);
	bool f=0;
	for(int i=1;i<=n;i++)
	  if(s[i]!='?')f=1;
	if(f)
	{
		if(s[1]=='?')
		{
			int pos=1;
			while(s[pos]=='?')pos++;
			pos++;
			for(int i=1;i<=pos;i++)a[i]=s[i];
			int p=pos-2;
			while(p>=1)
			{
				a[p]=a[p+1];
				ask(a+p,pos-p+1);
				if(s[p]=='?')
				{
					for(int i=1;i<=p;i++)s[i]='O';
					break;
				}
				p--;
			}
		}
		int pos=1;
		while(pos<=n&&s[pos]!='?')a[pos]=s[pos],pos++;
		int en=n;
		while(s[en]=='?')en--;
		while(pos<=en)
		{
			for(int i=1;i<pos;i++)a[i]=s[i];
			a[pos]=a[pos-1];
			ask(a+1,pos);
			if(s[pos]=='?')
			{
				int x=pos;
				while(s[x]=='?')x++;
				while(pos!=x)a[pos]=s[pos]=s[x],pos++;
			}
			while(pos<=n&&s[pos]!='?')pos++;
		}
		while(pos<=n)
		{
			for(int i=1;i<pos;i++)a[i]=s[i];
			a[pos]=a[pos-1];
			ask(a+1,pos);
			if(s[pos]=='?')
			{
				a[pos]='C';
				ask(a+1,pos);
				if(s[pos]=='?')s[pos]='H';
				pos++;
				while(pos<=n)s[pos]=s[pos-1],pos++;
			}
			while(pos<=n&&s[pos]!='?')pos++;
		}
	}
	else
	{
		a[0]=a[1]=a[2]='C';
		ask(a,3);
		a[0]=a[1]=a[2]='H';
		ask(a,3);
		a[0]=a[1]=a[2]='O';
		ask(a,3);
		bool f=0;
		for(int i=1;i<=n;i++)
		  if(s[i]!='?')f=1;
		if(f)
		{
			if(s[1]=='?')
			{
				int x=1;
				while(s[x]=='?')s[x++]='O';
			}
			if(s[n]=='?')
			{
				for(int i=1;i<=n;i++)a[i]=s[i];
				int x=n;
				while(s[x]=='?')a[x--]='C';
				ask(a+1,n);
				if(s[n]=='?')
				{
					x=n;
					while(s[x]=='?')s[x--]='H';
				}
			}
		}
		else
		{
			a[2]=a[3]='C';
			ask(a,4);
		}
		f=0;
		for(int i=1;i<=n;i++)
		  if(s[i]!='?')f=1;
		if(f)
		{
			int x=1;
			while(s[x]=='?')s[x]='O',x++;
		}
		else s[1]=s[2]='O',s[3]=s[4]='H';
	}
	printf("! ");
	for(int i=1;i<=n;i++)putchar(s[i]);
	putchar('\n');
	fflush(stdout);
	int x;
	scanf("%d",&x);
}
int main()
{
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}