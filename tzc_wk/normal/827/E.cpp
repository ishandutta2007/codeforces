/*




D P 




 l l
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
const double Pi=acos(-1.0);
struct comp{
	double x,y;
	comp(){x=y=0;}
	comp(double a,double b){x=a;y=b;}
	inline comp operator +(comp c){return comp(x+c.x,y+c.y);}
	inline comp operator -(comp c){return comp(x-c.x,y-c.y);}
	inline comp operator *(comp c){return comp(x*c.x-y*c.y,x*c.y+y*c.x);}
} a[1<<22],b[1<<22],p[1<<22];
int rev[1<<22];
inline void FFT(int len,comp* a,int type){
	for(int i=0;i<len;i++){
		if(i<rev[i])	swap(a[i],a[rev[i]]);
	}
	for(int mid=1;mid<len;mid<<=1){
		comp W(cos(Pi/mid),type*sin(Pi/mid));
		for(int j=0;j<len;j+=mid<<1){
			comp w(1,0);
			for(int k=0;k<mid;k++){
				comp x=a[j+k],y=w*a[j+mid+k];
				a[j+k]=x+y;
				a[j+mid+k]=x-y;
				w=w*W;
			}
		}
	}
}
int pt1[1<<22],pt2[1<<22];
inline int id(char c){
	if(c=='?')	return 0;
	if(c=='K')	return 1;
	if(c=='V')	return 2;
}
char s[1<<22],_s[1<<22];
int len=1;
int n;
inline void match(){
	for(int i=0;i<len;i++)	a[i]=b[i]=p[i]=comp(0,0),pt1[i]=pt2[i]=0;
	for(int i=0;i<n;i++)	pt1[i]=id(s[i]);
	for(int i=0;i<n;i++)	pt2[i]=id(_s[i]);
	for(int i=0;i<len;i++)	a[i]=comp(pt1[i]*pt1[i]*pt1[i],0);
	for(int i=0;i<len;i++)	b[i]=comp(pt2[i],0);
	FFT(len,a,1);FFT(len,b,1);
	for(int i=0;i<len;i++)	p[i]=p[i]+a[i]*b[i];
	for(int i=0;i<len;i++)	a[i]=comp(pt1[i],0);
	for(int i=0;i<len;i++)	b[i]=comp(pt2[i]*pt2[i]*pt2[i],0);
	FFT(len,a,1);FFT(len,b,1);
	for(int i=0;i<len;i++)	p[i]=p[i]+a[i]*b[i];
	for(int i=0;i<len;i++)	a[i]=comp(pt1[i]*pt1[i],0);
	for(int i=0;i<len;i++)	b[i]=comp(pt2[i]*pt2[i],0);
	FFT(len,a,1);FFT(len,b,1);
	for(int i=0;i<len;i++)	p[i]=p[i]-comp(2,0)*a[i]*b[i];
	FFT(len,p,-1);
	set<int> ans;
	vector<int> unans;
	for(int i=n;i<=n*2-1;i++){
		int t=int(p[i].x/len+0.5);
		if(t==0)	ans.insert(n-(2*n-1-i));
	}
//	cout<<ans.size()<<endl;
	for(int i=1;i<=n;i++)	if(ans.find(i)==ans.end()){
		unans.push_back(i);
	}
	foreach(it,unans){
		int tmp=*it;
		vector<int> fac;
		for(int i=1;i*i<=tmp;i++){
			if(tmp%i==0){
				fac.push_back(i);
				if(i!=tmp/i){
					fac.push_back(tmp/i);
				}
			}
		}
		foreach(i,fac){
			int x=*i;
			if(ans.find(x)!=ans.end())	ans.erase(ans.find(x));
		}
	}
	cout<<ans.size()<<endl;
	foreach(it,ans)	cout<<*it<<" ";puts("");
}
inline void solve(){
	n=read();cin>>s;
	len=1;
	int num=0;
	while(len<=(n<<1))	len<<=1,num++;
	for(int i=0;i<len;i++)	rev[i]=0;
	for(int i=0;i<len;i++)	rev[i]=(rev[i>>1]>>1)|((i&1)<<(num-1));
	for(int i=0;i<len;i++)	_s[i]=0;
	fz(i,0,n-1)	_s[i]=s[i];
	reverse(_s,_s+n);
	match();
}
int main(){
	int T=read();
	while(T--)	solve();
	return 0;
}