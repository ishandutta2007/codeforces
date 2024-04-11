#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const int N=100005,base=233;
char ch[N];
#define ull unsigned long long
ull ycl[N],has[N];
int n,pos,quan,sum[N][26];
ll dq,mx,ans,zs[26];
inline int Sum(int x,int y){
	return sum[x][y]+(pos<=x?(quan==y)-(ch[pos]==y):0);
}
inline ull cal(int l,int r){
	return (has[r]-has[l]*ycl[r-l])+((l<pos&&pos<=r)?(quan-ch[pos])*ycl[r-pos]:0);
}
int tot;
void dfs(int l,int r){
	//if(pos==5&&quan=='j'-'a')cout<<l<<" "<<r<<endl;
	int tmp=r+1; tot++;
	dq+=(ll)(r-l+1)*(r-l+1); //cout<<l<<" "<<r<<" "<<dq<<endl;
	//if(tmp*2-l<=n&&Sum(tmp*2-l,ch[tmp])-Sum(l-1,ch[tmp])==1&&cal(l,tmp)==cal(tmp,tmp*2-l))cout<<l<<" "<<r<<" "<<pos<<" "<<quan<<endl;
	if(tmp*2-l<=n&&Sum(tmp*2-l,ch[tmp])-Sum(l-1,ch[tmp])==1&&cal(l-1,tmp-1)==cal(tmp,tmp*2-l))dfs(l,tmp*2-l);
	tmp=l-1;
	//if(tmp*2-r>0&&Sum(r,ch[tmp])-Sum(tmp*2-r-1,ch[tmp])==1&&cal(tmp*2-r-1,tmp-1)==cal(tmp,r))cout<<l<<" "<<r<<" "<<pos<<" "<<quan<<endl;
	if(tmp*2-r>0&&Sum(r,ch[tmp])-Sum(tmp*2-r-1,ch[tmp])==1&&cal(tmp*2-r-1,tmp-1)==cal(tmp,r))dfs(tmp*2-r,r);
}
int yyy[N],wzp[N]; 
signed main(){
	scanf("%s",ch+1);
	n=strlen(ch+1); ycl[0]=1;
	for(int i=1;i<=n;i++){
		ch[i]-='a';
		for(int j=0;j<26;j++)sum[i][j]=sum[i-1][j]; sum[i][ch[i]]++;
		has[i]=has[i-1]*base+ch[i]; ycl[i]=ycl[i-1]*base;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<i&&i+j<=n;j=j*2+1){
			//cout<<ycl[1]<<" "<<cal(i-j-1,i-1)<<" "<<cal(i,i+j)<<" "<<sum[i+j][ch[i]]-sum[i-j-1][ch[i]]<<endl;
			if(cal(i-j-1,i-1)!=cal(i,i+j)||sum[i+j][ch[i]]-sum[i-j-1][ch[i]]>1||yyy[i-(j+1)/2]<j/2)break;
			ans+=(ll)(j*2+1)*(j*2+1); yyy[i]=j; 
		}
	}
	for(int i=1;i<=n;i++){
		pos=0;
		for(int j=0;j<i&&i+j<=n;j=j*2+1){
			//cout<<i<<" "<<j<<" "<<cal(i-j-1,i-1)<<" "<<endl;
			if(cal(i-j-1,i-1)!=cal(i,i+j)||yyy[i-(j+1)/2]<j/2)break; wzp[i]=j;
		}
		for(int k=0;k<26;k++){
			pos=i; quan=k; dq=ans; //cout<<cal(0,1)<<" "<<cal(2,3)<<endl;
			//if(pos==2&&quan==1)cout<<Sum(2,1)<<endl;
			for(int j=0;j<i&&i+j<=n&&j<=wzp[i];j=j*2+1){
				if(Sum(i+j,k)-Sum(i-j-1,k)>1||yyy[i-(j+1)/2]<j/2)break;
				dfs(i-j,i+j); 
				//cout<<i<<" "<<k<<" "<<j<<" "<<wzp[i]<<endl;
			}
			zs[k]=dq;
		}
		for(int j=0;j<26;j++){
			mx=max(mx,ans+zs[j]-zs[ch[i]]);
		}
	}
	cout<<mx<<endl;
}