#include<bits/stdc++.h>
using namespace std;

const int inf=1e9;
int n,cnt;
long long tot;
long long w[70];

void insert(long long x)
{int i;
 
 for(i=62;i>=0;i--)
 	if(x&(1LL<<i))
 	{	if(!w[i])
 		{	w[i]=x;
 			cnt++;
			return;
		}
		x^=w[i];
	}
}

int query(long long x)
{int i;
 
 for(i=62;i>=0;i--)
 	if(x&(1LL<<i))
 		x^=w[i];
 return x==0;
}

int main()
{int i,j;
 long long x,y;
 
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {	scanf("%I64d%I64d",&x,&y);
 	tot^=x;
 	insert(x^y);
 }
 if(query(tot))
 	printf("%I64d/%I64d\n",(1LL<<cnt)-1,1LL<<cnt);
 else
 	printf("1/1\n");
 return 0;
}