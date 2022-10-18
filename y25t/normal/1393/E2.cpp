#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

#define P 1000000007
#define N 100005
#define M 1000005

inline int fp(int x,int k){
	int res=1;
	for(;k;k>>=1,x=1ll*x*x%P)
		if(k&1)
			res=1ll*res*x%P;
	return res;
}

int n,m;
char str[M];

std::vector<int> s[N];

std::vector<int> pos[N],nxt;

const int X=37,iX=fp(X,P-2);
std::vector<int> hsh[N];

std::vector<int> f[N];

inline void init(int x){
	f[x].resize(s[x].size());
	pos[x].resize(s[x].size());
	nxt.resize(s[x].size());
	hsh[x].resize(s[x].size());
	nxt[s[x].size()-1]=s[x].size()-1;
	for(int i=s[x].size()-2;i>=0;i--)
		nxt[i]=s[x][i]==s[x][i+1]?nxt[i+1]:i+1;
	int l=0,r=s[x].size()-1;
	for(int i=0;i<s[x].size();i++)
		if(s[x][i]>s[x][nxt[i]])
			pos[x][l++]=i;
		else
			pos[x][r--]=i;
	hsh[x][0]=s[x][0];
	for(int i=1,tmp=X;i<s[x].size();i++,tmp=1ll*tmp*X%P)
		hsh[x][i]=(hsh[x][i-1]+1ll*s[x][i]*tmp%P)%P;
//	printf("&%d\n",x);
//	for(int i=0;i<s[x].size();i++)
//		printf("%d ",pos[x][i]);
//	puts("");
} 

inline int gethsh(int x,int i,int j){
	return j<i?hsh[x][j]:(1ll*(hsh[x][j+1]-hsh[x][i]+P)*iX%P+(i?hsh[x][i-1]:0))%P;
}
inline bool cmp(int x,int i,int y,int j){//x<=y
	int l=0,r=std::min(s[x].size(),s[y].size())-2,k=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(gethsh(x,i,mid)==gethsh(y,j,mid)){
			k=mid+1;
			l=mid+1;
		}
		else
			r=mid-1;
	}
//	printf("!%d %d %d %d %d\n",x,i,y,j,k);
	if(k==std::min(s[x].size(),s[y].size())-1)
		return s[x].size()<=s[y].size()||(s[x].size()-1==s[y].size()&&j==s[y].size()-1&&i<s[x].size()-1);
	return s[x][k+(k>=i)]<s[y][k+(k>=j)];
}

int ans;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",str);
		m=strlen(str);
		for(int j=0;j<m;j++)
			s[i].push_back(str[j]-'a'+2);
		s[i].push_back(1);
		init(i);
	}
	for(int i=0;i<s[1].size();i++)
		f[1][i]=1;
	for(int i=2;i<=n;i++){
		for(int j=0,k=0,tmp=0;j<s[i].size();j++){
			while(k<s[i-1].size()&&cmp(i-1,pos[i-1][k],i,pos[i][j])){
				tmp=(tmp+f[i-1][pos[i-1][k]])%P;
				k++;
			}
			f[i][pos[i][j]]=tmp;
//			printf("*%d %d %d %d\n",i,j,k,tmp);
		}
	}
	for(int i=0;i<s[n].size();i++)
		ans=(ans+f[n][i]%P)%P;
	printf("%d\n",ans);
}