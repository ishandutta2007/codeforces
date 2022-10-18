#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int n,k;
	cin>>n>>k;
	cout<<(6*(n-1)+5)*k<<endl;
	for(int i=0;i<n;i++)
	{
		printf("%d %d %d %d\n",(i*6+1)*k,(i*6+3)*k,(i*6+4)*k,(i*6+5)*k);
	}
#ifndef ONLINE_JUDGE
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}