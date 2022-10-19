#include<bits/stdc++.h>
using namespace std;
int xx,yy;
char s[100001];
int num;
int ans;
int main()
{
	scanf("%s",s+1);
	int len=strlen(s+1);
	int q=(s[2]-'0')+(s[1]-'0')*10;
	int r=(s[5]-'0')+(s[4]-'0')*10;
	int it=(s[2]-'0')*10+s[1]-'0';
//	if(1){cout<<q<<" "<<r<<" "<<it<<endl;}
	if(it==r) {puts("0");return 0;}
	while(it>=60)
	{
		q++;if(q==24)q=0;it=(q%10)*10+q/10;
//		cout<<it<<endl;
		ans+=60-r;
		r=0;
	}
	if(it<r) {q++;ans+=(60-r);r=0;if(q==24) q=0;it=(q%10)*10+q/10;}
//	cout<<q<<" "<<r<<endl;
	while(it>=60)
	{
		q++;if(q==24)q=0;it=(q%10)*10+q/10;
		ans+=60-r;
		r=0;
	}
	if(it<60&&r<=it) ans+=it-r;
	cout<<ans<<endl;
}