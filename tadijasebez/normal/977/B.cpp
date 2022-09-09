#include <stdio.h>
#include <cstring>
#include <map>
using namespace std;
#define mp make_pair
const int N=100050;
//int cnt[N];
char s[N];
map<pair<char,char> ,int> cnt;
map<pair<char,char> ,int>::iterator it;
int main()
{
	int n,i;
	scanf("%i",&n);
	scanf("%s",s+1);
	for(i=1;i<n;i++) cnt[mp(s[i],s[i+1])]++;//cnt[(s[i]-'A'+1)+(s[i+1]-'A'+1)*26]++;
	int sol=0;
	for(it=cnt.begin();it!=cnt.end();it++) if(sol<it->second) sol=it->second;
	for(it=cnt.begin();it!=cnt.end();it++)
	{
		if(sol==it->second)
		{
			printf("%c%c\n",it->first.first,it->first.second);
			return 0;
		}
	}
	//for(i=1;i<N;i++) if(cnt[i]>cnt[sol]) sol=i;
	//printf("%c%c\n",'A'+mod(sol%26-1),'A'+mod(sol-(mod(sol%26-1))/26-1));
	return 0;
}