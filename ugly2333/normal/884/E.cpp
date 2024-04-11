//CF 884E
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
int n,m,p[16666],f[16666],a[16666],b[33333];
char ch[16666];
int fnd(int x){
	if(f[x]==x)
		return x;
	return f[x]=fnd(f[x]);
}
int main()
{
	int i,j,x,y,l,ans,s,pp;
	ans=0;
	s=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i=i+1){
		scanf("%s",&ch);
		for(j=0;j<m/4;j=j+1){
			if(ch[j]>=65)
				x=ch[j]-55;
			else
				x=ch[j]-48;
			a[4*j+1]=(x>>3)&1;
			a[4*j+2]=(x>>2)&1;
			a[4*j+3]=(x>>1)&1;
			a[4*j+4]=(x>>0)&1;
		}
		for(j=1;j<=m;j=j+1){
			b[j]=0;
			if(a[j]){
				if(!a[j-1])
					pp=0,x=j;
				if(p[j]){
					if(!pp)
						pp=p[j];
					else{
						if(fnd(p[j])!=fnd(pp)){
							f[fnd(max(p[j],pp))]=fnd(min(p[j],pp));
							ans--;
						}
					}
				}
				if(!a[j+1]){
					if(!pp){
						pp=++s;
						f[s]=s;
						ans++;
					}
					pp=fnd(pp);
					while(x<=j){
						a[x]=pp;
						x++;
					}
				}
			}
		}
		s=0;
		for(j=1;j<=m;j=j+1){
			if(a[j]){
				p[j]=fnd(a[j]);
				if(!b[p[j]])
					b[p[j]]=++s;
				p[j]=b[p[j]];
			}
			else
				p[j]=0;
			//cout<<a[j]<<' ';
		}
		//cout<<endl;
		for(j=1;j<=s;j=j+1)
			f[j]=j;
	}
	cout<<ans<<endl;
	return 0;
}
/*
6 24
555555
555555
F0F0F0
3C3C3C
555555
FFFFFF
2 24
F0F0F0
3C3C3C
2 88
DFE8DAFEFEECFBEAABEBC9
ABD86EEF9CEBFD8A4BEE9D

1101111111101000110110101111111011111110111011001111101111101010101010111110101111001001
1010101111011000011011101110111110011100110110111111110110001010010010111110111010011101
*/