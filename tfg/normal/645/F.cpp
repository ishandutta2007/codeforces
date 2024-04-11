#include <bits/stdc++.h>

using namespace std;

int n, k, q;

typedef long long ll;

const int tam=int(1e6)+2;
const ll MOD=int(1e9)+7;

ll get_inv(ll x)
{
	ll base = x;
	int e = MOD-2;
	ll num = 1;
	while(e)
	{
		if(e&1)
			num=(num*base)%MOD;
		base=(base*base)%MOD;
		e=e>>1;
	}
	return num;
}

ll phi[tam];
ll fat[tam];
ll ifat[tam];
vector<int> divs[tam];

ll comb(int x)
{
	if(x<k) return 0;
	return (((fat[x]*ifat[k])%MOD)*ifat[x-k])%MOD;
}

ll sum=0;

int num_d[tam];

int main()
{
	cin >> n >> k >> q;
	for(int i=1;i<tam;i++)
		phi[i]=i;
	fat[0]=ifat[0]=1;
	for(int i=1;i<tam;i++)
	{
		fat[i]=(fat[i-1]*ll(i))%MOD;
		ifat[i]=get_inv(fat[i]);
		divs[i].push_back(i);
		for(int j=i+i;j<tam;j+=i)
		{
			phi[j]-=phi[i];
			divs[j].push_back(i);
		}
		//cout << "phi of " << i << "is " << phi[i] << endl;
	}
	for(int i=0;i<n+q;i++)
	{
		int temp;cin >> temp;
		//printf("adding %i\n",temp);
		for(int j=0;j<divs[temp].size();j++)
		{
			int now=divs[temp][j];
			ll last_comb = (comb(num_d[now])*phi[now])%MOD;
			num_d[now]++;
			ll next_comb = (comb(num_d[now])*phi[now])%MOD;
			sum=(sum-last_comb+next_comb+MOD)%MOD;
			//printf("on %i, last_comb %lli, next_comb %lli, num_d %i, sum %lli\n",now,last_comb,next_comb,num_d[now],sum);
		}
		if(i>=n)
			cout << sum << endl;
	}

}