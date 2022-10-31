#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <complex>
#include <cmath>
#include <cstring>
#include <map>
#include <string>

using namespace std;
typedef long long lli;
typedef pair<lli, lli> pll;
typedef pair<int, int> pii;
const lli mod=1e9+7;
const lli inf=2e18;

inline int _abs(int a) {
	return a<0 ? -a : a;
}
inline lli _abs(lli a) {
	return a<0 ? -a : a;
}

int vis[256],arr[256];
string str[256];

void push(int val,string s) {
	if(!vis[val] && (arr[val]==-1 || arr[val]>(int)s.size() || (arr[val]==(int)s.size() && str[val]>s) )) {
		arr[val]=s.size(); str[val]=s;
	}
}
string GetStr(string s,char op,int flag) {
	if(flag) {
		int c=0;
		for(auto &it:s) {
			if(it=='(') c++;
			else if(it==')') c--;
			else if(c==0 && (it=='&' || it=='|')) {
				return "!("+s+")";
			}
		}
		return "!"+s;
	}
	else {
		int c=0;
		for(auto &it:s) {
			if(it=='(') c++;
			else if(it==')') c--;
			else if(c==0 && op=='&' && it=='|') {
				return "("+s+")";
			}
		}
		return s;
	}
}
string get(int v1,int v2,char op,int f1,int f2) {
	string res,s1,s2;

	s1=GetStr(str[v1],op,f1);
	s2=GetStr(str[v2],op,f2);
	if(s1<s2) {
		res=s1; res.push_back(op); res+=s2;
	}
	else {
		res=s2; res.push_back(op); res+=s1;
	}
	return res;
}
int not_op(int val) {
	int res=0;
	for(int i=0;i<8;i++) {
		res|=(val&(1<<i)) ? 0 : 1<<i;
	}
	return res;
}
int main() {
	memset(arr,-1,sizeof(arr));
	arr[15]=arr[51]=arr[85]=1;
	str[15]="x"; str[51]="y"; str[85]="z";
	
	for(int c=0;c<256;c++) {
		int mx=500,val=-1;
		string s="";
		for(int j=0;j<256;j++) {
			if(!vis[j] && arr[j]!=-1 && (mx>arr[j] || (mx==arr[j] && s>str[j]))) {
				mx=arr[j];
				val=j;
				s=str[j];
			}
		}
		vis[val]=1;
		for(int j=0;j<256;j++) if(vis[j]) {
			int tv;
			string tmp,s1,s2;

			tv=val|j;
			tmp=get(val,j,'|',0,0);
			push(tv,tmp);
			
			tv=not_op(val)|j;
			tmp=get(val,j,'|',1,0);
			push(tv,tmp);

			tv=val|not_op(j);
			tmp=get(val,j,'|',0,1);
			push(tv,tmp);
			
			tv=not_op(val)|not_op(j);
			tmp=get(val,j,'|',1,1);
			push(tv,tmp);

			tv=val&j;
			tmp=get(val,j,'&',0,0);
			push(tv,tmp);

			tv=not_op(val)&j;
			tmp=get(val,j,'&',1,0);
			push(tv,tmp);

			tv=val&not_op(j);
			tmp=get(val,j,'&',0,1);
			push(tv,tmp);
			
			tv=not_op(val)&not_op(j);
			tmp=get(val,j,'&',1,1);
			push(tv,tmp);
		}
		int tv;
		string tmp;

		tv=not_op(val);
		tmp=GetStr(str[val],'|',1);
	
		push(tv,tmp);
	}

	int n;
	scanf("%d",&n);
	char tt[10];
	while(n--) {
		scanf("%s",tt);
		
		int res=0;
		for(int i=0;i<8;i++) {
			res=res*2+tt[i]-'0';
		}
		printf("%s\n",str[res].c_str());
	}

	
	return 0;
}