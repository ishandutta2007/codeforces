#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,T,num[21000],A[100000],lim=3600*24,where[21000];
struct atom{
	int l,r,where;
	void scan(){
		char ch[15];
		scanf("%s",ch+1);
		l=ch[8]-'0'+(ch[7]-'0')*10+(ch[5]-'0')*60+(ch[4]-'0')*600+(ch[2]-'0')*3600+(ch[1]-'0')*36000;
		r=l+T;
	}
}x[21000];
int compare(atom k1,atom k2){
	return k1.l<k2.l;
}
int main(){
	scanf("%d%d%d",&n,&m,&T);
	for (int i=1;i<=n;i++) x[i].scan();
	for (int i=1;i<=n;i++){
		A[x[i].l]++; A[x[i].r]--;
	}
	int sign=0,pre=0,tot=0,now=1,flag=0;
	for (int i=0;i<lim;i++){
		tot+=A[i]; if (tot>=m) flag=1; 
	}
	if (flag==0){
		printf("No solution\n"); return 0;
	}
	tot=0;
	sort(x+1,x+n+1,compare);
	memset(A,0x00,sizeof A);
	for (int i=1;i<=n;i++) A[x[i].r]--;
	for (int i=0;i<lim;i++){
		tot+=A[i];
		while (now<=n&&x[now].l==i){
			if (tot==m){
				A[x[pre].r]++; pre=now; where[now]=sign;
			} else {
				tot++; sign++; where[now]=sign; pre=now;
			}
			now++;
		}
	}
	printf("%d\n",sign);
	for (int i=1;i<=n;i++) printf("%d\n",where[i]);
}