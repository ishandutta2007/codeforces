#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

#define ll long long
const int mod=1000000007;

struct unit
{int num;
 int x[2];
};
struct unit a[100010],b[100010];

int n,m,tot,N,ans0,ans1;
int pos[100010][2],used[100010],f[100010][2][2],L[100010],q[200010],vis[100010];
vector<pair<int,int> > w;

void update(int &i,int x)
{i+=x;
 if(i>=mod) i-=mod;
}

int equal(int x,int y)
{return x==y || x+y==0;
}

void dfs(int i,int pre)
{int j,k;

 //cout<<i<<" "<<pre<<" "<<used[i]<<endl;
 
 if(used[i]) return;
 b[++tot]=a[i];
 used[i]++;
 for(j=0;j<2;j++)
 	if(!equal(a[i].x[j],pre))
 	{	k=a[i].x[j];
 		if(k<0) k=-k;
 		if(pos[k][1]==0) return;
 		if(pos[k][0]==i)
 			dfs(pos[k][1],k);
 		else
		 	dfs(pos[k][0],k);
		return;
	}
}

void solve()
{int s0=0,s1=0,now,i,j,k;

 //cout<<"DD "<<tot<<endl;
 //cout<<tot<<" "<<b[1].num<<" "<<b[1].x[0]<<" "<<b[1].x[1]<<endl;

 if(tot==1)
 {	if(b[1].num==1)
 		w.push_back(make_pair(1,1));
 	else if(b[1].num==2)
 	{	if(b[1].x[0]==b[1].x[1])
 			w.push_back(make_pair(1,1));
 		else if(b[1].x[0]+b[1].x[1]==0)
 			w.push_back(make_pair(2,0));
 		else
		 	w.push_back(make_pair(3,1));	
 	}
 	return;
 }
 for(i=1;i<=tot;i++) L[i]=b[i].num-1;
 if(!equal(b[1].x[L[1]],b[2].x[0]) && !equal(b[1].x[L[1]],b[2].x[L[2]]))
 	swap(b[1].x[0],b[1].x[L[1]]);
 for(i=2;i<=tot;i++)
 	if(b[i].num>1 && equal(b[i].x[1],b[i-1].x[b[i-1].num-1]))
 		swap(b[i].x[0],b[i].x[1]);		
 /*
 cout<<tot<<endl;
 cout<<"-------------"<<endl;
 for(i=1;i<=tot;i++)
 	cout<<b[i].x[0]<<" "<<b[i].x[1]<<endl;		
 cout<<"---------------"<<endl;		
 cout<<b[1].num<<endl;
 */
 for(now=0;now<2;now++)
 {	memset(f[1],0,sizeof(f[1]));
 	for(i=1;i<=tot;i++)
 	{	f[i][0][0]=0;
 		f[i][0][1]=0;
 		f[i][1][0]=0;
 		f[i][1][1]=0;
 	}
 	if(b[1].num==1)
 		f[1][now][now]=1;
 	else if(now==0)
 	{	f[1][1][1]=1;
 		f[1][0][0]=1;
 	}
 	else if(now==1)
 	{	f[1][1][1]=1;
 		f[1][0][1]=1;
 	}
 	k=-1;
  	for(i=2;i<=tot;i++)
  	{	if(i==tot && b[i].num==1) break;
  		if(i==tot)
  		{	if(b[1].x[0]+b[tot].x[1]==0)
  				k=now^1;
			else if(b[1].x[0]==b[tot].x[1])
				k=now;
		}
		//cout<<i<<endl;
		//cout<<k<<endl;
	  	memset(f[i],0,sizeof(f[i]));
	  	if(b[i].x[0]+b[i-1].x[L[i-1]]==0)
  		{	if(k==-1 || k==1)
		  	{	update(f[i][1][1],f[i-1][0][0]);
  				update(f[i][1][1],f[i-1][1][0]);
  				update(f[i][1][0],f[i-1][0][1]);
  				update(f[i][1][0],f[i-1][1][1]);
  			}
  			if(k==-1 || k==0)
  			{	update(f[i][0][1],f[i-1][0][0]);
  				update(f[i][0][1],f[i-1][1][1]);
  				update(f[i][0][0],f[i-1][0][1]);
  				update(f[i][0][0],f[i-1][1][0]);
  			}
  		}
  		else
  		{	if(k==-1 || k==1)
		  	{	update(f[i][1][1],f[i-1][0][0]);
  				update(f[i][1][1],f[i-1][1][0]);
  				update(f[i][1][0],f[i-1][0][1]);
  				update(f[i][1][0],f[i-1][1][1]);
  			}
  			if(k==-1 || k==0)
  			{	update(f[i][0][1],f[i-1][0][1]);
  				update(f[i][0][1],f[i-1][1][0]);
  				update(f[i][0][0],f[i-1][0][0]);
  				update(f[i][0][0],f[i-1][1][1]);
  			}
  		}
  	}
  	if(b[tot].num==1)
  	{	for(i=0;i<2;i++)	
  			for(j=0;j<2;j++)
  				f[tot][i][j]=f[tot-1][i][j];
  		if(b[tot].x[0]+b[tot-1].x[L[tot-1]]==0)
  			swap(f[tot][0][1],f[tot][0][0]);
  		else
		  	swap(f[tot][1][1],f[tot][1][0]);
	}
	//cout<<f[tot][0][0]<<" "<<f[tot][1][0]<<endl;
	update(s0,(f[tot][0][0]+f[tot][1][0])%mod);
 	update(s1,(f[tot][0][1]+f[tot][1][1])%mod);
 }
 //cout<<"## "<<s0<<" "<<s1<<endl;
 w.push_back(make_pair(s1,s0));
}
 
int main()
{int i,j,k,t0,t1,s=0;
 
 scanf("%d%d",&n,&m);
 for(i=1;i<=n;i++)
 {	scanf("%d",&a[i].num);
 	for(j=0;j<a[i].num;j++)
 	{	scanf("%d",&a[i].x[j]);
 		k=a[i].x[j];
 		if(k<0) k=-k;
 		vis[k]++;
 		pos[k][used[k]++]=i;
	}
 }
 for(i=1;i<=m;i++)
 	if(!vis[i]) s++;
 for(i=1;i<=n;i++)
 	if(a[i].num==1) q[++N]=i;
 for(i=1;i<=m;i++)
 	if(pos[i][1]==0) q[++N]=pos[i][0];
 memset(used,0,sizeof(used));
 for(i=1;i<=N;i++)
 	if(!used[q[i]])
 	{	tot=0;
 		k=a[q[i]].x[0];
 		if(k<0) k=-k;
 		if(pos[k][1]==0)
 			dfs(q[i],k);
 		else
 			dfs(q[i],a[q[i]].x[1]);
 		solve();
 	}
 for(i=1;i<=n;i++)
 	if(!used[i])
 	{	tot=0;
 		dfs(i,0);
 		solve();
 	}
 /*
 cout<<"ac"<<endl;
 for(i=0;i<w.size();i++)
 	cout<<w[i].first<<" "<<w[i].second<<endl;	
 */	
 ans0=1;
 ans1=0;
 for(i=0;i<w.size();i++)
 {	t0=ans0;
 	t1=ans1;
	ans0=((ll)t1*w[i].first%mod+(ll)t0*w[i].second%mod)%mod;
	ans1=((ll)t0*w[i].first%mod+(ll)t1*w[i].second%mod)%mod;
 }
 //cout<<ans1<<endl;
 for(i=1;i<=s;i++) ans1=ans1*2%mod;
 printf("%d\n",ans1);
 return 0;
}