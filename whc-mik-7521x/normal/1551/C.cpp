#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c,d,e;
};
int t,n;
bool cmpa(node x,node y){
	return x.a>y.a;
} 
bool cmpb(node x,node y){
	return x.b>y.b;
} 
bool cmpc(node x,node y){
	return x.c>y.c;
} 
bool cmpd(node x,node y){
	return x.d>y.d;
} 
bool cmpe(node x,node y){
	return x.e>y.e;
} 
int main(){
	scanf("%d",&t);
	while(t--){
		node p[200005];
		memset(p,0,sizeof p);
		scanf("%d",&n);
		string s;
		for(int i=1;i<=n;i++){
			cin>>s;
			int len=s.size();
			for(int o=0;o<len;o++){
				if(s[o]=='a')p[i].a++;
				if(s[o]=='b')p[i].b++;
				if(s[o]=='c')p[i].c++;
				if(s[o]=='d')p[i].d++;
				if(s[o]=='e')p[i].e++;
			}
			p[i].a=p[i].a*2-len;
			p[i].b=p[i].b*2-len;
			p[i].c=p[i].c*2-len;
			p[i].d=p[i].d*2-len;
			p[i].e=p[i].e*2-len;
		}
		int ans=0,tot,num,rt;
		sort(p+1,p+n+1,cmpa);
		if(p[1].a>0){
			tot=p[1].a,num=1;
			while(tot>0&&num<=n){
				rt=num;
				num++;
				tot+=p[num].a;
			}
			ans=max(ans,rt);
		}
		sort(p+1,p+n+1,cmpb);
		if(p[1].b>0){
			tot=p[1].b,num=1;
			while(tot>0&&num<=n){
				rt=num;
				num++;
				tot+=p[num].b;
			}
			ans=max(ans,rt);
		}
		sort(p+1,p+n+1,cmpc);
		if(p[1].c>0){
			tot=p[1].c,num=1;
			while(tot>0&&num<=n){
				rt=num;
				num++;
				tot+=p[num].c;
			}
			ans=max(ans,rt);
		}
		sort(p+1,p+n+1,cmpd);
		if(p[1].d>0){
			tot=p[1].d,num=1;
			while(tot>0&&num<=n){
				rt=num;
				num++;
				tot+=p[num].d;
			}
			ans=max(ans,rt);
		}
		sort(p+1,p+n+1,cmpe);
		if(p[1].e>0){
			tot=p[1].e,num=1;
			while(tot>0&&num<=n){
				rt=num;
				num++;
				tot+=p[num].e;
			}
			ans=max(ans,rt);
		}
		printf("%d\n",ans);
	}
	return 0;
}