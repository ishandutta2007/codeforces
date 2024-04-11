#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
vector<int> v[30];
void work()
{
	string s,t;
	cin>>s>>t;
	int n=s.length(),m=t.length();
	for(int i=0;i<26;i++) v[i].clear();
	for(int i=0;i<n;i++)
	{
		v[s[i]-'a'].pb(i);
	}
	int ans=0,cur=0;
	for(int i=0;i<m;i++)
	{
		if(v[t[i]-'a'].size()==0)
		{
			cout<<"-1\n";
			return ;
		}
//		printf("%d %d %d\n",i,ans,cur);
//		printf("**%d %d\n",v[t[i]-'a'].back(),cur);
		if(v[t[i]-'a'].back()<cur)
		{
//			printf("***%d\n",v[t[i]-'a'][0]);
			ans++,cur=v[t[i]-'a'][0]+1;
			continue;
		}
		int l=0,r=v[t[i]-'a'].size()-1,tmp;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(v[t[i]-'a'][mid]>=cur) tmp=mid,r=mid-1;
			else l=mid+1;
		}
		cur=v[t[i]-'a'][tmp]+1;
	}
	cout<<ans+1<<endl;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T=read();
	while(T--) work();
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}