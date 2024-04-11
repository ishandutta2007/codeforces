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
#define N 100005
char a[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	scanf("%s",a+1);
	int n=strlen(a+1);
	vector<int> v;
	for(int i=1;i<=n;i++)
	{
//		cout<<a[i]<<endl;
		if(a[i]=='0')
		{
			if(!v.empty()) v.pop_back();
		}
		else v.pb(i);
//		int vs=v.size();
//		for(int i=0;i<vs;i++) cout<<v[i]<<" ";
//		cout<<"\n";
	}
	int vs=v.size();
	for(int i=0;i<vs;i++) a[v[i]]='0';
	cout<<(a+1)<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}