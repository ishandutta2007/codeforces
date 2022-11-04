#include<bits/stdc++.h>
using namespace std;

int n,m,tot;
int l[1000010],r[1000010];
char a[1000010],b[1000010];
vector<int> w[300];

int check(int i)
{int x,y;
 
 x=l[i];
 y=r[i];
 if(y-x>m) return 0;
 r[x]=y;
 l[y]=x;
 return 1;
}

int main()
{int i,j,k,p,flag,s;
 
 scanf("%d",&m);
 scanf("%s",a+1);
 n=strlen(a+1);
 for(i=0;i<=n;i++) r[i]=i+1;
 for(i=1;i<=n+1;i++) l[i]=i-1;
 for(i=1;i<=n;i++)
 	w[a[i]-96].push_back(i);
 for(i=26;i>=1;i--)
 {	flag=1;
 	s=0;
 	for(j=0;j<w[i].size();j++)
 		if(!check(w[i][j]))
 		{	flag=0;
		 	s++;
 		}
 	if(s)
	{	for(j=1;j<i;j++)
			for(p=0;p<w[j].size();p++)
				b[++tot]=96+j;
		for(p=1;p<=s;p++) b[++tot]=96+i;
		break;
	}
	//cout<<i<<" "<<flag<<endl;
 }
 sort(b+1,b+tot+1);
 for(i=1;i<=tot;i++)
 	printf("%c",b[i]);
 printf("\n");	
 return 0;
}