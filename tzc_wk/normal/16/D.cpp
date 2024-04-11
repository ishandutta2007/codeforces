#include <bits/stdc++.h>
using namespace std;
#define N 110
#define ll int
struct node{
	int h,m;
	int time;
};
node a[N];
int n;
char s[10000];
int main(){
	cin>>n;
	getchar();
	for(int i=1;i<=n;i++){
		gets(s);
		a[i].h=(s[1]-'0')*10+s[2]-'0';
		a[i].m=(s[4]-'0')*10+s[5]-'0';
		if(a[i].h==12)a[i].h=0;
		if(s[7]=='p') {
			a[i].h+=12;			
		}			
		a[i].time=a[i].m+a[i].h*60;
	}
	int ans=1,x=a[1].time;
	ll siz=1;
	for(int i=2;i<=n;i++) {
		if(a[i].time<x)	{
			siz=1;
			ans++;
		}
		else if(a[i].time==x)siz++;
		else siz = 1;
		if(siz>10){
			siz=1;
			ans++;
		}
		x=a[i].time;
	}
	cout<<ans<<endl;
	return 0;
}