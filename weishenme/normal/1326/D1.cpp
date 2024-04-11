#include<bits/stdc++.h>
using namespace std;
const int N=5000005;
char s_new[N],s[N],t[N];
int p[N];
int Init() {// 
    int len=strlen(s);//len
    s_new[0]='$';// 
    s_new[1]='#';
    int j=2; 
    for(int i=0;i<len;i++) {
        s_new[j++]=s[i];
        s_new[j++]='#';
    } 
    s_new[j]='\0';// 
    return j;// s_new 
}
void Manacher() {
    int len=Init();
    int max_len=-1;//
    int id;
    int mx=0,vis=0;
    for(int i=1;i<=len;i++) {
        if(i<mx)
            p[i]=min(p[2*id-i],mx-i);// 
        else p[i]=1;
        while(s_new[i-p[i]]==s_new[i+p[i]])//'$''\0'
            p[i]++;//mx
        if(mx<i+p[i]) {//mxmxp[i]=min(p[2*id-i],mx-i) 
            id=i;//id 
            mx=i+p[i];//mx 
        }
		if (p[i]-1>max_len&&(i-p[i]+1<=1||i+p[i]-1>=len-1))vis=i,max_len=p[i]-1;
    } 
	for (int i=vis-max_len;i<=vis+max_len;i++)
		if (s_new[i]>='a'&&s_new[i]<='z')putchar(s_new[i]);
}
void solve(){
	scanf("%s",t+1);
	int n=strlen(t+1);
	for (int i=1,j=n;i<j;i++,j--)
		if (t[i]!=t[j]){
			for (int k=1;k<i;k++)putchar(t[k]);
			for (int k=i;k<=j;k++)s[k-i]=t[k];
			Manacher();
			for (int k=j+1;k<=n;k++)putchar(t[k]);
			puts("");
			for (int i=0;i<=3*n+10;i++)p[i]=t[i]=s[i]=s_new[i]=0;
			return;
		}
	for (int i=1;i<=n;i++)putchar(t[i]);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--)solve();
}