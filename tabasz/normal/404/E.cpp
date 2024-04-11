#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

char C[1000001];
int T[2000002];

int main()
{
	scanf("%s", C);
	int ind=1000000, n=0;
	while((int)C[n]!=0) n++;
	for(int i=0; i<n; i++)
	{
		T[ind]++;
		if(C[i]=='R') ind++;
		else ind--;
	}
	if(!T[ind])
	{
		printf("1\n");
		return 0;
	}
	if(C[n-1]=='L')
	{
		for(int i=0; i<n; i++)
		{
			if(C[i]=='L') C[i]='R';
			else C[i]='L';
		}
	}
	int p=1000000-n, k=1000000-1, mid=(p+k)/2, w=0;
	while(p<=k)
	{
		ind=1000000;
		for(int i=p; i<=1000000+n; i++) T[i]=0;
		for(int i=0; i<n; i++)
		{
			T[ind]++;
			if(C[i]=='R') ind++;
			else
			{
				if(ind-1>mid) ind--;
			}
		}
		if(T[ind]==0)
		{
			w=max(w, 1000000-mid);
			k=mid-1;
		}
		else p=mid+1;
		mid=(p+k)/2;
	}
	printf("%d\n", w);
	return 0;
}