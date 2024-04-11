#include <iostream>
#define M a
#define uint long long int
using namespace std;
long long int b[100];
long long int c[100];
long long int m[60][60][2];
long long int akt[60][60][2];
uint a, l, r, ile;
uint zm(uint s)
{
    return r/s-(l-1)/s;
}
uint najw()
{
    if(ile==1)
    {
        return r;
    }
    uint skok=(r-l)/(ile-1)+100;
    while(zm(skok)<ile)
    {
        uint lol=r/skok;
        skok=r/(lol+1);
    }
    return skok;
}
// long long int bla[60][60];
int main()
{
	uint z, k, n, pot, s, t;
	long long int sum;
	 // cin>>z;
	 z=1;
	 
	 cin>>a>>l>>r>>ile;
	 
	for(int y=1; y<=z; y++)
	{
        for(int i=0; i<=55; i++)
        {
                for(int j=0; j<=55; j++)
                {
                        for(int cos=0; cos<=1; cos++)
                        {
                                m[i][j][cos]=akt[i][j][cos]=0;
                        }
                }
        }
		// cin>>k;
		k=2;
		for(int i=1; i<=k; i++)
		{
			// cin>>b[i];
			b[i]=1;
		}
		for(int i=1; i<=k; i++)
		{
			// cin>>c[i];
			c[i]=1;
			m[0][i-1][0]=c[i];
			akt[i-1][i-1][0]=1;
		}
		for(int i=1; i<=k-1; i++)
		{
			m[i][i-1][0]=1;
		}
		// cin>>n;
		n=najw();
		if(n<=k)
		{
			cout<<b[n]%a<<endl;
			continue;
		}
		pot=n-k;
		s=t=0;
		while(pot>0)
		{
			if(pot%2==0)
			{
			}
			if(pot%2==1)
			{
				// akt[60][60][s]*m[60][60][t]->akt[60][60][1-s]
				for(int d=0; d<k; d++)
				{
					for(int e=0; e<k; e++)
					{
						akt[d][e][1-s]=0;
						for(int f=0; f<k; f++)
						{
							akt[d][e][1-s]=(akt[d][e][1-s]+akt[d][f][s]*m[f][e][t])%M;
						}
					}
				}
				s=1-s;
			}
			for(int d=0; d<k; d++)
			{
				for(int e=0; e<k; e++)
				{
					m[d][e][1-t]=0;
					for(int f=0; f<k; f++)
					{
						m[d][e][1-t]=(m[d][e][1-t]+m[d][f][t]*m[f][e][t])%M;
					}
					// cout<<m[d][e][1-t]<<" ";
				}
				// cout<<endl;
			}
			t=1-t;
			pot=pot/2;
		}
		sum=0;
		/* cout<<endl;
		for(int j=0; j<k; j++)
		{
			for(int l=0; l<k; l++)
			{
				cout<<akt[j][l][s]<<" ";
			}
			cout<<endl;
		} */
		for(int j=0; j<k; j++)
		{
			sum=(sum+akt[0][j][s]*b[k-j])%M;
		}
		cout<<sum%M<<endl;
	}
	// system("pause");
	return 0;
}