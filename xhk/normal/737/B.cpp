#include<bits/stdc++.h>
using namespace std;

int n,sa,sb,m,cnt;
char a[200010];
vector<pair<int,int> > b;
vector<int> c;

int main()
{int i,j,last;
 
 scanf("%d%d%d%d",&n,&sa,&sb,&m);
 scanf("%s",a+1);
 for(i=1;i<=n;i=last+1)
 {	last=i-1;
 	while(last+1<=n && a[last+1]=='0') last++;
 	//cout<<i<<" "<<last<<endl;
 	if(last>=i)
 	{	cnt+=(last-i+1)/sb;
 		b.push_back(make_pair(i,last));
 	}
 	else
 		last=i;
 }
 
 //cout<<cnt<<endl;
 for(i=0;i<b.size();i++)
 {	for(j=b[i].first;j+sb-1<=b[i].second;j+=sb)
 		if(cnt>=sa)
 		{	c.push_back(j+sb-1);
 			cnt--;
 		}
 }
		
 printf("%d\n",c.size());
 for(i=0;i<c.size();i++)
 {	printf("%d",c[i]);
 	printf("%c",i!=c.size()-1?' ':'\n');
 }
 return 0;
}