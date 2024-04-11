#include<bits/stdc++.h>//luogu
using namespace std;
int n;
int a[210000];
int fa[210000];
int cnt=0;
long long ans=0;
int find(int i){
	if(fa[i]==i)return i;
	return fa[i]=find(fa[i]);
}
int o[1<<18];
int oo[1<<18];
int s[210000];
int t[210000];
int f[210000];
bool cmp(int i,int j,int i1,int j1){
	if(a[i]+a[j]!=a[i1]+a[j1]) return a[i]+a[j]>a[i1]+a[j1];
	return (long long)(n+1)*(min(i,j)-min(i1,j1))+max(i,j)-max(i1,j1)<0;
}
int main(){
	scanf("%d",&n);
	cnt=n+1;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	a[n+1]=-1;
	a[0]=0;
	for(int i=0;i<=n;i++)fa[i]=i;
	while(cnt>1){
		for(int i=0;i<=n;i++)f[i]=find(i);
		f[n+1]=n+1;
		for(int i=0;i<(1<<18);i++) o[i]=n+1;
		for(int i=0;i<(1<<18);i++) oo[i]=n+1;
		for(int i=0;i<=n;i++){
			if(o[a[i]]==n+1){
				o[a[i]]=i;
				continue;
			}
			if(oo[a[i]]==n+1){
				if(f[i]!=f[o[a[i]]]) oo[a[i]]=i;
			}
		}
		for(int i=0;i<18;i++){
			for(int j=0;j<(1<<18);j++){
				if((j>>i)&1){
					int k=(j^(1<<i));
					if(a[o[j]]<a[o[k]]){
						if(a[oo[j]]<a[oo[k]]) oo[j]=oo[k];
						if((f[o[j]]!=f[oo[j]])&&(a[o[j]]>a[oo[j]] || ((a[o[j]]==a[oo[j]])&&(o[j]<oo[j]))))oo[j]=o[j];
						o[j]=o[k];
					}
					else{
						if(f[o[j]]!=f[o[k]] && a[oo[j]]<a[o[k]]){
							oo[j]=o[k];
							continue;
						}
						if(f[o[j]]!=f[oo[k]] && a[oo[j]]<a[oo[k]])oo[j]=oo[k];
					}
				}
			}
		}
		for(int i=0;i<=n;i++)s[i]=t[i]=n+1;
		for(int i=0;i<=n;i++){
			int tt=(1<<18)-1-a[i];
			if(o[tt]==n+1) continue;
			if(f[i]==f[o[tt]]){
				if(oo[tt]==n+1) continue;
				if(cmp(i,oo[tt],s[f[i]],t[f[i]])){
					s[f[i]]=i;
					t[f[i]]=oo[tt];
				}
			}
			else{
				if(cmp(i,o[tt],s[f[i]],t[f[i]])){
					s[f[i]]=i;
					t[f[i]]=o[tt];
				}
			}
		}
		for(int i=1;i<=n;i++)if(f[i]==i){
			int ss=find(s[i]);
			int tt=find(t[i]);
			if(ss!=tt){
				fa[ss]=tt;
				ans+=a[s[i]]+a[t[i]];
				cnt--;
			}
		}
	}
	for(int i=0;i<=n;i++)ans-=a[i];
	cout<<ans;
	return 0;
}