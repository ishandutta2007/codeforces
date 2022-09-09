#include <stdio.h>
#include <cstring>
const int N=100050;
int x[N],y[N],z[N];
char word[N];
int abs(int x){ return x>0?x:-x;}
int main()
{
	int n,q,l,r,i;
	scanf("%s",&word);
	n=(unsigned) strlen(word);
	for(i=0;i<n;i++)
	{
		x[i+1]=x[i];
		y[i+1]=y[i];
		z[i+1]=z[i];
		if(word[i]=='x') x[i+1]++;
		if(word[i]=='y') y[i+1]++;
		if(word[i]=='z') z[i+1]++;
	}
	scanf("%i",&q);
	int t1,t2,t3;
	while(q--)
	{
		scanf("%i %i",&l,&r);
		if(r-l<2) printf("YES\n");
		else 
		{
			l--;
			t1=x[r]-x[l];
			t2=y[r]-y[l];
			t3=z[r]-z[l];
			if(abs(t1-t2)>1 || abs(t2-t3)>1 || abs(t3-t1)>1) printf("NO\n");
			else printf("YES\n");
		}
	}
	return 0;
}