#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[27]={0},b[27]={0},coun=0;
	string s1;
	string s2;
	cin>>s1>>s2;
	if(s1.size()!=s2.size()) cout<<"NO";
	else
	{
		for(int i=0;i<s1.size();i++)
		{
			a[s1[i]-'a']++;
			b[s2[i]-'a']++;
			if(s1[i]!=s2[i]) coun++;
 		}
		for(int i=0;i<27;i++) {
			
		if(a[i]!=b[i]) {
			cout<<"NO";
			return 0;
		}
		}
		if(coun==1 ||coun>2) cout<<"NO";
		else cout<<"YES";
	}
}