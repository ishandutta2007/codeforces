#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int n;
bool read[100001];
int main()
{
	cin>>n;
	int total=0,now=0;
	for(int i=1;i<=n;i++) cin>>read[i];
	bool f=0;
	while(now<=n)
	{
		int readed=0,tothis=-1,untilthis=-1;
		for(int i=now+1;i<=n;i++)
		{	
			if(read[i]) {tothis=i; break;}
		}
		if(tothis==-1) break;
		for(int i=tothis;i<=n;i++)
		{
			if(!read[i]) {untilthis=i-1; break;}
		}
		if(untilthis==-1) untilthis=n;
		total+=untilthis-tothis+1+f;
		now=untilthis;
		f=1;
	}
	cout<<total<<"\n";
	return 0;
}