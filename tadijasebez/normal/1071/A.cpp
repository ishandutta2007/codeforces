#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    int a,b,i,j;
    scanf("%i %i",&a,&b);
    int sum=0;
    for(i=1;sum<=a+b;i++)
	{
		if(sum+i<=a+b) sum+=i;
		else break;
	}
	vector<int> fir;
	vector<int> sec;
	for(j=i-1;j>=1;j--)
	{
		if(a>=j) a-=j,fir.pb(j);
		else sec.pb(j);
	}
	printf("%i\n",fir.size());
	for(i:fir) printf("%i ",i);printf("\n");
	printf("%i\n",sec.size());
	for(i:sec) printf("%i ",i);printf("\n");
	return 0;
}