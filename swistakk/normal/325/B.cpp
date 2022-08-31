#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#define uint long long int
using namespace std;
vector<uint> wynik;
int main()
{
	uint n;
	cin>>n;
	int ile = 0;
	uint pot = 1;
	if (n == 1)
	{
		cout<<"2"<<endl;
		return 0;
	}
	for (; pot <= n + 1; pot *= 2)
	{
		uint k = pot - 1;
		//cout<<k<<" hoh"<<endl;
		uint kl = 1, kp = 1000 * 1000 * 1000, aktc, faj;
		kp *= kp;
		while (kl <= kp)
		{
			aktc = (kl + kp) / 2;
			/* if (k == 3)
			{
				cout<<aktc<<endl;
			} */
			if (pow(double(3 * n), 0.5) < aktc || 2 * n / aktc < 2 * k - 2)
			{
				kp = aktc - 1;
				continue;
			}
			
			uint rhs = aktc * aktc + (2 * k - 1) * aktc;
			//cout<<aktc<<" "<<rhs<<endl;
			if (2 * n == rhs)
			{
				if (aktc % 2 == 0)
				{
					break;
				}
				ile = 1;
				//cout<<pot<<" "<<aktc<<endl;
				//wynik.push_back(pot * aktc);
				cout<<pot * aktc<<endl;
				break;
			}
			if (2 * n > rhs)
			{
				kl = aktc + 1;
			}
			else
			{
				kp = aktc - 1;
			}
		}
	}
	sort(wynik.begin(), wynik.end());
	if (ile == 0)
	{
		cout<<"-1"<<endl;
	}
	else
	{
		for (int i = 0; i < wynik.size(); i++)
		{
			//cout<<wynik[i]<<endl;
		}
	}
	return 0;
}