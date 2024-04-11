#include<bits/stdc++.h>
using namespace std;
char a[1005][8];
bool f;
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,i,j;
	cin>>n;
	for(i=1;i<=n;i++) 
	{
		scanf("%s",a[i]);
		if(a[i][0]=='O'&&a[i][1]=='O'&&!f) a[i][0]=a[i][1]='+',f=true;
		if(a[i][3]=='O'&&a[i][4]=='O'&&!f) a[i][3]=a[i][4]='+',f=true;
	}
	if(f)
	{
		cout<<"YES\n";
		for(i=1;i<=n;i++) printf("%s\n",a[i]);
	}
	else cout<<"NO\n";
	return 0;
}