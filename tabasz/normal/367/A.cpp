#include<cstdio>
#include<algorithm>
using namespace std;
const int M=131072;

int D[2*M][3];

int sum(int p, int k, int d)
{
	p+=M;
	k+=M;
	int w=D[p][d];
	if(p!=k) w+=D[k][d];
	while(p/2!=k/2)
	{
		if(p%2==0) w+=D[p+1][d];
		if(k%2==1) w+=D[k-1][d];
		p/=2;
		k/=2;
	}
	return w;
}

int main()
{
	int n, li=0, m;
	char c;
	scanf("%c", &c);
	while(c!='\n')
	{
		if(c=='x') D[li+M][0]=1;
		if(c=='y') D[li+M][1]=1;
		if(c=='z') D[li+M][2]=1;
		li++;
		scanf("%c", &c);
	}
	for(int i=M-1; i>0; i--)
		for(int j=0; j<3; j++)
			D[i][j]=D[2*i][j]+D[2*i+1][j];
	//for(int i=0; i<6; i++) printf("%d,, ", D[i+M][2]);
	scanf("%d", &m);
	for(int i=0; i<m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		int x=sum(a, b, 0), y=sum(a, b, 1), z=sum(a, b, 2);
		//printf("%d, %d, %d\n", x, y, z);
		int mini=min(x, min(y, z)), maxi=max(x, max(y, z));
		if((b-a+1)<3 || mini+1>=maxi || ((b-a+1)==3 && z==1 && x==1 && y==1)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}