#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;
char a[1050],b[1050];
int min(int a, int b){ return a>b?b:a;}
vector<int> vec,bec;
int main()
{
	int n,m,i,j,k,sol,in;
	scanf("%i %i",&n,&m);
	scanf("%s",&a);
	scanf("%s",&b);
	sol=n+1;
	for(i=0;i<m-n+1;i++)
	{
		k=0;
		vec.clear();
		in=-1;
		for(j=0;j<n;j++)
		{
			if(a[j]!=b[i+j]) k++,vec.push_back(j+1);
		}
		if(sol>k)
		{
			sol=k;
			bec.clear();
			for(j=0;j<vec.size();j++) bec.push_back(vec[j]);
		}
	}
	printf("%i\n",sol);
	for(i=0;i<bec.size();i++) printf("%i ",bec[i]);
	return 0;
}