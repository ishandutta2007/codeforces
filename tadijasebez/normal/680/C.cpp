#include <stdio.h>
#include <vector>
using namespace std;
vector<int> Prime,Divisor;
bool sieve[50];
void FindPrimes()
{
	int i,j;
	for(i=2;i<50;i++)
	{
		if(!sieve[i])
		{
			Prime.push_back(i);
			for(j=i;j<50;j+=i) sieve[j]=1;
		}
	}
}
int Ask(int x)
{
	if(x>100) return 0;
	printf("%i\n",x);
	fflush(stdout);
	char ch[5];
	scanf("%s",&ch);
	return ch[0]=='y';
}
int main()
{
	FindPrimes();
	int i;
	for(i=0;i<Prime.size();i++)
	{
		if(Ask(Prime[i])) Divisor.push_back(Prime[i]);
	}
	if(Divisor.empty()) printf("prime\n"),fflush(stdout);
	else if(Divisor.size()==1)
	{
		if(Ask(Divisor[0]*Divisor[0])) printf("composite\n"),fflush(stdout);
		else printf("prime\n"),fflush(stdout);
	}
	else printf("composite\n"),fflush(stdout);
	return 0;
}