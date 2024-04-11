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
#define y1			y_chenxiaoyan_1
#define y0			y_chenxiaoyan_0
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
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
int n=read(),m=read(),k=read();
signed main(){
	if(k>(4*n*m-2*n-2*m)){
		puts("NO");
		return 0;
	}
	n--;m--;
	puts("YES");
	vector<pair<char,int> > v;
	fz(i,1,n){
		if(!k)	break;
		if(k<=m){
			v.push_back({'R',k});
			k=0;
		}
		else{
			v.push_back({'R',m});
			k-=m;
		}
		if(k){
			if(k<=m){
				v.push_back({'L',k});
				k=0;
			}
			else{
				v.push_back({'L',m});
				k-=m;
			}
			if(k){
				v.push_back({'D',1});
				k--;
			}
		}
	}
	if(k){
		if(k<=m){
			v.push_back({'R',k});
			k=0;
		}
		else{
			v.push_back({'R',m});
			k-=m;
		}
		if(k){
			fz(i,1,m){
				if(!k)	break;
				if(k<=n){
					v.push_back({'U',k});
					k=0;
				}
				else{
					v.push_back({'U',n});
					k-=n;
				}
				if(k){
					if(k<=n){
						v.push_back({'D',k});
						k=0;
					}
					else{
						v.push_back({'D',n});
						k-=n;
					}
					if(k){
						v.push_back({'L',1});
						k--;
					}
				}
			}
			if(k){
				if(k<=n){
					v.push_back({'U',k});
					k=0;
				}
				else{
					v.push_back({'U',n});
					k-=n;
				}
			}
		}
	}
	assert(k==0);
	int cnt=0;
	for(int i=0;i<v.size();i++){
		if(v[i].second!=0)	cnt++;
	}
	cout<<cnt<<endl;
	for(int i=0;i<v.size();i++){
		if(v[i].second!=0){
			cout<<v[i].second<<" "<<v[i].first<<endl;
		}
	}
	return 0;
}