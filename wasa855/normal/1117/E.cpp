#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 20005
int a[N],b[N],c[N];
char ans[N];
signed main()
{
#ifdef __LOCAL__
//	freopen("in.txt","r",stdin);
#endif
	string s;
	cin>>s;
	int n=s.length();
	string ra,rb,rc;
	for(int i=0;i<n;i++)
	{
		a[i]=i/26/26,b[i]=i/26%26,c[i]=i%26;
	}
	printf("? ");
	for(int i=0;i<n;i++) printf("%c",a[i]+'a');
	cout<<"\n"; fflush(stdout);
	cin>>ra;
	printf("? ");
	for(int i=0;i<n;i++) printf("%c",b[i]+'a');
	cout<<"\n"; fflush(stdout);
	cin>>rb;
	printf("? ");
	for(int i=0;i<n;i++) printf("%c",c[i]+'a');
	cout<<"\n"; fflush(stdout);
	cin>>rc;
	for(int i=0;i<n;i++)
	{
		int bel=(ra[i]-'a')*26*26+(rb[i]-'a')*26+rc[i]-'a';
		ans[bel]=s[i];
	}
	printf("! ");
	for(int i=0;i<n;i++) printf("%c",ans[i]);
	cout<<"\n", fflush(stdout);
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}