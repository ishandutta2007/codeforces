#include<bits/stdc++.h>
using namespace std;
long long t;
string a,b,s;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	cin>>b;
	s+=b;
	for(int i=1;i<t;i++)
	{
		int len1=s.length();
		cin>>b;
		int len2=b.length();
		int flag=1;
		for(int i=len2-1;i>=0;i--)
		{
			if(b[i]==s[len1-1])
			{
				int l=len1-1,r=i;
				while(s[l]==b[r])
				{
					l--,r--;
					if(r==-1)
						break;
				}
				if(r==-1)
				{
					for(int j=i+1;j<len2;j++)
						s+=b[j];
					flag=0;
					break;
				}
			}
		}
		if(flag)
			s+=b;
	}
	cout<<s<<endl;
	return 0;
}