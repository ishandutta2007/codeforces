#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int pd[210000],s[210000],head,n;
struct atom{
    int where,x,y;
}x[210000];
int compre(atom k1,atom k2){
	return k1.x<k2.x||(k1.x==k2.x&&k1.y>k2.y);
}
int check(int i){
    int k1=x[s[head-1]].y,k2=x[s[head]].y,k3=x[i].y,k4=x[s[head-1]].x,k5=x[s[head]].x,k6=x[i].x;
    return 1ll*(k1*k3-k2*k3)*(k4*k6-k4*k5)>1ll*(k1*k2-k1*k3)*(k5*k6-k4*k6);
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
		scanf("%d%d",&x[i].x,&x[i].y); x[i].where=i;
	}
    sort(x+1,x+1+n,compre);
    head=1; s[1]=1;
    for (int i=2;i<=n;i++){
        if(x[i].x==x[i-1].x)continue; while(head>=2&&check(i))head--; s[++head]=i;
    }
    for (int i=1;i<=head;i++)pd[x[s[i]].where]=1;
    for (int i=2;i<=head;i++)
        if(x[s[i-1]].y<=x[s[i]].y) pd[x[s[i-1]].where]=0; else break;
    for (int i=2;i<=n;i++){
        if(x[i].y==x[i-1].y&&x[i].x==x[i-1].x&&pd[x[i-1].where]) pd[x[i].where]=1;
    }
    for (int i=1;i<=n;i++) if(pd[i])printf("%d ",i);
    cout<<endl;
    return 0;
}