#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

struct unit
{char sa[3],sb[3];
};
struct unit a[110];

int n,nq,ans;
vector<char> w[100010];
char c[110];

int check(int i)
{int j,k,flag=0;
 char t;
 if(i==n)
 {	if(c[i]=='a') return 1;
 	return 0;
 }
 t=c[i+1];
 k=(c[i]-96)*100+(c[i+1]-96);
 for(j=0;j<w[k].size();j++)
 {	c[i+1]=w[k][j];
 	flag=flag|check(i+1);
 	c[i+1]=t;
 	if(flag) return 1;
 }
 return 0;
}

void dfs(int i)
{int j;
 if(i==n+1)
 {	//cout<<c[1]<<c[2]<<c[3]<<endl;
 	if(check(1))
 	{	ans++;
 		//cout<<c[1]<<c[2]<<c[3]<<endl;
 	}
 	return;
 }
 for(j=1;j<=6;j++)
 {	c[i]=96+j;
 	dfs(i+1);
 }
}

int main()
{int i,j;
 
 scanf("%d%d",&n,&nq);
 for(i=1;i<=nq;i++)
 {	scanf("%s%s",a[i].sa+1,a[i].sb+1);
 	w[(a[i].sa[1]-96)*100+(a[i].sa[2]-96)].push_back(a[i].sb[1]);
 }
 dfs(1);
 cout<<ans<<endl;
 return 0;
}