#include <bits/stdc++.h>
using namespace std;
string m[200050];
map<string,bool> u;
int main()
{
	int q,n,i;
	scanf("%i",&q);n=q;
	while(q--)cin>>m[q];
	for(i=0;i<n;i++)if(!u[m[i]])cout<<m[i]<<"\n",u[m[i]]=true;
	return 0;
}