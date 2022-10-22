#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long
 
#define RPT(i,x,y) for (REG int i=(x);i<(y);i++)
#define DRPT(i,x,y) for (REG int i=(x);i>(y);i--)
#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;
 
#define MAXN 2010000
#define MAXM 2010000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5
 
#define _ 0
using namespace std;
char s[MAXN];
char str[MAXN];
int fail[MAXN];
 
void make_fail(char *s)
{
	for (int i=1, j=0;s[i];i++)
	{
    	while (j && s[i]!=s[j])
			j=fail[j - 1];
    	if (s[i]==s[j])
			fail[i]=++j;
    	else 
			fail[i]=0;
	}
}
 
int len,l;
int search(char *str,char *s)
{
	int ans=0;
	for (int i=0,j=0;str[i];i++)
	{
    	while (j && (str[i]!=s[j] || j>=len))
			j=fail[j-1];
		if (i==l-1)
			return j;
    	if (str[i]==s[j] && !s[++j])
			ans++;
	}
	return -1;
}
 
void get1()
{
	make_fail(str);
	int ll=search(s,str);
	
	//WRT(ll);
	if (ll==0)
	{
		if (s[l-1]==str[0])
			ll=1;
		else
			ll=0;
	}
	else
		ll++;
	for (int i=ll;i<len;i++)
		s[l+i-ll]=str[i];
	l=l+len-ll;
	s[l]='\0';
}
 
void get2()
{
	int ll;
	for (int i=min(l,len);i>=0;i--)
	{
		bool f=true;
		RPT(j,0,i)
			if (str[j]!=s[l-i+j])
			{
				f=false;
				break;
			}
		if (f)
		{
			ll=i;
			break;
		}
	}
	for (int i=ll;i<len;i++)
		s[l+i-ll]=str[i];
	l=l+len-ll;
	s[l]='\0';
}
int n;
int main()
{
	cin>>n;
	RPT(i,0,n)
	{
		scanf("%s",str);
		len=strlen(str);
		if (len>1100)
			get1();
		else
			get2();
	}
	cout<<s;
	return 0;
}