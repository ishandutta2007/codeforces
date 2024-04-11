#include <bits/stdc++.h>
using namespace std;
string str; 
int cnt;
bool tag;
int main()
{
	cin>>str;
	int siz=str.size();
	for(int i=0;i<siz;i++)
	{
		if(str[i]=='0')
		{
			if(!tag)
			{
				printf("1 1\n");
				tag=true;
			}
			else
			{
				printf("3 1\n");
				tag=false;
			}
		}
		else
		{
			cnt++;
			printf("%d 3\n",cnt);
			if(cnt==4) cnt=0;
		}
	}
	return 0;
}