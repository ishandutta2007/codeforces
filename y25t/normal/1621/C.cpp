#include<bits/stdc++.h>
#define N 10005

int T;

int n;

int p[N];

int t;
inline int qry(int x){
	t++;
	printf("? %d\n",x);
	fflush(stdout);
	static int res;
	scanf("%d",&res);
	return res;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			p[i]=0;
		t=0;
		for(int i=1;i<=n;i++) if(!p[i]){
			std::vector<int> c;
			int x=qry(i);
			while(1){
				c.push_back(qry(i));
				if(c.back()==x)
					break;
			}
			for(int o=0;o<(int)c.size()-1;o++)
				p[c[o]]=c[o+1];
			p[c.back()]=c[0];
		}
		printf("!");
		for(int i=1;i<=n;i++)
			printf(" %d",p[i]);
		puts("");
		fflush(stdout);
	}
}