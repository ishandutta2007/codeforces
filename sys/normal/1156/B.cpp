#include <bits/stdc++.h>
using namespace std;
int n,num[105],cnt[105],tot;
string str;
void print(int x,int y)
{
	for(int i=1;i<=25;i+=2)
		if(i!=x)
			while(cnt[i]) printf("%c",i+'a'-1),cnt[i]--;
	while(cnt[x]) printf("%c",x+'a'-1),cnt[x]--;
	while(cnt[y]) printf("%c",y+'a'-1),cnt[y]--;
	for(int i=2;i<=26;i+=2)
		while(cnt[i]) printf("%c",i+'a'-1),cnt[i]--;
	printf("\n");
}
int main()
{
	num[0]=-1;
	scanf("%d",&n);
	while(n--)
	{
		bool odd=false,even=false;
		memset(cnt,0,sizeof(cnt));
		tot=0;
		cin>>str;
		int siz=str.size();
		for(int i=0;i<siz;i++)
			cnt[str[i]-'a'+1]++;
		for(int i=1;i<=25;i+=2)
			if(cnt[i]) odd=true;
		for(int i=2;i<=26;i+=2)
			if(cnt[i]) even=true;
		if(!odd||!even)
		{
			cout<<str<<endl;
			goto A;
		}
		for(int i=1;i<=25;i+=2)
			for(int j=2;j<=26;j+=2)
				if(abs(i-j)!=1&&cnt[i]&&cnt[j])
				{
					print(i,j);
					goto A;
				}
		printf("No answer\n"); 
		A:;
	}
	return 0;
}