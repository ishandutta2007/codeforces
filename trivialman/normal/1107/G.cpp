#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const int N = 300010;

struct dat{
	LL s,gap;
}stk[N];

int n,a,top,j,c[N],d[N];
LL s[N],ans;

int main(){
	scanf("%d%d",&n,&a);
	s[0]=0;
	rep(i,1,n)scanf("%d%d",d+i,c+i),c[i]=a-c[i],s[i]=s[i-1]+c[i];
	ans = max(0, *max_element(c+1,c+n+1));
	rep(i,1,n-1){
		while(top&&stk[top].s>=s[i-1])--top;
		LL gap = d[i+1]-d[i]; gap*=gap;
		dat tmp = stk[top];
		if(!top || gap<=tmp.gap){
			if(!top || tmp.gap+tmp.s>gap+s[i-1]) stk[++top]={s[i-1],gap};
		}else{
			for(j=top;j&&stk[j].gap<gap;--j)stk[j].gap=gap;
			if(j<top) top = (j && stk[j].gap+stk[j].s<=stk[j+1].gap+stk[j+1].s) ? j : j+1;
		}
		ans = max(ans, s[i+1]-(stk[top].s+stk[top].gap));
	}
	cout<<ans<<endl;
	return 0;
}