#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define N 150005
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
char s[N];
void work()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	vector<int> ans;
	for(int i=1;i<=n-2;i++)
	{
		if(s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o'&&s[i+3]=='n') ans.pb(i+2),i+=2;
		else if(s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o') ans.pb(i+1),i+=2;
		else if(s[i]=='o'&&s[i+1]=='n'&&s[i+2]=='e') ans.pb(i+1),i+=2;
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
	cout<<"\n";
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T=read();
	while(T--) work();
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}
//