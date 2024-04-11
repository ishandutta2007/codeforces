#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T;
	cin>>T;
	int X=300;
	while(T--)
	{
		int n=read();
		int t1=X*(X+1)/2,t=n/t1,tmp=n-t1*t;
		cout<<"133";
		for(int i=1;i<=tmp;i++) cout<<"7";
		for(int i=1;i<X;i++) cout<<"3";
		for(int i=1;i<=t;i++) cout<<"7";
		cout<<"\n";
	}
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}