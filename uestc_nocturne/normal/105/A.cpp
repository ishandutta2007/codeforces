#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
typedef __int64 LL;
struct Node{string name;int va;}sk[120];
bool cmp(Node x,Node y){return x.name<y.name;}
int n,m,i,po,id,j;
string ch;
double k;
int main()
{
	while(~scanf("%d%d%lf",&n,&m,&k))
	{
		for(i=0;i<n;i++)
		cin>>sk[i].name>>sk[i].va;
		po=0;
		for(i=0;i<n;i++)
		{
			sk[i].va=(int)((double)sk[i].va*(k+0.00000001));
			if(sk[i].va>=100)
			{
				sk[po].name=sk[i].name;
				sk[po++].va=sk[i].va;
			}
		}
		n=po;
		for(i=0;i<m;i++)
		{
			cin>>ch;
			id=-1;
			for(j=0;j<n;j++)
			if(sk[j].name==ch)
			{id=j;break;}
			if(id==-1)
			{
				sk[n].name=ch;
				sk[n].va=0;
				n++;
			}
		}
		sort(sk,sk+n,cmp);
		cout<<n<<endl;
		for(i=0;i<n;i++)
		cout<<sk[i].name<<" "<<sk[i].va<<endl;
	}
}