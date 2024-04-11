#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct bian{
	int next,point,f;
}b[2000];
int p[60],u[1000],v[1000],w[10000],n,m,K,len,totpoint,x[60],pd[60],dst[60];
const int inf=1e9;
void ade(int k1,int k2,int k3)
{
    len++; b[len].point=k2; b[len].next=p[k1]; b[len].f=k3; p[k1]=len;
}
void add(int k1,int k2,int k3)
{
//	cout<<"add "<<k1<<" "<<k2<<" "<<k3<<endl;
    ade(k1,k2,k3); ade(k2,k1,0);
}
bool bfs(int s,int t)
{
    int head=1,now=0,i,j;
    for (int i=0;i<=totpoint;i++){
        dst[i]=-1; pd[i]=0;
    }
    x[1]=s; pd[s]=1; dst[s]=0;
    while (head>now)
    {
        now++; i=p[x[now]]; 
        while (i!=-1)
        {
            j=b[i].point;
            if ((b[i].f)&&(!pd[j]))
            {
                pd[j]=1; dst[j]=dst[x[now]]+1;
                if (j==t)
                {
                    return 1;
                }
                head++; x[head]=j;
            }
            i=b[i].next;
        }
    }
    return pd[t];
}
int change(int k1,int aim,int k2)
{
    if ((k1==aim)||(k2==0)) return k2;
    int num=0,k,i,j;
    i=p[k1];
    while (i!=-1)
    {
        j=b[i].point;
        if ((b[i].f)&&(dst[k1]+1==dst[j]))
        {
            k=change(j,aim,min(k2,b[i].f));
            k2=k2-k; num+=k;
            b[i].f=b[i].f-k; b[i^1].f+=k;
            if (k2==0)
            {
                break;
            }
        }
        i=b[i].next;
    }
    if (!num)
    {
        dst[k1]=-1;
    }
    return num;
}
int dinic(int s,int t,int lim){
    int now=0; 
    while (bfs(s,t)&&lim){
        int k=change(s,t,lim); now+=k; lim-=k;
    }
   // cout<<now<<endl;
    return now;
}
int check(double k1){
	//cout<<"check "<<k1<<endl;
	len=-1; totpoint=n-1;
	memset(p,0xff,sizeof p);
	for (int i=1;i<=m;i++){
		int k=(int)min(K*1.0,(trunc(w[i]/k1)));
		add(u[i]-1,v[i]-1,k);
	}
	return dinic(0,totpoint,inf)>=K;
}
int main(){
	scanf("%d%d%d",&n,&m,&K);
	for (int i=1;i<=m;i++) scanf("%d%d%d",&u[i],&v[i],&w[i]);
	double l=0,r=1000001;
	for (int i=1;i<=100;i++){
		double mid=(l+r)/2.0;
		if (check(mid)) l=mid; else r=mid;
	}
	printf("%.11lf\n",K*(l+r)/2);
	return 0;
}