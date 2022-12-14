#include<cstdio>
#include<iostream>

using namespace std;

long long get(long long num,long long den)
{
	if(num==0) return 0;
	if(den==1) return num;
	if(num>den) return get(num%den,den)+(num/den);
	long long nden=den%num;
	if(nden==0) nden+=num;
	return get(num,nden)+((den-nden)/num);
}

int main()
{
	long long num,den;
	cin>>num>>den;
	cout<<get(num,den)<<"\n";
	return 0;
}