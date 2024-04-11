#include <iostream>

int l[101000], r[101000];
int n;
int tl=0;
int tr=0;

int iabs(int x)
{
	if(x<0) return -x;
	return x;
}

int main()
{
	std::cin >> n;
	for(int i=0;i<n;i++)
	{
		std::cin >> l[i] >> r[i];
		tl+=l[i];
		tr+=r[i];
	}
	int b=iabs(tl-tr);
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int nl=tl-l[i]+r[i];
		int nr=tr-r[i]+l[i];
		int nb=iabs(nl-nr);
		if(nb>b)
		{
			ans=i+1;
			b=nb;
		}
	}
	std::cout << ans << std::endl;
}