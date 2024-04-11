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
typedef pair<int,int> pii;
int query(string x)
{
	cout<<x<<endl;
	fflush(stdout);
	int xx=read();
	if(xx<=0) exit(0);
	return xx;
}
signed main()
{
#ifdef __LOCAL__
//	freopen("in.txt","r",stdin);
#endif
	string s;
	for(int i=1;i<=300;i++) s+='a';
	int aa=300-query(s);
	s.clear();
	for(int i=1;i<=300;i++) s+='b';
	int bb=300-query(s);
	int len=aa+bb;
	s.clear();
	for(int i=1;i<=len;i++) s+='a';
	int res=bb;
	for(int i=0;i<len-1;i++)
	{
		s[i]='b';
		if(query(s)>res) s[i]='a';
		else res--;
	}
	if(res) s[len-1]='b';
	query(s);
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}