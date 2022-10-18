#include<bits/stdc++.h>
#define N 1000005

char buf[1<<23],*p1=buf,*p2=buf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<23,stdin),p1==p2)?EOF:*p1++)
inline void rd(int &x){
	x=0;
	char c=getchar();
	while(c<'0'||c>'9')
		c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}

int T;

int n,m,a[N],b[N],c[N];

int main(){
	rd(T);
	while(T--){
		rd(n),rd(m);
		for(int i=1;i<=n;i++)
			rd(a[i]),c[a[i]]++;
		for(int i=1;i<=m;i++)
			c[i]+=c[i-1];
		bool flg=1;
		for(int i=1;i<=m;i++) if(c[i]-c[i-1])
			for(int j=i,t=1;j<=m;j+=i,t++)
				if(c[std::min(m,j+i-1)]-c[j-1]&&!(c[t]-c[t-1]))
					flg=0;
		puts(flg?"Yes":"No");
		for(int i=1;i<=m;i++)
			b[i]=c[i]=0;
	}
}