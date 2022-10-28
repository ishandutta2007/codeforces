#include <bits/stdc++.h>
using namespace std;

int search(int* a,int l, int r,int s,long long int *cost,int n){
	int *b=(int*)malloc(n*sizeof(int));
	
	if (l==r)
	{
		
		*cost=0;
		if (l==0)
		{
			free(b);
			return l;
		}
		for (int i = 0; i < n; ++i)
		{
			 if (1LL*(i+1)*l<=1e9)
			{
				b[i]=a[i]+(i+1)*l;
			}
			else{
				b[i]=s+1;
			}
		}
		sort(b,b+n);

		for (int i = 0; i < l; ++i)
		{
			*cost+=b[i];
		}
		free(b);
		return l;
	}
	int m=(l+r)/2;
	if (r==l+1)
	{
		m++;
	}

		for (int i = 0; i < n; ++i)
		{
			if (1LL*(i+1)*m<=1e9)
			{
				b[i]=a[i]+(i+1)*m;
			}
			else{
				b[i]=s+1;
			}
		}
		sort(b,b+n);
		*cost =0;

		for (int i = 0; i < m; ++i)
		{
			*cost+=b[i];
		}

		
		free(b);
		
	if (*cost==s)
	{
		return m;
	}
	else if (*cost > s)
	{
		return search(a,l,m-1,s,cost,n);
	}
	else{
		return search(a,m,r,s,cost,n);
	}

}

int main(){

	int n,s;
	cin>>n>>s;
	int a[n],b[n]={0};
	long long int cost;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int ans=search(a,0,n,s,&cost,n);
	cout<<ans<<" "<<cost<<endl;
	return 0;
}