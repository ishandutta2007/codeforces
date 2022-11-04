#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int n;
int w[500010],sa[500010],rank[1000010],c[500010],d[500010],h[500010],f[500010][21],s[500010],b[500010];
long long ans;
char a[1000010];
vector<int> g[1000010];

void suffix()
{int i,j,k,p;
 
 for(i=1;i<=n;i++) w[a[i]]++;
 for(i=1;i<=256;i++) w[i]+=w[i-1];
 for(i=1;i<=n;i++) rank[i]=w[a[i]];
 for(i=1;i<=n;i++) sa[w[a[i]]--]=i;
 for(p=2;p/2<=n;p*=2)
 {	j=0;
	for(i=n;i>=n-p/2+1;i--) b[++j]=i;
	for(i=1;i<=n;i++) if(sa[i]>p/2) b[++j]=sa[i]-p/2;
 	//for(i=p/2+1;i<=n;i++) w[rank[i]]++;
 	//for(i=1;i<=256;i++) w[i]+=w[i-1];
 	//for(i=1;i<=n-p/2;i++) b[w[rank[i+p/2]]--]=i;
 	//for(i=1;i<=n;i++) cout<<b[i]<<endl;
 	for(i=1;i<=n;i++) w[i]=0;
 	for(i=1;i<=n;i++) w[rank[b[i]]]++;
 	for(i=1;i<=n;i++) w[i]+=w[i-1];
 	for(i=n;i>=1;i--) sa[w[rank[b[i]]]--]=b[i];
 	k=0;
 	for(i=1;i<=n;i++) if(i==1 || rank[sa[i]]!=rank[sa[i-1]] || rank[sa[i]+p/2]!=rank[sa[i-1]+p/2]) c[sa[i]]=++k; else c[sa[i]]=k;
 	for(i=1;i<=n;i++) rank[i]=c[i];
 	//cout<<p<<endl;
 	//for(i=1;i<=n;i++) cout<<rank[i]<<" ";
 	//cout<<endl;
 	//for(i=1;i<=n;i++) cout<<sa[i]<<" ";
 	//cout<<endl;
 	//cout<<(int)'('<<" "<<(int)')'<<endl;
	if(k>=n) break;
 }
}

int query(int l,int r)
{int k;
 k=d[r-l+1];
 return min(f[l][k],f[r-(1<<k)+1][k]);
}

int main()
{int i,j,p,l,r,mid,k;
 
 scanf("%d",&n);
 scanf("%s",a+1);
 suffix();
 //for(i=1;i<=n;i++) cout<<sa[i]<<" ";
 //cout<<endl;
 //for(i=1;i<=n;i++) cout<<rank[i]<<" ";
 //cout<<endl;
 for(i=1;i<=n;i++)
 {	if(rank[i]==1) continue;
 	h[i]=max(0,h[i-1]-1);
 	while(i+h[i]<=n && sa[rank[i]-1]+h[i]<=n && a[i+h[i]]==a[sa[rank[i]-1]+h[i]]) h[i]++;
 }
 //for(i=1;i<=n;i++) cout<<h[i]<<" ";
 //cout<<endl;
 for(i=1;i<=n;i++)
 {	s[i]=s[i-1]+((a[i]=='(')?1:-1);
 	g[s[i]+n].push_back(i);
 }
 //for(i=1;i<=2*n;i++) cout<<i<<" "<<g[i].size()<<endl;
 for(i=1;i<=2*n;i++) sort(g[i].begin(),g[i].end());
 for(i=2;i<=n;i++) d[i]=d[i/2]+1;
 for(i=1;i<=n;i++) f[i][0]=s[i];
 for(p=1;p<=d[n];p++)
 	for(i=1;i<=n-(1<<p)+1;i++)
	 	f[i][p]=min(f[i][p-1],f[i+(1<<(p-1))][p-1]);
 for(i=1;i<=n;i++)
 {	l=i+h[i];
 	r=n;
 	k=0;
 	while(l<=r)
 	{	mid=(l+r)/2;
 		if(query(i,mid)>=s[i-1])
 		{	k=max(k,mid);
		 	l=mid+1;
 		}
 		else
			r=mid-1;
	}
	//cout<<i<<" "<<i+h[i]<<" "<<k<<endl;
	//cout<<s[i]<<" "<<g[s[i]+n].size()<<endl;
	if(k>=i+h[i]) ans+=upper_bound(g[s[i-1]+n].begin(),g[s[i-1]+n].end(),k)-lower_bound(g[s[i-1]+n].begin(),g[s[i-1]+n].end(),i+h[i]);
 }
 printf("%I64d\n",ans);
 return 0;
}