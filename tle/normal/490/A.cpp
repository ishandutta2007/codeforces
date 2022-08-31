//zzq
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>
using namespace std;
set<int> s[4];
int main()
{
	int n,r;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>r;
		s[r].insert(i);
	}
	int size=min(min(s[1].size(),s[2].size()),s[3].size());
	set<int>::iterator sr[4];
	for(int i=1;i<=3;i++) sr[i]=s[i].begin();
	cout<<size<<"\n";
	for(int i=1;i<=size;i++)
	{
		cout<<*sr[1]<<" "<<*sr[2]<<" "<<*sr[3]<<"\n";
		for(int j=1;j<=3;j++) sr[j]++;
	}
	return 0;
}