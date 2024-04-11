#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back

LL a, b;//sum, xor
int full, half;
bool mov;

int main()
{
	ios_base::sync_with_stdio(0);
	cin>> a >> b;
	int ind=0;
	while(a>>ind>0 || b>>ind>0)
		ind++;
	ind--;
	if(a>>ind==0 && b>>ind>0)
	{
		cout<< "0\n";
		return 0;
	}
//	printf("%d\n", ind);
	while(ind>=0)
	{
		if((a>>ind)%2==1 && (b>>ind)%2==1)
		{
			if(mov)
			{
				cout<< "0\n";
				return 0;
			}
			half++;
		}
		if((a>>ind)%2==1 && (b>>ind)%2==0)
		{
			if(mov)
				full++;
			mov=1;
		}
		if((a>>ind)%2==0 && (b>>ind)%2==1)
		{
			if(!mov)
			{
				cout<< "0\n";
				return 0;
			}
			half++;
		}
		if((a>>ind)%2==0 && (b>>ind)%2==0)
		{
			if(mov)
			{
				full++;
				mov=0;
			}
		}
		ind--;
	}
	if(mov)
	{
		cout<< "0\n";
		return 0;
	}
	//printf("%d %d\n", half, full);
	LL r=1;
	for(int i=0; i<half; i++)
		r*=2;
	if(full==0)
		r-=2;
	cout<< r << '\n';
	return 0;
}