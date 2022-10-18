#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define INF 1e18
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int a;
	cin>>a;
	int l=a-(int)INF%a*9%a*9%a;
    int r=l+(int)INF-1;
    ll al=l,ar=r;
    cout<<al<<" "<<ar<<endl;
#ifndef ONLINE_JUDGE
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}