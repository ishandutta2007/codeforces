#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;


const int N=800005;
char ch[N];
int nxt[N],pre[N],q[N];
int a[N],b[N],n,vis[N];
int La[N],Ra[N],Lb[N],Rb[N];
vector<int> ans;

void Link(int x,int y){
	nxt[x]=y; pre[y]=x;
}
pair<int,int> solve(int l,int r){
	//cout<<"solve "<<l<<' '<<r<<endl;
	if (l>r) return pair<int,int>(q[l],q[l]);
	if (ch[l]!=ch[r]){
		pair<int,int> re=solve(l+1,r-1); r++;
		if ((ch[l]=='0')^(l&1)) swap(l,r);
		Link(q[l],re.first);
		Link(re.second,q[r]);
		return pair<int,int>(q[l],q[r]);
	}
	int m=-1;
	int pl=l,pr=r,sl=0,sr=0;
	for (;;){
		sl+=(ch[pl]=='0'?-1:1);
		sr+=(ch[pr]=='0'?-1:1);
		if (sl==0) m=pl;
		if (sr==0) m=pr-1;
		++pl; --pr;
		if (m!=-1) break; 
	}
	pair<int,int> info1=solve(l,m);
	int tpre=pre[q[m+1]],tnxt=nxt[q[m+1]];
	pre[q[m+1]]=nxt[q[m+1]]=0;
	pair<int,int> info2=solve(m+1,r);
	if (info2.first==q[m+1]){
		Link(info2.second,tnxt);
		Link(tpre,info2.first);
		int ned=(tnxt?info1.second:info2.second);
		return pair<int,int>(info1.first,ned);
	}
	else{
		Link(tpre,info2.first);
		Link(info2.second,tnxt);
		int nst=(tpre?info1.first:info2.first);
		return pair<int,int>(nst,info1.second);
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=2*n;i++){
		scanf("%d%d",&a[i],&b[i]);
		if (a[i]>0) La[a[i]]=i;
		else Ra[-a[i]]=i;
		
		if (b[i]>0) Lb[b[i]]=i;
		else Rb[-b[i]]=i;
	}
	
	for (int id=1;id<=2*n;id++)
		if (!vis[id]){
			*q=0;
			for (int x=id;;){
				q[++*q]=x;
				vis[x]=1;
				if (a[x]>0){
					ch[*q]='1';
					x=Ra[a[x]];
				}
				else{
					ch[*q]='0';
					x=La[-a[x]];
				}
				
				q[++*q]=x;
				vis[x]=1;
				if (b[x]>0){
					ch[*q]='0';
					x=Rb[b[x]];
				}
				else{
					ch[*q]='1';
					x=Lb[-b[x]];
				}
				
				if (x==id) break;
			}
			
			int sum=0;
			for (int i=1;i<=*q;i++)
				sum+=(ch[i]=='1');
			if (sum<(*q)/2){
				for (int i=1;i<=*q;i++) ch[i]^=1;
				sum=(*q)-sum;
			}
			if (sum!=(*q)/2+1){
				puts("NO");
				return 0;
			}
			
			for (int i=1;i<=*q;i++){
				q[(*q)+i]=q[i];
				ch[(*q)+i]=ch[i];
			}
			int l=1;
			for (;ch[l]!='1'||ch[l+1]!='1';l+=2);
			
			//for (int i=l+1;i<=l+(*q);i++)
			//	printf("%d %c\n",q[i],ch[i]);
			//puts("114514");
			vector<int> temp;
			pair<int,int> re=solve(l+2,l+(*q)-1);
			temp.push_back(q[l+1]);
			for (int i=re.first;i;i=nxt[i])
				temp.push_back(i);
			
			if (a[temp[0]]<0)
				reverse(temp.begin(),temp.end());
				
			for (auto i:temp)
				ans.push_back(i);
		}
	puts("YES");
	for (auto i:ans)
		printf("%d %d\n",a[i],b[i]);
}

/*
1 2
2 -2
3 1
-3 3
-2 -3
4 -1
-4 4
-1 -4
*/