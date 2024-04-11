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
int cnt[15];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T=read();
	while(T--)
	{
		string s;
		cin>>s;
		for(int i=0;i<=9;i++) cnt[i]=0;
		int sum=0;
		for(int i=0;i<s.length();i++) cnt[s[i]-'0']++,sum+=s[i]-'0';
		bool zer=0,eve=0;
		if(cnt[0]) zer=1;
		if(cnt[0]>=2) eve=1;
		for(int i=1;i<=9;i++)
		{
			if(i%2==0) if(cnt[i]) eve=1;
		}
		if(zer&&eve&&sum%3==0) cout<<"red\n";
		else cout<<"cyan\n";
	}
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}