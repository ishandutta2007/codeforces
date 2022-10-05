#include<bits/stdc++.h>
using namespace std;
int n,p,m,k;
int a[190000];
int lazy[610000]={};
int o[610000]={};
int xx[610000][7];
int num[610000][7];
void pushup(int p){
	int aa[20];
	int bb[20];
	int nn[20]={};
	for(int i=1;i<=o[2*p];i++) aa[i]=xx[2*p][i];
	for(int j=1;j<=o[2*p+1];j++) aa[j+o[2*p]]=xx[2*p+1][j];
	sort(aa+1,aa+o[2*p]+o[2*p+1]+1);
	int tot=0;
	bb[++tot]=aa[1];
	for(int i=2;i<=o[2*p]+o[2*p+1];i++) if(aa[i]!=aa[i-1]) bb[++tot]=aa[i];
	for(int i=1;i<=o[2*p];i++){
		int l=1,r=tot;
		for(;l<r;){
			if(xx[2*p][i]<=bb[(l+r)/2]) r=(l+r)/2;
			else l=(l+r)/2+1;
		}
		nn[l]+=num[2*p][i];
	}
	for(int i=1;i<=o[2*p+1];i++){
		int l=1,r=tot;
		for(;l<r;){
			if(xx[2*p+1][i]<=bb[(l+r)/2]) r=(l+r)/2;
			else l=(l+r)/2+1;
		}
		nn[l]+=num[2*p+1][i];
	}
	if(tot<=k){
		o[p]=tot;
		for(int i=1;i<=tot;i++) {
			xx[p][i]=bb[i];
			num[p][i]=nn[i];
		}
		return;
	}
	pair<int,int> tt[20];
	for(int i=1;i<=tot;i++) tt[i]=make_pair(nn[i],bb[i]);
	sort(tt+1,tt+tot+1);
	for(int i=1;i<=tot-k;i++){
		for(int j=i+1;j<=i+k;j++) tt[j].first-=tt[i].first;
	}
	o[p]=0;
	for(int i=tot-k+1;i<=tot;i++){
		if(tt[i].first){
			xx[p][++o[p]]=tt[i].second;
			num[p][o[p]]=tt[i].first;
		}
	}
}
void pushdown(int l,int r,int p){
	if(lazy[p]){
		int mid=(l+r)/2;
		lazy[2*p]=lazy[p];
		lazy[2*p+1]=lazy[p];
		o[2*p]=1;
		xx[2*p][1]=lazy[p];
		num[2*p][1]=mid-l+1;
		o[2*p+1]=1;
		xx[2*p+1][1]=lazy[p];
		num[2*p+1][1]=r-mid;
		lazy[p]=0;
	}
}
void update(int x,int y,int id,int l,int r,int p){
	if((x<=l)&&(y>=r)){
		lazy[p]=id;
		o[p]=1;
		xx[p][1]=id;
		num[p][1]=r-l+1;
		return;
	}
	pushdown(l,r,p);
	int mid=(l+r)/2;
	if(x<=mid) update(x,y,id,l,mid,2*p);
	if(y>=mid+1) update(x,y,id,mid+1,r,2*p+1);
	pushup(p);
}
int ss;
int oo[20];
int uu[20];
void query(int x,int y,int l,int r,int p){
	if((x<=l)&&(y>=r)){
		int aa[20];
	    int bb[20];
	    int nn[20]={};
	    for(int i=1;i<=o[p];i++) aa[i]=xx[p][i];
	    for(int j=1;j<=ss;j++) aa[j+o[p]]=uu[j];
	    sort(aa+1,aa+o[p]+ss+1);
	    int tot=0;
	    bb[++tot]=aa[1];
	    for(int i=2;i<=o[p]+ss;i++) if(aa[i]!=aa[i-1]) bb[++tot]=aa[i];
	    for(int i=1;i<=o[p];i++){
		    int l=1,r=tot;
		    for(;l<r;){
			    if(xx[p][i]<=bb[(l+r)/2]) r=(l+r)/2;
			    else l=(l+r)/2+1;
		    }
		    nn[l]+=num[p][i];
	    }
	    for(int i=1;i<=ss;i++){
		    int l=1,r=tot;
		    for(;l<r;){
			    if(uu[i]<=bb[(l+r)/2]) r=(l+r)/2;
			    else l=(l+r)/2+1;
		    }
		    nn[l]+=oo[i];
	    }
	    if(tot<=k){
		    ss=tot;
		    for(int i=1;i<=tot;i++) {
			    uu[i]=bb[i];
			    oo[i]=nn[i];
		    }
		    return;
	    }
	    pair<int,int> tt[20];
	    for(int i=1;i<=tot;i++) tt[i]=make_pair(nn[i],bb[i]);
	    sort(tt+1,tt+tot+1);
	    for(int i=1;i<=tot-k;i++){
		    for(int j=i+1;j<=i+k;j++) tt[j].first-=tt[i].first;
	    }
	    ss=0;
	    for(int i=tot-k+1;i<=tot;i++) {
		    if(tt[i].first){
			    uu[++ss]=tt[i].second;
			    oo[ss]=tt[i].first;
		    }
	    }
		return;
	}
	pushdown(l,r,p);
	int mid=(l+r)/2;
	if(x<=mid) query(x,y,l,mid,2*p);
	if(y>=mid+1) query(x,y,mid+1,r,2*p+1);
}
int main(){
	scanf("%d%d%d",&n,&m,&p);
	k=100/p;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) update(i,i,a[i],1,n,1);
	for(int i=1;i<=m;i++){
		int op,l,r;
		scanf("%d%d%d",&op,&l,&r);
		if(op==1){
			int id;
			scanf("%d",&id);
			update(l,r,id,1,n,1);
		}
		else{
			ss=0;
			query(l,r,1,n,1);
			printf("%d ",ss);
			for(int i=1;i<=ss;i++) printf("%d ",uu[i]);
			printf("\n");
		}
	}
	return 0;
}