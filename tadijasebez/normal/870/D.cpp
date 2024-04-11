#include <stdio.h>
#include <set>
#include <stdlib.h>
#include <ctime>
using namespace std;
const int N=5050;
int p[N],q[N],a[N],b[N],l[N],r[N],sol[N];
int Ask(int i, int j)
{
	printf("? %i %i\n",i,j);
	fflush(stdout);
	int x;
	scanf("%i",&x);
	return x;
}
set<int> id;
set<int>::iterator it;
int GetId(int x){ it=id.begin();while(--x) it++;return *it;}
int abs(int x){ return x>0?x:-x;}
bool Try(int n, int st)
{
	//id.clear();
	int i,j,last,loop,x;
	for(i=0;i<n;i++) p[i]=q[i]=-1;//,id.insert(i);
	for(i=0;i<n;i++) p[i]=a[l[i]]^st;
	for(i=0;i<n;i++) q[p[i]]=i;//,printf("%i %i\n",p[i],i);
	//for(i=0;i<n;i++) printf("%i ",p[i]);printf("\n");
	//for(i=0;i<n;i++) printf("%i ",q[i]);printf("\n");
	//printf("\n");
	for(i=0;i<n;i++) if(q[i]==-1) return 0;
	int k=3*n;
	while(k--){ i=rand()%n;j=rand()%n;if((p[i]^q[j])!=(a[j]^b[i])){ /*printf("(%i %i) %i %i\n",i,j,p[i]^q[j],a[j]^b[i]);*/return 0;}}
	for(i=0;i<n;i++) sol[i]=p[i];
	/*for(loop=0;loop<n;loop++)
	{
		printf("loop:%i\n",loop);
		if(p[loop]!=-1) continue;
		//if(loop!=0){ printf(":D\n");return 0;}
		x=GetId(abs(rand())%id.size());
		//x=st;
		printf("%i\n",x);
		id.erase(x);
		p[loop]=x;q[x]=loop;
		i=r[x],j=loop,last=x;
		while(p[i]==-1)
		{
			printf("(%i %i)\n",i,j);
			p[i]=a[j]^b[l[i]]^last;
			if(!id.count(p[i])) return 0;
			id.erase(p[i]);
			q[p[i]]=i;
			j=i;
			last=p[i];
			i=r[p[i]];
		}
	}*/
	return 1;
}
int main()
{
	srand(time(0));
	int n,i,j;
	scanf("%i",&n);
	for(i=0;i<n;i++)
	{
		a[i]=Ask(0,i);
		if(a[i]==0) l[0]=i,r[i]=0;
	}
	for(i=0;i<n;i++)
	{
		b[i]=Ask(i,l[0]);
	}
	for(i=0;i<n;i++) for(j=0;j<n;j++) if(a[j]==b[i]) l[i]=j,r[j]=i;
	//for(i=0;i<n;i++) printf("%i ",l[i]);printf("\n");
	//for(i=0;i<n;i++) printf("%i ",r[i]);printf("\n");
	//for(i=0;i<n;i++) printf("%i ",a[i]);printf("\n");
	//for(i=0;i<n;i++) printf("%i ",b[i]);printf("\n");
	int cnt=0;
	for(i=0;i<n;i++) cnt+=Try(n,i);
	//for(i=0;i<n;i++) if(p[i]!=i) cnt=2;
	printf("!\n%i\n",cnt);
	for(i=0;i<n;i++) printf("%i ",sol[i]);
	printf("\n");
	fflush(stdout);
	return 0;
}