#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
int n;
char ch[110000];
const int size=310;
int A[60000][350][4],B[110000],where[110000],f[320][320],cnt;
map<char,int>M;
void add(int k1,int k2,int k3){
	for (int i=1;i<=size;i++)
		A[f[i][k1%i]][where[k1]][k2]+=k3;
}
int calc(int k1,int step,int k2,int k3){
//	cout<<"calc "<<k1<<" "<<step<<" "<<k2<<" "<<k3<<endl;
	if (step>size){
		if (k2==0) k2+=step; int ans=0;
	//	for (int i=1;i<=n;i++) cout<<B[i]<<" "; cout<<endl;
		while (k2<=k1){
			ans+=(B[k2]==k3); k2+=step;
		}
	//	cout<<ans<<endl;
		return ans;
	}
	int where=f[step][k2],ans=0;
	int lim=k1/size,R=max(1,lim*size); 
	for (int i=0;i<lim;i++) ans+=A[where][i][k3];
	int fir=R/step*step+k2; if (fir<R) fir+=step;
	//cout<<R<<" "<<fir<<endl;
	for (int i=fir;i<=k1;i+=step) ans+=(B[i]==k3);
//	cout<<fir<<" "<<ans<<endl;
	return ans;
}
int main(){
	scanf("%s",ch+1); n=strlen(ch+1);
	M['A']=0; M['T']=1; M['G']=2; M['C']=3;
	for (int i=1;i<=n;i++) B[i]=M[ch[i]];
	for (int i=1;i<=size;i++)
		for (int j=0;j<i;j++) f[i][j]=++cnt;
	for (int i=1;i<=n;i++){
		where[i]=i/size; add(i,B[i],1);
	}
	int m; scanf("%d",&m);
	for (;m;m--){
		int k1,k2; scanf("%d%d",&k1,&k2);
	//	for (int i=1;i<=n;i++) cout<<B[i]<<" "; cout<<endl;
		if (k1==1){
			scanf("%s",ch+1); add(k2,B[k2],-1); B[k2]=M[ch[1]]; add(k2,B[k2],1);
		} else {
			int k3; scanf("%d%s",&k3,ch+1); int len=strlen(ch+1),ans=0;
			for (int i=1;i<=len;i++){
				int fir=k2+i-1;
				ans+=calc(k3,len,fir%len,M[ch[i]])-calc(k2-1,len,fir%len,M[ch[i]]);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}