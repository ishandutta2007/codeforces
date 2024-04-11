#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 105

int T;

int n;

int f[N];
inline int fnd(int x){
	return f[x]?f[x]=fnd(f[x]):x;
}

int p[N];
inline bool q1(int u,int v){
	printf("1 %d %d\n",u-1,v-1);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}
int st[N],top;
std::vector<int> ver;
inline bool q2(int x){
	ver.clear();
	printf("2 %d ",x-1);
	for(int i=1;i<=top;i++)
		for(int j=1;j<=n;j++)
			if(fnd(j)==fnd(st[i]))
				ver.push_back(j);
	printf("%d ",ver.size());
	for(auto u:ver)
		printf("%d ",u-1);
	puts("");
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}
int pos[N];
inline void sol(){
	memset(f,0,sizeof(f));
	memset(p,0,sizeof(p));
	memset(st,0,sizeof(st));
	top=0;
	memset(pos,0,sizeof(pos));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		f[i]=0;
	p[1]=1;
	for(int i=2;i<=n;i++){
		if(q1(i,p[1])){
			for(int j=i;j>1;j--)
				p[j]=p[j-1];
			p[1]=i;
			continue;
		}
		if(q1(p[i-1],i)){
			p[i]=i;
			continue;
		}
		int L=1,R=i-1;
		while(1){
			if(L+1==R){
				for(int j=i;j>R;j--)
					p[j]=p[j-1];
				p[R]=i;
				break;
			}
			int mid=(L+R)>>1;
			if(q1(p[mid],i))
				L=mid;
			else
				R=mid;
		}
	}
	top=0;
	for(int i=1;i<=n;i++){
		while(top&&q2(p[i])){
			f[fnd(p[i])]=fnd(st[top]);
			top--;
		}
		st[++top]=p[i];
	}
	for(int i=1;i<=top;i++)
		pos[fnd(st[i])]=i;
	puts("3");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			putchar(pos[fnd(i)]<=pos[fnd(j)]?'1':'0');
		puts("");
	}
	fflush(stdout);
	int tmp;
	scanf("%d",&tmp);
}

int main(){
	scanf("%d",&T);
	while(T--)
		sol();
}