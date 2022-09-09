#include <stdio.h>
#include <queue>
using namespace std;
bool vis[4][4];
int a[4][4],b[4][4];
pair<int,int> sol[4][4];
int time[4][4];
bool win(int f, int s)
{
	if(f==1 && s==3) return true;
	if(f==2 && s==1) return true;
	if(f==3 && s==2) return true;
	return false;
}
int main()
{
	int i,j,f,s;
	long long n;
	scanf("%lld %i %i",&n,&f,&s);
	for(i=1;i<=3;i++) for(j=1;j<=3;j++) scanf("%i",&a[i][j]);
	for(i=1;i<=3;i++) for(j=1;j<=3;j++) scanf("%i",&b[i][j]);
	int t,tmp;
	long long res1=0,res2=0,cicle1,cicle2;
	bool ok=false;
	for(i=0;i<n;i++)
	{
		//printf("%i %i %i\n",i,f,s);
		vis[f][s]=true;
		time[f][s]=i;
		res1+=win(f,s);
		res2+=win(s,f);
		if(!vis[a[f][s]][b[f][s]])
		{	
			sol[a[f][s]][b[f][s]]=make_pair(res1,res2);
		}
		else
		{
			cicle1=res1-sol[a[f][s]][b[f][s]].first;
			cicle2=res2-sol[a[f][s]][b[f][s]].second;
			t=i-time[a[f][s]][b[f][s]]+1;
			n=n-i-1;
			res1+=cicle1*(n/t);
			res2+=cicle2*(n/t);
			n=n%t;
			//printf("%i %i %i %i\n",cicle1,cicle2,t,n);
			ok=true;
			tmp=a[f][s];
			s=b[f][s];
			f=tmp;
			break;
		}
		tmp=a[f][s];
		s=b[f][s];
		f=tmp;
	}
	if(ok)
	{
		for(i=0;i<n;i++)
		{
			res1+=win(f,s);
			res2+=win(s,f);
			tmp=a[f][s];
			s=b[f][s];
			f=tmp;
		}
	}
	printf("%lld %lld\n",res1,res2);
	return 0;
}