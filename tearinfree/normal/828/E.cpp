#include <bits/stdc++.h>

const int MAX=1<<17;
int n;
char str[100010];
int tr[4][1<<18][11][10];
int arr[11];
int le,ri,len,val;

void up(int idx,int node,int o) {
	for(int i=1;i<=10;i++){
		if(o!=-1)tr[o][node][i][arr[i]]=0;
		tr[idx][node][i][arr[i]]++;
	}
	node>>=1;
	while(node) {
		int nx=node<<1;
		for(int i=1;i<=10;i++) {
			tr[idx][node][i][arr[i]]=tr[idx][nx][i][arr[i]]+tr[idx][nx+1][i][arr[i]];
			if(o!=-1) tr[o][node][i][arr[i]]=tr[o][nx][i][arr[i]]+tr[o][nx+1][i][arr[i]];
		}
		node>>=1;
	}
}
int sum(int idx,int node,int st,int fi) {
	if(fi<le||st>ri) return 0;
	else if(le<=st&&fi<=ri) return tr[idx][node][len][val];
	else {
		int nx=node<<1,md=(st+fi)>>1;
		return sum(idx,nx,st,md)+sum(idx,nx+1,md+1,fi); 
	}
}
int get(char ch) {
	if(ch=='A') return 0;
	else if(ch=='C') return 1;
	else if(ch=='T') return 2;
	else if(ch=='G') return 3;
	else return -1;
}
int main() {
	int t,l,r,c,q;
	char tmp[11];
	scanf("%s",str);
	n=strlen(str);
	for(int i=0;i<n;i++) {
		for(int j=1;j<=10;j++) arr[j]=i%j;
		up(get(str[i]),i+MAX,-1);
	}
	
	scanf("%d",&q);
	while(q--) {
		scanf("%d",&t);
		if(t==1) {
			scanf("%d %c",&c,&tmp[0]);
			c--;
			if(str[c]==tmp[0])continue;
			for(int i=1;i<=10;i++) arr[i]=c%i;
			up(get(tmp[0]),c+MAX,get(str[c]));
			str[c]=tmp[0];
		}
		else {
			scanf("%d %d %s",&l,&r,tmp);
			len=strlen(tmp);
			l--;r--;
			le=l;
			ri=r;
			int s=0;
			for(int i=l;i<l+len&&i<=r;i++) {
				val=i%len;
				s+=sum(get(tmp[(i-l)%len]),1,0,MAX-1);
			}
			printf("%d\n",s);
		}
	}
	return 0;
}