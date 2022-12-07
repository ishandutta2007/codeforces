#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define PB push_back
using namespace std;


char s[105];

struct node{
	int n,m;
	vector<vector<char>> s;
	node(){}
	node(int _n,int _m){
		n=_n; m=_m;
		s.resize(n);
		For(i,0,n-1){
			s[i].resize(m);
			For(j,0,m-1) s[i][j]=' ';
		}
	}
	void print(){
		printf("%d %d\n",n,m);
		For(i,0,n-1){
			For(j,0,m-1) putchar(s[i][j]);
			puts("");
		}
	}
};


node Doop(node a,int l,int r){
	for (;l<=r;++l){
		if (s[l]=='+'){
			node b(a.n+2,a.m+6);
			For(i,0,a.n-1) For(j,0,a.m-1)
				b.s[i][j+3]=a.s[i][j];
			b.s[1][0]='+'; b.s[1][1]='-'; b.s[1][2]='>';
			b.s[1][a.m+3]='-'; b.s[1][a.m+4]='>'; b.s[1][a.m+5]='+';
			For(i,2,b.n-2) b.s[i][0]=b.s[i][b.m-1]='|';
			For(i,0,b.m-1) b.s[b.n-1][i]='-';
			b.s[b.n-1][0]=b.s[b.n-1][b.m-1]='+';
			b.s[b.n-1][1]='<';
			a=b;
		}
		if (s[l]=='?'){
			node b(a.n+3,a.m+6);
			For(i,0,a.n-1) For(j,0,a.m-1)
				b.s[i+3][j+3]=a.s[i][j];
			b.s[4][0]='+'; b.s[4][1]='-'; b.s[4][2]='>';
			b.s[4][a.m+3]='-'; b.s[4][a.m+4]='>'; b.s[4][a.m+5]='+';
			b.s[3][0]=b.s[3][b.m-1]='|'; b.s[2][0]=b.s[2][b.m-1]='|';
			For(i,0,b.m-1) b.s[1][i]='-';
			b.s[1][0]=b.s[1][b.m-1]='+';
			b.s[1][b.m-2]='>';
			a=b;
		}
		if (s[l]=='*'){
			node b(a.n+5,a.m+6);
			For(i,0,a.n-1) For(j,0,a.m-1) b.s[i+3][j+3]=a.s[i][j];
			For(i,1,b.n-1) b.s[i][0]=b.s[i][b.m-1]='|';
			b.s[4][0]='+'; b.s[4][1]='-'; b.s[4][2]='>';
			b.s[4][a.m+3]='-'; b.s[4][a.m+4]='>'; b.s[4][a.m+5]='+';
			
			For(i,0,b.m-1) b.s[1][i]=b.s[b.n-1][i]='-';
			b.s[1][0]=b.s[1][b.m-1]='+';
			b.s[b.n-1][0]=b.s[b.n-1][b.m-1]='+';
			b.s[1][b.m-2]='>'; b.s[b.n-1][1]='<';
			a=b;
		}
	}
	return a;
}

node str(int l,int r){
	node a(3,r-l+1 + 4);
	For(i,0,2) a.s[i][0]=a.s[i][r-l+1 + 3]='+';
	For(i,1,r-l+1 + 2) a.s[0][i]=a.s[2][i]='-';
	For(i,l,r) a.s[1][i-l + 2]=s[i];
	return a;
}

node Add(node a,node b){
	node c(max(a.n,b.n),a.m+b.m+2);
	For(i,0,a.n-1) For(j,0,a.m-1) c.s[i][j]=a.s[i][j];
	For(i,0,b.n-1) For(j,0,b.m-1) c.s[i][j+a.m+2]=b.s[i][j];
	c.s[1][a.m]='-';
	c.s[1][a.m+1]='>';
	return c;
}

node solve_3(int l,int r){
	vector<node> stk;
	for (;l<=r;)
		if ('A'<=s[l]&&s[l]<='Z'){
			int p=l;
			for (;p<=r&&'A'<=s[p]&&s[p]<='Z';++p);
			if (p>r) stk.PB(str(l,p-1));
			else{
				if (p-1!=l) stk.PB(str(l,p-2));
				stk.PB(str(p-1,p-1));
			}
			l=p;
		}
		else{
			node temp=stk.back();
			stk.pop_back();
			stk.push_back(Doop(temp,l,l));
			++l;
		}
	
	node res=stk[0];
	For(i,1,stk.size()-1) res=Add(res,stk[i]);
	return res;
}

node solve(int l,int r);

node solve_1(int l,int r,vector<int> p){
	vector<node> sta;
	for (int i=0;i<p.size()-1;i++)
		sta.PB(solve(p[i]+1,p[i+1]-1));
		
	int n=sta.size()-1,m=0;
	for (auto i:sta) n+=i.n,m=max(m,i.m);
	
	node res(n,m+6);
	For(i,1,n-1) res.s[i][0]=res.s[i][m+5]='|';
	int P=0;
	for (auto i:sta){
		res.s[P+1][0]='+';
		res.s[P+1][1]='-';
		res.s[P+1][2]='>';
		res.s[P+1][m+3]='-';
		res.s[P+1][m+4]='>';
		res.s[P+1][m+5]='+';
		For(j,0,i.n-1) For(k,0,i.m-1)
			res.s[P+j][3+k]=i.s[j][k];
		For(k,i.m,m-1)
			res.s[P+1][3+k]='-'; 
		P+=i.n+1;
	}
	P-=sta.back().n+1;
	For(i,P+2,res.n-1) res.s[i][0]=res.s[i][m+5]=' ';
	return res;
}

node solve_2(int l,int r){
	if (s[l]!='('){
		int p=l;
		for (;s[p]!='(';++p);
		return Add(solve(l,p-1),solve(p,r));
	}
	int cnt=0,p=-1;
	For(i,l,r-1){
		if (s[i]=='(') ++cnt;
		if (s[i]==')') --cnt;
		if (!cnt){
			p=i;
			break;
		}
	}
	if (p==-1) return solve(l+1,r-1);
	int pp=p+1;
	for (;pp<=r&&(s[pp]=='+'||s[pp]=='*'||s[pp]=='?');++pp);
	if (pp<=r) return Add(solve(l,pp-1),solve(pp,r));
	return Doop(solve(l+1,p-1),p+1,pp-1);
}

node solve(int l,int r){
	vector<int> p;
	p.PB(l-1);
	int cnt=0,flg=0;
	For(i,l,r){
		if (s[i]=='(') cnt++,flg=1;
		else if (s[i]==')') cnt--,flg=1;
		else if (s[i]=='|'&&cnt==0) p.PB(i); 
	}
	p.PB(r+1);
	if (p.size()!=2) return solve_1(l,r,p);
	if (flg) return solve_2(l,r);
	return solve_3(l,r);
}
node work(node a){
	node b(a.n,a.m+6);
	b.s[1][0]='S';
	b.s[1][1]='-'; 
	b.s[1][2]='>'; 
	b.s[1][a.m+3]='-'; 
	b.s[1][a.m+4]='>'; 
	b.s[1][a.m+5]='F';
	For(i,0,a.n-1) For(j,0,a.m-1) b.s[i][j+3]=a.s[i][j];
	return b; 
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%s",s+1);
	node ans=solve(1,strlen(s+1));
	ans=work(ans);
	ans.print();
}
/*
((N*|E+)*+)|((R*|C+)*+)
*/