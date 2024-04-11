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
#define int long long
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
int n=read(),m=read(),a[500005];
int l[5005],r[5005],blk,bel[500005],tag[5005];
multiset<int> pos[5005];
const int BLOCK_SZ=700;
signed main(){
	fz(i,1,n)	a[i]=read();
	blk=(n-1)/BLOCK_SZ+1;
	fz(i,1,blk){
		l[i]=(i-1)*BLOCK_SZ+1;
		r[i]=min(i*BLOCK_SZ,n);
		fz(j,l[i],r[i])	bel[j]=i;
//		cout<<l[i]<<" "<<r[i]<<endl;
	}
	fz(i,1,blk){
		fz(j,l[i],r[i])
			pos[i].insert(a[j]);
	}
	while(m--){
		int opt=read();
		if(opt==1){
			int L=read(),R=read(),x=read();
			int l0=bel[L],r0=bel[R];
//			cout<<l0<<" "<<r0<<endl;
			if(l0==r0){
				pos[l0].clear();
				fz(i,L,R){
					a[i]+=x;
				}
				fz(i,l[l0],r[l0])	pos[l0].insert(a[i]);
			}
			else{
				for(int i=l0+1;i<r0;i++)	tag[i]+=x;
				pos[l0].clear();
				fz(i,L,r[l0]){
					a[i]+=x;
				}
				fz(i,l[l0],r[l0])	pos[l0].insert(a[i]);
				pos[r0].clear();
				fz(i,l[r0],R){
					a[i]+=x;
				}
				fz(i,l[r0],r[r0])	pos[r0].insert(a[i]);
			}
		}
		else{
			int x=read();
			int L=0,R=0;
			fz(i,1,blk){
				if(pos[i].find(x-tag[i])!=pos[i].end()){
					bool flag=0;
					fz(j,l[i],r[i]){
//						cout<<a[j]<<endl;
//						cout<<a[j]+tag[i]<<" "<<x<<endl;
						if((a[j]+tag[i])==x){
							L=j;
							flag=1;
							break;
						}
					}
					if(flag)	break;
				}
			}
			fd(i,blk,1){
				if(pos[i].find(x-tag[i])!=pos[i].end()){
					bool flag=0;
					fd(j,r[i],l[i]){
						if(a[j]+tag[i]==x){
							R=j;
							flag=1;
							break;
						}
					}
					if(flag)	break;
				}
			}
			if(L==0||R==0)	puts("-1");
			else			cout<<R-L<<endl;
		}
	}
	return 0;
}