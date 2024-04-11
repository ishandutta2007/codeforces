#include<bits/stdc++.h>
using namespace std;
int x[3],y[3],ans;
int main()
{
	for (int i=0;i<3;i++) cin>>x[i]>>y[i];
	if ((x[0]==x[1] && x[1]==x[2]) || (y[0]==y[1] && y[1]==y[2])) cout<<1;
	else
	{
		for (int i=0;i<3;i++)
			for (int j=0;j<3;j++)
				for (int k=0;k<3;k++)
					if (i!=j && j!=k && i!=k)
						if ((x[i]==x[j] && (y[k]<=min(y[i],y[j]) || y[k]>=max(y[i],y[j]))) || (y[i]==y[j] && (x[k]<=min(x[i],x[j]) || x[k]>=max(x[i],x[j]))))
							return cout<<2,0;
		cout<<3;
	}
}