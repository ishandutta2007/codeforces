#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[100009];
struct pp{char c;int num,flag;}a[109];
bool cmp(pp x,pp y){
	return x.num<y.num;
}
bool cmpp(pp x,pp y){
	return x.c<y.c;
}
int main(){
	int ans=0;
	scanf("%s%d",s,&m);n=strlen(s);
	if(n<=m){
		printf("0\n");
		return 0;
	}
	for(int i=0;i<n;i++){
		if(a[s[i]-'a'+1].num==0) ans++;
		a[s[i]-'a'+1].num++;
	}
	for(int i=1;i<=26;i++) a[i].c='a'+i-1,a[i].flag=1;
	for(int i=1;i<=26;i++) if(a[i].num==0) a[i].num=1e9;
	sort(a+1,a+26+1,cmp);
	for(int i=1;i<=26;i++){
		if(a[i].num<=m) m-=a[i].num,a[i].flag=0,ans--;		
	}	
	sort(a+1,a+26+1,cmpp);
	printf("%d\n",ans);
	for(int i=0;i<n;i++)
		if(a[s[i]-'a'+1].flag==1) printf("%c",s[i]);
	return 0;
}