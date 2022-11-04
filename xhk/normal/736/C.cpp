#include<bits/stdc++.h>
using namespace std;

struct edge
{int u,v,next;
};
struct edge e[10010];

#define ll long long
const int mod=1000000007;
int n,d,num,sp,ans;
int head[110],f[110][30][30],h[110][30][30],g[30][30];

void update(int &i,int x)
{i=(i+x)%mod;
}

void add(int u,int v)
{e[num].u=u;
 e[num].v=v;
 e[num].next=head[u];
 head[u]=num;
 num++;
 e[num].u=v;
 e[num].v=u;
 e[num].next=head[v];
 head[v]=num;
 num++;
}

void work(int i,int fa)
{int j,i1,j1,i2,j2,s,s1,d1,d2,flag;
 
 //cout<<i<<endl;
 if(i!=1 && e[head[i]].next==-1)
 {	f[i][sp][0]=1;
 	f[i][0][sp]=1;
 	return;
 }

 //cout<<"&&"<<endl;

 j=head[i];
 flag=1;
 s1=1;
 while(j!=-1)
 {	if(e[j].v!=fa)
 	{	work(e[j].v,i);
 		s=0;
		if(flag)
 		{	flag=0;
 			memset(h[i],0,sizeof(h[i]));
			for(i1=0;i1<=d+2;i1++)
 				for(j1=0;j1<=d+1;j1++)
 				{	if(i1==sp && j1==sp)
 						update(h[i][0][sp],f[e[j].v][i1][j1]);
 					else if(i1==sp)
 					{	if(j1+1<=d)
 							update(h[i][sp][j1+1],f[e[j].v][i1][j1]);
 						else
					 		update(h[i][0][sp],f[e[j].v][i1][j1]);
					}
 					else if(j1==sp && i1+1<=d)
 						update(h[i][i1+1][sp],f[e[j].v][i1][j1]);
 					else if(i1+1<=d)
 						update(h[i][i1+1][j1+1],f[e[j].v][i1][j1]);	
 					if(i1<d || i1==sp) update(s,f[e[j].v][i1][j1]);
 				}
 			//cout<<"(( "<<i<<" "<<h[0][1]<<" "<<f[e[j].v][sp][0]<<endl;	
 		}
 		else
		{	memset(g,0,sizeof(g));
			for(i1=0;i1<=d+1;i1++)
				for(j1=0;j1<=d+1;j1++)
				{	if(h[i][i1][j1]==0) continue;
					for(i2=0;i2<=d+1;i2++)
						for(j2=0;j2<=d+1;j2++)
						{	if(f[e[j].v][i2][j2]==0) continue;
							if(i2==d) continue;
							
							d1=-1;
							if(i2!=sp && (i2+1+j1>d)) d1=max(d1,i2+1);
							if(i1!=sp && (i1+j2+1>d)) d1=max(d1,i1);
							if(j1==sp && j2>=d) d1=max(d1,0);
							if(d1==-1) d1=sp;
							
							d2=sp;
							if(j1!=sp) d2=min(d2,j1);
							if(j2!=sp) d2=min(d2,j2+1);
							
							//cout<<i1<<" "<<j1<<" "<<i2<<" "<<j2<<" "<<"%% "<<d1<<" "<<d2<<" "<<(ll)h[i1][j1]*f[e[j].v][i2][j2]%mod<<endl;
							update(g[d1][d2],(ll)h[i][i1][j1]*f[e[j].v][i2][j2]%mod);
						}
				}
			s=0;	
			for(i1=0;i1<=d+1;i1++)
				for(j1=0;j1<=d+1;j1++)
				{	h[i][i1][j1]=g[i1][j1];
					if(i1!=d) update(s,f[e[j].v][i1][j1]);
				}		
		}
		/*
		for(i1=0;i1<=d+1;i1++)
 			{	for(j1=0;j1<=d+1;j1++)
 					cout<<i<<" "<<i1<<" "<<j1<<" ## "<<h[i1][j1]<<endl;
 			}	
 			cout<<"-----"<<endl;
		*/
		s1=(ll)s1*s%mod;			
 	}
 	j=e[j].next;
 }
 f[i][sp][0]=s1;
 //cout<<i<<" "<<s1<<endl;
 for(i1=0;i1<=d+1;i1++)
 	for(j1=0;j1<=d+1;j1++)
 		update(f[i][i1][j1],h[i][i1][j1]);
 /*
 for(i1=0;i1<=d+1;i1++)
 {	for(j1=0;j1<=d+1;j1++)
 		cout<<i<<" "<<i1<<" "<<j1<<" ## "<<f[i][i1][j1]<<endl;
 }
 cout<<"-----"<<endl;		
 */
}

int main()
{int i,j,x,y;
 
 scanf("%d%d",&n,&d);
 memset(head,-1,sizeof(head));
 for(i=1;i<n;i++)
 {	scanf("%d%d",&x,&y);
 	add(x,y);
 }
 if(d==0)
 {	printf("%d\n",1);
 	return 0;
 }
 sp=d+1;
 work(1,0);
 ans=0;
 for(i=0;i<=d+1;i++) update(ans,f[1][sp][i]);
 //update(ans,f[1][sp][sp]);
 printf("%d\n",ans);
 return 0;
}