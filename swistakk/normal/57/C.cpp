#include <iostream>
#define M 1000000007
#define uint long long int
using namespace std;
uint spot(uint a, uint b)
{
	uint tmp=a;
	uint akt=1;
	while(b)
	{
		if(b%2==1)
		{
			akt*=tmp;
			akt%=M;
		}
		tmp*=tmp;
		tmp%=M;
		b/=2;
	}
	return akt;
}
uint inv(uint a)
{
	return spot(a, M-2);
}
int main()
{
	uint n;
	cin>>n;
	uint wynik=1;
	uint sil=1;
	for(int i=1; i<=2*n-1; i++)
	{
		sil=i*sil%M;
		if(i==n-1 || i==n)
		{
			wynik*=inv(sil);
			wynik%=M;
		}
	}
	wynik*=sil;
	wynik%=M;
	cout<<(2*wynik-n+M)%M<<endl;
	//system("pause");
	return 0;
}