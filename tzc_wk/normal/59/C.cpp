#include <bits/stdc++.h>
using namespace std;
string s;
int k,flag[26],cnt1=0,cnt2=0;
inline void die(){
	cout<<"IMPOSSIBLE\n";
	exit(0);
}
int main(){
	cin>>k>>s;
	int i=0,j=s.size()-1;
	for(i=0,j=s.size()-1;i<=j;i++,j--){
		if(s[i]!=s[j]&&s[i]!='?'&&s[j]!='?')	die();
		if(s[i]==s[j]&&s[i]!='?')	flag[s[i]-'a']++;
		else if(s[i]=='?'&&s[j]!='?')
			s[i]=s[j],flag[s[j]-'a']++;
		else if(s[i]!='?'&&s[j]=='?')	
			s[j]=s[i],flag[s[i]-'a']++;
		else	cnt1++;
	}
	for(int i=0;i<k;i++)	if(flag[i]==0)	cnt2++;
	int aa=cnt1-cnt2;
	if(aa<0)	die();
	for(i=0,j=s.size()-1;i<=j&&aa;i++,j--)
		if(s[i]==s[j]&&s[i]=='?')
		{
			s[j]='a';
			s[i]=s[j];
			aa--;
		}	
	for(i=0,j=s.size()-1;i<=j;i++,j--)
		if(s[i]==s[j]&&s[i]=='?')
			for(int z=0;z<k;z++)
				if(flag[z]==0)
				{
					s[j]='a'+z;
					s[i]=s[j];
					flag[z]++;
					break;
				}
	cout<<s<<endl;
}