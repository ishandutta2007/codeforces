#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
bool ok[150];
void work()
{
	memset(ok,0,sizeof(ok));
	string s;
	cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++)
	{
		int v=i;
		while(v<n-1&&s[i]==s[v+1]) v++;
//		cout<<v<<endl;
		if((v-i+1)%2==1) ok[s[i]]=1;
		i=v;
	}
	for(int i='a';i<='z';i++)
	{
		if(ok[i]) printf("%c",i);
	}
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