#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
char s[N];
int z[N],n; 
void get_z()
{
	int l=0,r=0;
	for(int i=1;i<n;i++)
	{
		if(i>r)
		{
			l=i,r=i;
			while(r<n&&s[r-l]==s[r])
				r++;
			z[i]=r-l;
			r--;
		}
		else
		{
			int k=i-l;
			if(z[k]<r-i+1)
				z[i]=z[k];
			else
			{
				l=i;
				while(r<n&&s[r-l]==s[r])
					r++;
				z[i]=r-l;
				r--; 
			}
		}
	}
}
int main()
{
	scanf("%s",s);
	n=strlen(s);
	get_z();
	int maxx=0,pos=0;
	for(int i=1;i<n;i++)
	{
		if(z[i]==n-i&&maxx>=n-i)
		{
			pos=i;
			break;	
		}	
		maxx=max(maxx,z[i]);
	} 
	if(!pos)
		printf("Just a legend");
	else
		for(int i=0;i<n-pos;i++)
			putchar(s[i]);
	return 0;
}