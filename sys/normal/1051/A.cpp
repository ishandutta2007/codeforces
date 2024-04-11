#include <bits/stdc++.h>
using namespace std;
int T;
string str;
int cnt[5],tag[105];
char ch;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		cin>>str;
		int siz=str.size();
		memset(cnt,0,sizeof(cnt));
		memset(tag,0,sizeof(tag));
		for(int i=0;i<siz;i++)
		{
			if(str[i]<='Z'&&str[i]>='A'){tag[i]=1;cnt[1]++;}
			if(str[i]<='z'&&str[i]>='a'){tag[i]=2;cnt[2]++;}
			if(str[i]<='9'&&str[i]>='0'){tag[i]=3;cnt[3]++;}
		}
		int lt=(cnt[1]==0)+(cnt[2]==0)+(cnt[3]==0);
		if(!lt) goto PRINT;
		else
		{
			if(lt==1)
			{
				if(cnt[1]==0) ch='A';
				if(cnt[2]==0) ch='a';
				if(cnt[3]==0) ch='0';
				for(int i=0;i<siz;i++)
					if(cnt[tag[i]]!=1){str[i]=ch;goto PRINT;}
			}
			if(lt==2)
			{
				int have,no[3];
				if(cnt[1]) have=1;
				if(cnt[2]) have=2;
				if(cnt[3]) have=3;
				for(int i=0;i<siz-1;i++)
				{
					cnt[tag[i+1]]--;
					if(cnt[have])
					{
						str[i]=have!=1?'A':'a';
						str[i+1]=have!=3?'0':'a';
						goto PRINT;
					}
					cnt[tag[i]]++;
				}
			}
		}
		PRINT:cout<<str<<endl;
	}
	return 0;
}