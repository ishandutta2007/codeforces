#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=100050;
int cnt[1<<6],sub[1<<6],mask[N];
bool Check(int m, int c)
{
	for(int i=0;i<1<<6;i++)
	{
		int a=cnt[i],b=sub[i];
		if((i&c)==c) a--;
		if((i&m)==m) b--;
		if(a<b) return 0;
	}
	return 1;
}
void Del(int m, int c)
{
	for(int i=0;i<1<<6;i++)
	{
		if((i&c)==c) cnt[i]--;
		if((i&m)==m) sub[i]--;
	}
}
int main()
{
	string s;
	cin >> s;
	int n=s.size(),m;
	for(int i=0;i<n;i++) cnt[1<<(s[i]-'a')]++;
	for(int j=0;j<6;j++) for(int i=0;i<1<<6;i++) if((i>>j)&1) cnt[i]+=cnt[i^(1<<j)];
	scanf("%i",&m);
	while(m--)
	{
		int id;char c[7];
		scanf("%i %s",&id,c);
		int h=strlen(c);
		for(int i=0;i<h;i++) mask[id]|=1<<(c[i]-'a');
	}
	for(int i=1;i<=n;i++){ if(!mask[i]) mask[i]=63;sub[mask[i]]++;}
	for(int j=0;j<6;j++) for(int i=0;i<1<<6;i++) if((i>>j)&1) sub[i]+=sub[i^(1<<j)];
	string sol;
	for(int i=1;i<=n;i++)
	{
		//for(int j=0;j<6;j++) printf("%i ",cnt[1<<j]);
		for(int j=0;j<6;j++)
		{
			if(((mask[i]>>j)&1) && cnt[1<<j] && Check(mask[i],1<<j))
			{
				sol+='a'+j;
				Del(mask[i],1<<j);
				break;
			}
		}
		//printf("\n");
		if(sol.size()!=i) return printf("Impossible\n"),0;
	}
	cout << sol << "\n";
	return 0;
}