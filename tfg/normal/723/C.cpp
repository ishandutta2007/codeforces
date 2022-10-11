#include <cstdio>
#include <vector>

int n, m;
int a[10000];
int freq[10000];

std::vector<int> maxx;

int min_elem()
{
	int ind, min=10000;
	for(int i=1;i<=m;i++)
	{
		if(freq[i]<min)
		{
			min=freq[i];
			ind=i;
		}
	}
	return ind;
}

int max_elem()
{
	int ind, max=-1;
	for(int i=1;i<=m;i++)
	{
		if(freq[i]>max)
		{
			max=freq[i];
			ind=i;
		}
	}
	return ind;
}

int search_for(int x)
{
	int i=0;
	for(;a[i]!=x;i++);
	return i;
}

int main()
{
	scanf("%i %i", &n, &m);
	int min, max;
	min=n/m;max=(n+m-1)/m;
	for(int i=0;i<n;i++)
	{
		scanf("%i", a+i);
		if(a[i]<=m)
			freq[a[i]]++;
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>m)
		{
			
			int mmin=min_elem();
			if(freq[mmin]<min)
			{
				freq[mmin]++;
				//printf("changing a[%i]=%i to %i.\n",i,a[i],mmin);
				ans++;
				a[i]=mmin;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		while(freq[i]<min)
		{
			int mmax=max_elem();
			freq[mmax]--;
			freq[i]++;
			ans++;
			a[search_for(mmax)]=i;
		}
	}
	/*for(int i=0;i<n;i++)
	{
		if(a[i]<=m)
		{
			if(freq[a[i]]>max)
			{
				int mmin=min_elem();
				freq[mmin]++;
				freq[a[i]]--;
				ans++;
				a[i]=mmin;
			}
			else if(freq[a[i]]<min)
			{
				int mmax=max_elem();
				freq[mmax]--;
				freq[a[i]]++;
				ans++;
				a[search_for(mmax)]=a[i];
			}
		}
	}*/
	printf("%i %i\n%i",min,ans,a[0]);
	for(int i=1;i<n;i++)
		printf(" %i", a[i]);
	printf("\n");
}