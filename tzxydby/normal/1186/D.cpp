#include<bits/stdc++.h>
using namespace std;
const int N=100005;
double a[N];
int b[N];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	double sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>=0)
			b[i]=(int)a[i]+1;
		else
			b[i]=(int)a[i];
		if(a[i]==(double)b[i]||a[i]==(double)(b[i]-1))
			b[i]=(int)a[i];
		sum+=b[i]; 
	} 
	int i=1;
	while(sum>0)
	{
		if(a[i]==(double)b[i]||a[i]==(double)(b[i]-1))
		{
			i++;
			continue;
		}
		b[i]--;
		sum--;
		i++;
	}
	for(int i=1;i<=n;i++)
		cout<<b[i]<<endl; 
	return 0;
}