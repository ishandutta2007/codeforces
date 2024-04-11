#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,s=0,ans=0,i;
	char x;
	cin>>n;
	while(scanf("%c",&x)!=EOF)
	{
		if(x=='B') s++;
		if(x=='W'&&s) a[++ans]=s,s=0;
	} 
	if(s) a[++ans]=s;
	cout<<ans<<endl;
	for(i=1;i<=ans;i++) cout<<a[i]<<" ";
	return 0;
}