//CF1621F
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 1<<18;
const LL inf = 1e18;
int n,m,a,b,c,e,t,o,oo;
LL ans,cur;
char s[N];
vector<int> v;
vector<pair<int,int> > p,pp;
void go1(){
	while(e<m&&p[e].second<=1){
		e++;
	}
	if(e>=m){
		while(t<m&&p[t].second==0){
			t++;
		}
		if(t>=m){
			cur=-inf;
			return;
		}
		p[t].second--;
		cur-=c;
		if(p[t].first==-1)
			o++;
		return;
	}
	ans=max(ans,cur+a);
	if(o==0){
		while(t<m&&p[t].second==0){
			t++;
		}
		if(t>=m||p[t].second>1||p[t].first==0){
			cur=-inf;
			return;
		}
		p[t].second--;
		cur-=c;
		o++;
		return;
	}
	cur+=a;
	p[e].second--;
}
void go2(){
	if(o==0){
		cur=-inf;
		return;
	}
	o--;
	cur+=b;
}
int main()
{
	int T,i,x;
	int uu=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%s",&n,&a,&b,&c,s+1);
		v.clear();
		x=0;
		for(i=1;i<=n+1;i++){
			if(s[i]=='0')
				x++;
			else{
				if(x)
					v.push_back(x);
				x=0;
			}
		}
		if(v.size()==0){
			if(n>=2)
				printf("%d\n",b);
			else
				printf("0\n");
			continue;
		}
		if(v[0]==n){
			if(n>=2)
				printf("%d\n",a);
			else
				printf("0\n");
			continue;
		}
		m=v.size();
		p.clear();
		if(m==1)
			p.push_back(make_pair(-(s[1]=='1'&&s[n]=='1'),v[0]));
		else{
			p.push_back(make_pair(-(s[1]=='1'),v[0]));
			p.push_back(make_pair(-(s[n]=='1'),v[m-1]));
			for(i=1;i<=m-2;i++)
				p.push_back(make_pair(-1,v[i]));
		}
		sort(p.begin(),p.end());
		//for(i=0;i<m;i++)cout<<p[i].first<<' '<<p[i].second<<endl;
		o=0;
		for(i=2;i<=n;i++)
			if(s[i-1]=='1'&&s[i]=='1')
				o++;
		pp=p,oo=o;
		ans=0;
		cur=0,e=0,t=0;
		for(i=1;i<=n;i++){
			if(i&1)
				go1();
			else
				go2();
			if(uu&&cur<0)
				cur=-inf;
			if(cur<=-inf)
				break;
			ans=max(ans,cur);
		}
		p=pp,o=oo;
		cur=0,e=0,t=0;
		for(i=1;i<=n;i++){
			if(i&1)
				go2();
			else
				go1();
			if(uu&&cur<0)
				cur=-inf;
			if(cur<=-inf)
				break;
			//cout<<i<<' '<<o<<endl;
			ans=max(ans,cur);
		}
		printf("%lld\n",ans);
	}
	return 0;
}