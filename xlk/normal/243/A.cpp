#include<stdio.h>
#include<set>
using namespace std;
int b[2000020],x,n,z;
set<int>s,t;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		t.clear();
		for(int j:s)
			t.insert(j|x);
		t.insert(x);
		s.swap(t);
		for(int j:s)
			b[j]=1;
	}
	for(int i=0;i<1<<20;i++)
		z+=b[i];
	printf("%d",z);
}