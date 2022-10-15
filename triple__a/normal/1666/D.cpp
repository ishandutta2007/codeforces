#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
string s,t;
int cnt[2][26];
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		cin>>s>>t;
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<(int)s.size();i++) cnt[0][s[i]-'A']++;
		for(int i=0;i<(int)t.size();i++) cnt[1][t[i]-'A']++;
		bool f=true;
		for(int i=0;i<26;i++) if(cnt[0][i]<cnt[1][i]) f=false;
		if(f)
		{
			string tmp="";
			for(int i=0;i<(int)s.size();i++)
			{
				if(cnt[0][s[i]-'A']==cnt[1][s[i]-'A']) tmp+=s[i];
				else cnt[0][s[i]-'A']--;
			}
			if(tmp!=t) f=false;
		}
		if(f) puts("YES"); else puts("NO");
	}
	return 0;
}