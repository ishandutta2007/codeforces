#include <bits/stdc++.h>
using namespace std;
const int Maxn=10005;
int bel[Maxn],n;
string str,res,print;
char ans[Maxn];
int main()
{
	cin>>res;
	int siz=res.size();
	print="? ";
	char ch='a';
	for(int i=0;i<siz;i++)
	{
		print+=ch;
		if((i+1)%(26*26)==0) ch++;
	}
	cout<<print<<endl;
	cin>>str;
	for(int i=0;i<siz;i++)
		bel[i]+=(str[i]-'a')*26*26;
	ch='a';
	print="? ";
	for(int i=0;i<siz;i++)
	{
		print+=ch;
		if((i+1)%26==0) ch++;
		if(ch=='z'+1) ch='a';
	}
	cout<<print<<endl;
	cin>>str;
	for(int i=0;i<siz;i++)
		bel[i]+=(str[i]-'a')*26;
	ch='a';
	print="? ";
	for(int i=0;i<siz;i++)
	{
		print+=ch;
		ch++;
		if(ch=='z'+1) ch='a';
	}
	cout<<print<<endl;
	cin>>str;
	for(int i=0;i<siz;i++)
		bel[i]+=str[i]-'a';
	for(int i=0;i<siz;i++)
		ans[bel[i]]=res[i];
	printf("! %s",ans);
	fflush(stdout); 
	return 0;
}