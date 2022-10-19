#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
char s[N];
string ans1,ans2;
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	int l=1,r=n;
	while(ans1.size()+ans2.size()<n/2)
	{
		if(s[l]==s[r])
		{
			ans1+=s[l];
			if(l!=r)
				ans2+=s[l];
			l++;
			r--;
		}
		else
		{
			if(l+1<=r-1&&s[l+1]==s[r-1])
			{
				ans1+=s[l+1];
				if(l+1!=r-1)
					ans2+=s[l+1];
				l+=2;
				r-=2;
			}
			else if(s[l]==s[r-1])
			{
				ans1+=s[l];
				if(l!=r-1)
					ans2+=s[l];
				l++;
				r-=2;
			}
			else if(s[l+1]==s[r])
			{
				ans1+=s[l+1];
				if(l+1!=r)
					ans2+=s[l+1]; 
				l+=2;
				r--; 
			}
		}
	}
	for(int i=0;i<ans1.size();i++)
		printf("%c",ans1[i]);
	for(int i=ans2.size()-1;i>=0;i--)
		printf("%c",ans2[i]);
	return 0;
}